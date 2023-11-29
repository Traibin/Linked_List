#include<iostream>
#include<string>
using namespace std;
template<class T>
class SqList
{
public:
	int capacity;//˳������ܳ�����������
	int length;//�������Ѵ�ŵĳ���
	T* data;//���˳���Ԫ�ؿռ��ָ��
	SqList();//���캯��
	SqList(const SqList<T>& s);//��ʼ���������캯��
	~SqList();//��������
	void recap(int newcap);//�ı�˳���������ĺ���
	void CreateList(T a[], int n);//������a�����ݴ���һ��˳���
	void Add(T e);//���һ��eԪ����˳���ĩβ
	int GetLength();//���˳�����
	bool GetElem(int i, T& e);//��ȡ���Ϊi��Ԫ��ֵ
	bool SetElem(int i, T e);//�޸����i��Ԫ��ֵ
	int GetNo(T e);//���ҵ�һ��ֵΪe��Ԫ�ص����
	bool Insert(int i, T e);//��˳������ڵ�i��λ�ò���Ԫ��ֵΪe
	bool Delete(int i);//��˳�����ɾ�����Ϊi��Ԫ��
	void DispList();//�����������Ԫ��
	void Reverse(SqList<T>& L);//����Ԫ��
	bool Deletek(SqList<T>& L, int i, int k);//ɾ��i��Ԫ�ؿ�ʼ��k��Ԫ��
	void Deletex(SqList<T>& L, T x);//ɾ���б��д�xԪ��
	void Merge(SqList<T>a, SqList<T>b, SqList<T>&c);//��������ķ�ʽ��������a��b�ϲ�Ϊc
};
//���ⶨ�庯��
template<typename T>
SqList<T>::SqList()
{
	//����new�����Ķ�̬����
	/*data = new T[...]�����...�������ȥһ���������ֵ������ʼ��data��*/
	/*�������ʹ�����־������ֵ��1��2��3�����ǾͿ��Ը����캯��һ�����ʼ����ֵ*/
	/*SqList<T>::SqList(int a)
	{
		int initial = 5;
		initial = a;
		data = new T[initial];
		�������Ե��ù��캯��������a(�붨�������)���������initial��
		��Ȼ�����������е���࣬���ǿ��Ա�������ȫ�ֳ���ռ�ݿռ䣬�����Լ�����ֵ������������������
		���ǰ���ȫ�ֳ����������ܵõ��ø��������ĺ�����ʹ��
	}*/
	int initial = 5;
	data = new T[initial];//ʹ��new��data��̬��ֵ
	capacity = initial;//��ʼ��������֮����ø��������������и���
	length = 0;//��ʼ������Ϊ0
}
template<typename T>
SqList<T>::SqList(const SqList<T>& S)//�������
{
	capacity = S.capacity;//��������
	length = S.length;//���³���
	data = new T[capacity];//����һ����ָ�����S��ָ������
	for (int i = 0; i < length; i++)//���ܲ���
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
void SqList<T>::recap(int newcap)//�ı�����Ϊnewcap
{
	if (newcap <= 0)//���ж�����������ϲ��ϸ�
	{
		return;
	}
	T* olddata = data;//����һ����ʱ��olddataָ�룬ԭ����data�����������ʱȫ����olddataָ��
	data = new T[newcap];//��������Ϊnewcap������
	capacity = newcap;//���������и���
	for (int i = 0; i < length; i++)//ʹ��forѭ������olddata�����ݻ���data��
	{
		//ע�⣺length��Ϊȫ�ֱ�����Ԫ�صļ���Ҫ��ʱ����
		data[i] = olddata[i];
	}
	delete[] olddata;//�ͷſռ�
}
template<typename T>
void SqList<T>::CreateList(T a[], int n)//aΪ���飬nΪ����ĳ���
{
 // for (int i = 0; i < n; i++)//ʹ��forѭ������˳�����и�ֵ����
	//{
	//	if (capacity <= length)//�ж�capacity�������Ƿ��㹻
	//	{
	//		recap(2 * length);//���������������
	//	}
	//	data[i] = a[i];
	//	length++;//���³���
	//}
	//�ҵ�����
	if(n >= 0)//�ж�ѭ������
	{
		cout << "--------------����˳���-----------------------" << endl;
		length += n;//���³���
		if (capacity <= length)//�ж�capacity�������Ƿ��㹻
		{
			recap(2 * length);
		}
		for (int i = 0; i < n; i++)//forѭ����data��ֵ
		{
			data[i] = a[i];
		}
	}
}
template<typename T>
void SqList<T>::Add(T e)//β�巨˳���
{
	if (length >= capacity)
	{
		recap(2 * length);
	}
	data[length] = e;//������˳������һ��λ�ý��ϣ�֮ǰ�ĳ���Ϊlength-1
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
		cout << "�޷�����" << endl;
		return false;
	}
	cout << "--------------��ȡ˳�����-----------------------" << endl;
	e = data[i];
	cout << "���Ϊ��" << i << "��Ԫ��Ϊ��" << e << endl;
	return true;
}
template<typename T>
bool SqList<T>::SetElem(int i, T e)
{
	if (i < 0 || i >= length)
	{
		cout << "�޷�����" << endl;
		return false;
	}
	cout << "--------------�޸�˳���-----------------------" << endl;
	data[i] = e;
	cout << "�������Ϊ" << i << "Ԫ��Ϊ" << e << "�ɹ�" << endl;
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
		cout << "������Χ" << endl;
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
		cout << "�޷�����" << endl;
		return false;
	}
	if (length == capacity)
	{
		recap(2 * length);
	}
	cout << "--------------����Ԫ��-----------------------" << endl;
	for (int j = length; j > i; j--)
	{
		data[j] = data[j - 1];
	}
	data[i] = e;
	length++;//���������ؼ����ڿ���һ��λ�ã������ƣ�ͬ��ɵã�������Ҫһ����λ�û�����ʱ�Ŀռ�������ڶ���Ҫ�޸ĵ�����
	//�ҵ��뷨
	//for (int j = i; j <= length; j++)
	//{
	//	T temp;
	//	temp = data[j + 1];
	//	data[j+1] = data[j];
	//	data[j + 2] = temp;
	//}//����������������ӣ���δ�޸�ȫ���ĳ�ǰһ����
	return true;
}
template<typename T>
bool SqList<T>::Delete(int i)
{
	if (i < 0 || i >= length)
	{
		cout << "�޷�����" << endl;
		return false;
	}
	cout << "--------------ɾ��˳���-----------------------" << endl;
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
	cout << "��ǰ����Ϊ��" << capacity << "��ǰ����Ϊ��" << length << endl;
	cout << endl;
}
template<typename T>
void SqList<T>::Reverse(SqList<T>& L)
{
	cout << "--------------˳�����Ԫ��-----------------------" << endl;
	//�Ҳ�ȡ�м�ֵ�����м���
	/*�м�ֵָ���Ǹ�������м��±꣬�����������һ��Ϊ������һ��Ϊż��
	�㷨Ϊ���������������м������߽��н�������*/
	if (L.length % 2 == 1)
	{
		int a = L.length / 2;
		int i, j;
		for (i = j = a; i >= 0 && j <= length - 1; i--, j++)
		{
			//iΪ�м������
			//jΪ�м����ұ�
			T temp;//��ʱ�洢���������
			temp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = temp;
		}
	}
	else
	{
		//������ͬ��ɵ�
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
	cout << "--------------ɾ����" <<i<<"��Ԫ�ؿ�ʼ"<<k<<"��Ԫ��-----------------------" << endl;
	if (i < 0 || k<0 || i + k <= 0 || i + k>L.length)
	{
		return false;
	}
	for (int d = i + k; d <L.length; d++)//ע�⣺��Ҫ���ǵ�ɾ�����������Ԫ�أ�����Ҳ����Ҫ��ǰ�ƶ�
	{
		L.data[d - k] = L.data[d];
	}
	L.length -= k;
	return true;
}
template<typename T>
void SqList<T>::Deletex(SqList<T>& L, T x)
{
	cout << "--------------ɾ��ȫ����"<<x<<"��Ԫ��---------------------- - " << endl;
	//�ⷨ1�����彨��    �����������Ƕ�L����������¸�ֵ
	//int k = 0;//��k����¼�������±�
	//for (int i = 0; i < L.length; i++)//��������ѭ��
	//{
	//	if (L.data[i] != x)//������Ǿͱ���
	//	{
	//		L.data[k] = L.data[i];
	//		k++;//����L������±�
	//	}
	//}
	//L.length = k;
	//�ⷨ2��Ԫ���ƶ���
	//int k = 0;
	//for (int i = 0; i < L.length; i++)
	//{
	//	if (L.data[i] != x)
	//	{
	//		L.data[i - k] = L.data[i];//���и��ǲ���
	//	}
	//	else
	//	{
	//		k++;//��¼x�ĸ���
	//	}
	//}
	//L.length -= k;
	//�ⷨ3�����仮�ַ�
	int i = -1;
	int j = 0;
	while (j < L.length)
	{
		if (L.data[j] != x)
		{
			i++;
			if (i != j)
			{
				swap(L.data[i], L.data[j]);//����λ�ã����Ѽ�¼i��xԪ�ط������Ȼ��ɾ��
			}
		}
		j++;
	}
	L.length = i + 1;
}
template<typename T>
void SqList<T>::Merge(SqList<T>a, SqList<T>b, SqList<T>&c)
{
	//�ȶ�����a��bԪ����������
	//�ܹ���������Ϊ Ԫ�ظ���-1
	for (int i = 0; i < a.length - 1; i++)
	{
		//�ڲ�ѭ���Ա�
		//�Աȴ���=Ԫ�ظ���-��������-1
		for (int j = 0; j < a.length - i - 1; j++)
		{
			//�����һ�����ֱȵڶ����󣬽�����������
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
		//�ڲ�ѭ���Ա�
		//�Աȴ���=Ԫ�ظ���-��������-1
		for (int j = 0; j < b.length - i - 1; j++)
		{
			//�����һ�����ֱȵڶ����󣬽�����������
			if (b.data[j] > b.data[j + 1])
			{
				int temp = b.data[j];
				b.data[j] = b.data[j + 1];
				b.data[j + 1] = temp;
			}
		}
	}
	int i = 0, j = 0;
	while (i < a.length && j < b.length)//��ʼ��������������
	{
		if (a.data[i] < b.data[j])//b����a�����a����c
		{
			c.Add(a.data[i]);
			i++;
		}
		else//bС�ڵ���a�����b����c
		{
			c.Add(b.data[j]);
			j++;
		}
	}
	while(i<a.length)//̽��a�Ƿ���ʣ��
	{
		c.Add(a.data[i]);
		i++;
	}
	while(j < b.length)//̽��b�Ƿ���ʣ��
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