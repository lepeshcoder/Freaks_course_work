#include <iostream>
#include "list.h"
#include <iomanip>
using namespace std;




class e_shop 
{
private:
	product assortiment[10] = { {"хер",5.23},{"zalupa",2.71},{"kal",6.23},{"borow",10.00},{"davalka",4.1345},{"xyi",228.761},{"pizda",1337},{"myaso",14},{"massa",15},{"kal1",17} };
	List korzina;
public:
	~e_shop()
	{
		korzina.clear();
	}
	void push_product_to_korzina(string name, double cost)
	{
		product* temp = new product;
		temp->cost = cost;
		temp->name = name;
		korzina.push_back(*temp);
		delete temp;
	}
	void show_korzina()
	{
		double sum = 0;
		for (int i = 0; i < korzina.GetSize(); i++)
		{
			cout << i + 1 << "продукт:" << endl;
			cout << korzina[i].name << "  цена: " << fixed << setprecision(3) << korzina[i].cost << endl;
			sum += korzina[i].cost;
		}
		cout << "Общая цена: " << sum << endl;
	}
	void show_assortiment()
	{
		cout << "ASSORTIMENT:" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << i + 1 << "  Продукт: " << assortiment[i].name << "  Цена: " << fixed << setprecision(3) << assortiment[i].cost << endl;
		}
	}
	int find_product_in_assortiment(string name)
	{
		for (int i = 0; i < 10; i++)
		{
			if (assortiment[i].name == name)
			{
				return i;
			}
		}
		return -1;
	}
	int find_product_in_korzina(string name)
	{
		for (int i = 0; i < korzina.GetSize(); i++)
		{
			if (korzina[i].name == name)
			{
				return i;
			}
		}
		return -1;
	}
	int get_korzina_size()
	{
		return korzina.GetSize();
	}
	void clear_korzina()
	{
		korzina.clear();
	}
	product get_product(int index)
	{
		return assortiment[index];
	}
	void delete_from_korzina(int index)
	{
		korzina.removeAt(index);
	}
	bool is_already_in_korzina(string name)
	{
		for (int i = 0; i < korzina.GetSize(); i++)
		{
			if (korzina[i].name == name) return true;
		}
		return false;
	}
};


int main()
{
	setlocale(LC_ALL, "RUS");
	e_shop e_shop;

	while (true)
	{
		cout << "1 - Просмотреть ассортимент"  << endl;

		cout << "2 - Добавить элемент в корзину"  << endl;

		cout << "3 - Удалить элемент из корзины"  << endl;

		cout << "4 - Очистить корзину" << endl;

		cout << "5 - Просмотреть корзину" << endl;

		cout << "6 - завершение работы программы" << endl;

		int choice;
		cout << "Ваш выбор: ";
		cin >> choice;

		switch  (choice)
		{
		case 1:
		   {
			  system("cls");
			  e_shop.show_assortiment();
			  cout << "Вернуться в главное меню - ENTER" << endl;
			  cin.ignore(32768, '\n');
			  cin.clear();
			  cin.get();
			  system("cls");
			  break;
		   }
		case 2:
		   {
			  system("cls");
			  cout << "Введите название товара: ";
			  string name;
			  cin >> name;
			  int index = e_shop.find_product_in_assortiment(name);
			  if (index == -1)
			  {
				  cout << "Товар не найден!" << endl;
			  }
			  else
			  {
				  if (e_shop.is_already_in_korzina(name))
				  {
					  system("cls");
					  cout << "Такой товар уже есть в корзине!" << endl;
				  }
				  else
				  {
					  product temp = e_shop.get_product(index);
					  cout << "Товар: " << temp.name << "  Цена: " << temp.cost << endl;
					  e_shop.push_product_to_korzina(temp.name, temp.cost);
					  cout << "Товар добавлен в корзину!" << endl;
				  }
			  }
			  cout << "Вернуться в главное меню - ENTER" << endl;
			  cin.ignore(32768, '\n');
			  cin.clear();
			  cin.get();
			  system("cls");
			  break;
		   }
		case 3:
		   {
			  system("cls");
			  cout << "Введите название продукта который хотите удалить из корзины: ";
			  string name;
			  cin >> name;
			  int index = e_shop.find_product_in_korzina(name);
			  if (index == -1)
			  {
				  cout << "Товар не найден!" << endl;
			  }
			  else
			  {
				  e_shop.delete_from_korzina(index);
				  cout << "Товар удален из корзины!" << endl;
			  }
			  cout << "Вернуться в главное меню - ENTER" << endl;
			  cin.ignore(32768, '\n');
			  cin.clear();
			  cin.get();
			  system("cls");
			  break;
		   }
		case 4:
		   {
			  system("cls");
			  e_shop.clear_korzina();
			  cout << "Корзина очищена!" << endl;
			  cout << "Вернуться в главное меню - ENTER" << endl;
			  cin.ignore(32768, '\n');
			  cin.clear();
			  cin.get();
			  system("cls");
			  break;
		   }
		case 5:
	       {
			  system("cls");
			  cout << "Ваша корзина: " << endl;
			  e_shop.show_korzina();
			  cout << "Вернуться в главное меню - ENTER" << endl;
			  cin.ignore(32768, '\n');
			  cin.clear();
			  cin.get();
			  system("cls");
			  break;
           }
		case 6:
		   {
			exit(0);
		   }
		default:
		   {
			  system("cls");
			  cout << "Такого варианта нет!";
			  cout << "Вернуться в главное меню - ENTER" << endl;
			  cin.ignore(32768, '\n');
			  cin.clear();
			  cin.get();
			  system("cls");
			  break;
		   }
		}
	}
	return 0;
}