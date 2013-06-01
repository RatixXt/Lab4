/**
\file Tree.cpp 

@author Щербаков Алексей ИУ8-23
@brief Реализация бинарного дерева с помощью массива.

*/

#include <iostream>
#include <cmath>
using namespace std;

///Узел дерева
class node
{
public:
	float val;	///Значение элемента
	int son1;	///Индекс левого сына
	int son2;	///Индекс правого сына
};

///Дерево
class Tree
{
private:
	node arr[50];	///Массив с узлами делева
	int size;	///Кол-во узлов дерева
public:
	Tree() ///Конструктор
	{
		for(int i=0;i<50;i++)
		{
			arr[i].val=0;
			arr[i].son1=-1;	/// значение "-1" - отсутствие сына
			arr[i].son2=-1;
		}
		size=0;
	}
	int getsize();	///@function Получение кол-ва узлов дерева
	void push(float a);	/// @function Добавление нового узла
	void pop();	/// @function Удаление узла
	void get(int k);	/// @function Вывод информации об узле k
	};

	int Tree::getsize() 
	{
	return size;
	}

	void Tree::push(float a)
	{
		arr[size].val=a;	///Добавление узла
		int id=size;
		size++;	
		///Связывание узла с узлом-родителем
		if ((id!=0)&&((id-1)%2==0))
		arr[(id-1)/2].son1=id; else arr[(id-1)/2].son2=id;
	}

	void Tree::pop()
	{
		size--;	
		arr[size].val=0;	///Удаление узла
		///Удаление связи узла с родителем
		if ((size!=0)&&((size-1)%2==1)) arr[(size-1)/2].son2=-1; else arr[(size-1)/2].son1=-1;
	}

	void Tree::get(int k)
	{
	cout<<arr[k].val<<"["<<k<<"]"<<endl;	///Вывод значения узла и его индекса в формате value[index]
	cout<<"left son: ";	///Вывод информации о левом сыне
	if (arr[k].son1==-1) cout<<"no\n"; else cout<<arr[arr[k].son1].val<<"["<<arr[k].son1<<"]"<<endl;
	cout<<"right son: ";	///Вывод информации о правом сыне
	if (arr[k].son2==-1) cout<<"no\n"; else cout<<arr[arr[k].son2].val<<"["<<arr[k].son2<<"]"<<endl;
	}

	void main()
	{
	Tree TR;
	int choice=0;
	int k=0;
	float val=0;
	bool Flag=true;
	cout<<"Press button : 1 - add node; 2 - delete node; 3 - show node and its sons; 4 - exit.\n\n"; ///Подсказка о возможных действиях
	while(Flag)
	{
		cout<<"Choose action: ";
		cin>>choice;	///Переменная, в которую заносится выбор пользователя
		switch(choice)
		{
		case 1: ///Добавление нового узла
		{
		if (TR.getsize()==63) cout<<"There's no memory to add more nodes"<<endl; ///Вывод сообщения, если дерево заполнено
		else
			{
				cout<<"Enter a value\n";
				cin>>val;	///Ввод значения узла
				TR.push(val);	///Добавление узла к дереву
			}
		cout<<endl;
		break;
		}
		case 2: ///Удаление узла
		{
			if(TR.getsize()==0) cout<<"You can't delete elements: tree is empty\n"; ///Сообщение, если дерево пусто
			else TR.pop();	///Удаление элемента
			cout<<endl;
			break;
		}
		case 3: ///Вывод на экран информации по k узлу
		{
			if (TR.getsize()==0) cout<<"Tree is empty\n"; ///Сообщение, если дерево пусто
			else
		{
			cout<<"Enter index\n";
			cin>>k;	///Ввод индекса
			if ((k<0)||(k>TR.getsize()-1)) cout<<"Incorrect index\n"; ///Проверка корректности индекса
			else TR.get(k);	///Вывод информации по узлу
		}
		cout<<endl;
		break;
		}
		case 4: Flag=false; break;	///Выход
		default: cout<<"Incorrect value.\n";///Сообщение, если введено некорректное значение на этапе выбора действия
		}
	}
}