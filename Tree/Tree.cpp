/**
\file Tree.cpp 

@author Щербаков Алексей ИУ8-23
@brief Реализация алгоритма Дейкстры

*/

#include <iostream>
#include <cmath>
using namespace std;

///���� ������
class node
{
public:
	float val;	///�������� ��������
	int son1;	///������ ������ ����
	int son2;	///������ ������� ����
};

///������
class Tree
{
private:
	node arr[50];	///������ � ������ ������
	int size;	///���-�� ����� ������
public:
	Tree() ///�����������
	{
		for(int i=0;i<50;i++)
		{
			arr[i].val=0;
			arr[i].son1=-1;	/// �������� "-1" - ���������� ����
			arr[i].son2=-1;
		}
		size=0;
	}
	int getsize();	///@function ��������� ���-�� ����� ������
	void push(float a);	/// @function ���������� ������ ����
	void pop();	/// @function �������� ����
	void get(int k);	/// @function ����� ���������� �� ���� k
	};

	int Tree::getsize() 
	{
	return size;
	}

	void Tree::push(float a)
	{
		arr[size].val=a;	///���������� ����
		int id=size;
		size++;	
		///���������� ���� � �����-���������
		if ((id!=0)&&((id-1)%2==0))
		arr[(id-1)/2].son1=id; else arr[(id-1)/2].son2=id;
	}

	void Tree::pop()
	{
		size--;	
		arr[size].val=0;	///�������� ����
		///�������� ����� ���� � ���������
		if ((size!=0)&&((size-1)%2==1)) arr[(size-1)/2].son2=-1; else arr[(size-1)/2].son1=-1;
	}

	void Tree::get(int k)
	{
	cout<<arr[k].val<<"["<<k<<"]"<<endl;	///����� �������� ���� � ��� ������� � ������� value[index]
	cout<<"left son: ";	///����� ���������� � ����� ����
	if (arr[k].son1==-1) cout<<"no\n"; else cout<<arr[arr[k].son1].val<<"["<<arr[k].son1<<"]"<<endl;
	cout<<"right son: ";	///����� ���������� � ������ ����
	if (arr[k].son2==-1) cout<<"no\n"; else cout<<arr[arr[k].son2].val<<"["<<arr[k].son2<<"]"<<endl;
	}

	void main()
	{
	Tree TR;
	int choice=0;
	int k=0;
	float val=0;
	bool Flag=true;
	cout<<"Press button : 1 - add node; 2 - delete node; 3 - show node and its sons; 4 - exit.\n\n"; ///��������� � ��������� ���������
	while(Flag)
	{
		cout<<"Choose action: ";
		cin>>choice;	///����������, � ������� ��������� ����� ������������
		switch(choice)
		{
		case 1: ///���������� ������ ����
		{
		if (TR.getsize()==63) cout<<"There's no memory to add more nodes"<<endl; ///����� ���������, ���� ������ ���������
		else
			{
				cout<<"Enter a value\n";
				cin>>val;	///���� �������� ����
				TR.push(val);	///���������� ���� � ������
			}
		cout<<endl;
		break;
		}
		case 2: ///�������� ����
		{
			if(TR.getsize()==0) cout<<"You can't delete elements: tree is empty\n"; ///���������, ���� ������ �����
			else TR.pop();	///�������� ��������
			cout<<endl;
			break;
		}
		case 3: ///����� �� ����� ���������� �� k ����
		{
			if (TR.getsize()==0) cout<<"Tree is empty\n"; ///���������, ���� ������ �����
			else
		{
			cout<<"Enter index\n";
			cin>>k;	///���� �������
			if ((k<0)||(k>TR.getsize()-1)) cout<<"Incorrect index\n"; ///�������� ������������ �������
			else TR.get(k);	///����� ���������� �� ����
		}
		cout<<endl;
		break;
		}
		case 4: Flag=false; break;	///�����
		default: cout<<"Incorrect value.\n";///���������, ���� ������� ������������ �������� �� ����� ������ ��������
		}
	}
}
