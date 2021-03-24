#pragma once
using namespace std;
#include<iostream>

struct product
{
	string name = "";
	double cost = 0;
};

class List
{

public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(product data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	product& operator[](const int index);

	//добавление элемента в начало списка
	void push_front(product data);

	//добавление элемента в список по указанному индексу
	void insert(product data, int index);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	//удаление последнего элемента в списке
	void pop_back();

private:



	class Node
	{
	public:
		Node* pNext;
		product data;

		Node(product data = product(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node* head;
};






