#include<iostream>
#include<string>
using namespace std;
template<class T>
class SqList
{
public:
	int capacity;//顺序表所能承受最大的容量
	int length;//数组现已存放的长度
	T* data;//存放顺序表元素空间的指针
	SqList();//构造函数
	SqList(const SqList<T>& s);//初始化拷贝构造函数
	~SqList();//析构函数
	void recap(int newcap);//改变顺序表的容量的函数
	void CreateList(T a[], int n);//把数组a的数据创建一个顺序表
	void Add(T e);//添加一个e元素在顺序表末尾
	int GetLength();//获得顺序表长度
	bool GetElem(int i, T& e);//获取序号为i的元素值
	bool SetElem(int i, T e);//修改序号i的元素值
	int GetNo(T e);//查找第一个值为e的元素的序号
	bool Insert(int i, T e);//在顺序表中在第i个位置插入元素值为e
	bool Delete(int i);//在顺序表中删除序号为i的元素
	void DispList();//输出数组所有元素
	void Reverse(SqList<T>& L);//逆置元素
	bool Deletek(SqList<T>& L, int i, int k);//删除i号元素开始的k个元素
	void Deletex(SqList<T>& L, T x);//删除列表中带x元素
	void Merge(SqList<T>a, SqList<T>b, SqList<T>&c);//按照升序的方式，把链表a，b合并为c
};
//类外定义函数
template<typename T>
SqList<T>::SqList()
{
	//关于new创建的动态数组
	/*data = new T[...]这里的...必须填进去一个具体的数值，来初始化data。*/
	/*如果不想使用这种具体的数值（1，2，3），那就可以给构造函数一个想初始化的值*/
	/*SqList<T>::SqList(int a)
	{
		int initial = 5;
		initial = a;
		data = new T[initial];
		这样可以调用构造函数，传入a(想定义的容量)来更新这个initial。
		虽然这样看起来有点多余，但是可以避免设置全局常量占据空间，可以自己设置值来构造这个最初容量，
		若是按照全局常量来，可能得调用更新容量的函数来使用
	}*/
	int initial = 5;
	data = new T[initial];//使用new对data动态赋值
	capacity = initial;//初始化容量，之后调用更新容量函数进行更改
	length = 0;//初始化长度为0
}
template<typename T>
SqList<T>::SqList(const SqList<T>& S)//深拷贝函数
{
	capacity = S.capacity;//更新容量
	length = S.length;//更新长度
	data = new T[capacity];//创建一个新指针接受S的指针数组
	for (int i = 0; i < length; i++)//接受操作
	{
		data[i] = S.data[i];
	}
}
template<typename T>
SqList<T>::~SqList()
{
	delete[] data;
}
template<typename T>
void SqList<T>::recap(int newcap)//改变容量为newcap
{
	if (newcap <= 0)//先判断这个容量数合不合格
	{
		return;
	}
	T* olddata = data;//创建一个暂时的olddata指针，原来的data数组的数据暂时全部给olddata指针
	data = new T[newcap];//更新容量为newcap的数组
	capacity = newcap;//对容量进行更新
	for (int i = 0; i < length; i++)//使用for循环，把olddata的数据还给data，
	{
		//注意：length作为全局变量有元素的加入要及时更新
		data[i] = olddata[i];
	}
	delete[] olddata;//释放空间
}
template<typename T>
void SqList<T>::CreateList(T a[], int n)//a为数组，n为数组的长度
{
 // for (int i = 0; i < n; i++)//使用for循环，对顺序表进行赋值操作
	//{
	//	if (capacity <= length)//判断capacity的容量是否足够
	//	{
	//		recap(2 * length);//若不够做扩大操作
	//	}
	//	data[i] = a[i];
	//	length++;//更新长度
	//}
	//我的做法
	if(n >= 0)//判断循环条件
	{
		cout << "--------------创建顺序表-----------------------" << endl;
		length += n;//更新长度
		if (capacity <= length)//判断capacity的容量是否足够
		{
			recap(2 * length);
		}
		for (int i = 0; i < n; i++)//for循环对data赋值
		{
			data[i] = a[i];
		}
	}
}
template<typename T>
void SqList<T>::Add(T e)//尾插法顺序表
{
	if (length >= capacity)
	{
		recap(2 * length);
	}
	data[length] = e;//正好在顺序表最后一个位置接上，之前的长度为length-1
	length++;
}
template<typename T>
int SqList<T>::GetLength()
{
	return length;
}
template<typename T>
bool SqList<T>::GetElem(int i, T& e)
{
	if (i <= 0 || i >= length)
	{
		cout << "无法操作" << endl;
		return false;
	}
	cout << "--------------获取顺序表长度-----------------------" << endl;
	e = data[i];
	cout << "序号为：" << i << "的元素为：" << e << endl;
	return true;
}
template<typename T>
bool SqList<T>::SetElem(int i, T e)
{
	if (i < 0 || i >= length)
	{
		cout << "无法运行" << endl;
		return false;
	}
	cout << "--------------修改顺序表-----------------------" << endl;
	data[i] = e;
	cout << "设置序号为" << i << "元素为" << e << "成功" << endl;
	return true;
}
template<typename T>
int SqList<T>::GetNo(T e)
{
	int i = 0;
	while (i < length && data[i] != e)
	{
		i++;
	}
	if (i >= length)
	{
		cout << "超出范围" << endl;
		return -1;
	}
	else
	{
		return i;
	}
}
template<typename T>
bool SqList<T>::Insert(int i, T e)
{
	if (i < 0 || i >= length)
	{
		cout << "无法运行" << endl;
		return false;
	}
	if (length == capacity)
	{
		recap(2 * length);
	}
	cout << "--------------插入元素-----------------------" << endl;
	for (int j = length; j > i; j--)
	{
		data[j] = data[j - 1];
	}
	data[i] = e;
	length++;//这种做法关键在于空了一个位置，可以移，同理可得，我们需要一个空位置或者暂时的空间来储存第二次要修改的数据
	//我的想法
	//for (int j = i; j <= length; j++)
	//{
	//	T temp;
	//	temp = data[j + 1];
	//	data[j+1] = data[j];
	//	data[j + 2] = temp;
	//}//这种做法会产生叠加，把未修改全部改成前一个的
	return true;
}
template<typename T>
bool SqList<T>::Delete(int i)
{
	if (i < 0 || i >= length)
	{
		cout << "无法运行" << endl;
		return false;
	}
	cout << "--------------删除顺序表-----------------------" << endl;
	for (int j = i; j <= length-1; j++)
	{
		data[j] = data[j+1];
	}
	length--;
	return true;
}
template<typename T>
void SqList<T>::DispList()
{

	for (int i = 0; i <= length - 1; i++)
	{
		cout << data[i] << "  ";
	}
	cout << "当前容量为：" << capacity << "当前长度为：" << length << endl;
	cout << endl;
}
template<typename T>
void SqList<T>::Reverse(SqList<T>& L)
{
	cout << "--------------顺序表互换元素-----------------------" << endl;
	//我采取中间值来进行计算
	/*中间值指的是该数组的中间下标，分两种情况，一种为奇数，一种为偶数
	算法为定义两个数，在中间数两边进行交换操作*/
	if (L.length % 2 == 1)
	{
		int a = L.length / 2;
		int i, j;
		for (i = j = a; i >= 0 && j <= length - 1; i--, j++)
		{
			//i为中间数左边
			//j为中间数右边
			T temp;//暂时存储被替代的数
			temp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = temp;
		}
	}
	else
	{
		//由上述同理可得
		int a = L.length / 2;
		int i, j;
		i = a-1;
		j = a;
		for (; i >= 0 && j <= length - 1; i--, j++)
		{
			T temp;
			temp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = temp;
		}
	}
}
template<typename T>
bool SqList<T>::Deletek(SqList<T>& L, int i, int k)
{
	cout << "--------------删除自" <<i<<"号元素开始"<<k<<"个元素-----------------------" << endl;
	if (i < 0 || k<0 || i + k <= 0 || i + k>L.length)
	{
		return false;
	}
	for (int d = i + k; d <L.length; d++)//注意：需要考虑到删除个数后面的元素，他们也是需要向前移动
	{
		L.data[d - k] = L.data[d];
	}
	L.length -= k;
	return true;
}
template<typename T>
void SqList<T>::Deletex(SqList<T>& L, T x)
{
	cout << "--------------删除全部带"<<x<<"的元素---------------------- - " << endl;
	//解法1：整体建表法    总体来看就是对L链表进行重新赋值
	//int k = 0;//用k来记录新链表下标
	//for (int i = 0; i < L.length; i++)//进行链表循环
	//{
	//	if (L.data[i] != x)//如果不是就保留
	//	{
	//		L.data[k] = L.data[i];
	//		k++;//更新L链表的下标
	//	}
	//}
	//L.length = k;
	//解法2：元素移动法
	//int k = 0;
	//for (int i = 0; i < L.length; i++)
	//{
	//	if (L.data[i] != x)
	//	{
	//		L.data[i - k] = L.data[i];//进行覆盖操作
	//	}
	//	else
	//	{
	//		k++;//记录x的个数
	//	}
	//}
	//L.length -= k;
	//解法3：区间划分法
	int i = -1;
	int j = 0;
	while (j < L.length)
	{
		if (L.data[j] != x)
		{
			i++;
			if (i != j)
			{
				swap(L.data[i], L.data[j]);//交换位置，最后把记录i个x元素放在最后然后删除
			}
		}
		j++;
	}
	L.length = i + 1;
}
template<typename T>
void SqList<T>::Merge(SqList<T>a, SqList<T>b, SqList<T>&c)
{
	//先对链表a，b元素升序排序
	//总共排序轮数为 元素个数-1
	for (int i = 0; i < a.length - 1; i++)
	{
		//内层循环对比
		//对比次数=元素个数-排序轮数-1
		for (int j = 0; j < a.length - i - 1; j++)
		{
			//如果第一个数字比第二个大，交换两个数字
			if (a.data[j] > a.data[j + 1])
			{
				int temp = a.data[j];
				a.data[j] = a.data[j + 1];
				a.data[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < b.length - 1; i++)
	{
		//内层循环对比
		//对比次数=元素个数-排序轮数-1
		for (int j = 0; j < b.length - i - 1; j++)
		{
			//如果第一个数字比第二个大，交换两个数字
			if (b.data[j] > b.data[j + 1])
			{
				int temp = b.data[j];
				b.data[j] = b.data[j + 1];
				b.data[j + 1] = temp;
			}
		}
	}
	int i = 0, j = 0;
	while (i < a.length && j < b.length)//开始操作，遍历条件
	{
		if (a.data[i] < b.data[j])//b大于a，则把a赋给c
		{
			c.Add(a.data[i]);
			i++;
		}
		else//b小于等于a，则把b赋给c
		{
			c.Add(b.data[j]);
			j++;
		}
	}
	while(i<a.length)//探测a是否有剩余
	{
		c.Add(a.data[i]);
		i++;
	}
	while(j < b.length)//探测b是否有剩余
	{
		c.Add(b.data[j]);
		j++;
	}
}
int main()
{
	SqList<int> s1;
	int a[5] = { 0,1,2,3,4 };
	s1.CreateList(a, 5);
	s1.DispList();
	int e;
	s1.GetElem(4,e);
	s1.DispList();
	s1.Insert(3, 9);
	s1.DispList();
	s1.SetElem(0, 99);
	s1.DispList();
	s1.Delete(3);
	s1.DispList();
	SqList<int> s2;
	int b[5] = { 1,2,3,4,5};
	s2.CreateList(b, 5);
	s2.Reverse(s2);
	s2.DispList();
	s2.Deletek(s2, 0, 2);
	s2.DispList();
	int d[5] = { 1,2,1,5,1 };
	SqList<int> s3;
	s3.CreateList(d, 5);
	s3.Deletex(s3, 1);
	s3.DispList();
	int n[5] = { 5,2,4,1,6 };
	int m[6] = { 6,3,2,7,9,1 };
	SqList<int>s4;
	SqList<int>s5;
	s4.CreateList(n, 5);
	s5.CreateList(m, 6);
	SqList<int>s6;
	s6.Merge(s4, s5, s6);
	s6.DispList();
	system("pause");
	return 0;
}