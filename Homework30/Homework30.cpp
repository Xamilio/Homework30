#include <iostream>
#include <string>
#include <cstring>
#include <clocale>
#include <Windows.h>
using namespace std;

struct film 
{
	string name;
	string producer;
	string genre;
	double rank;
	double price;
};

film list[1000];
int power = 0;

void printFilm(int n)
{
	cout << "\n";
	if (n < 0 || n >= power)
	{
		cout << "Такого фильма нет" << "\n";
		return;
	}
	cout << "Название: " << list[n].name << "\n";
	cout << "Режиссер: " << list[n].producer << "\n";
	cout << "Жанр: " << list[n].genre << "\n";
	cout << "Оценка: " << list[n].rank << "\n";
	cout << "Цена: " << list[n].price << "\n";
	cout << "\n";
	
}

string tolowerstr(string p)
{
	string res = "";
	for (int i = 0; i < p.length(); i++)
	{
		res = res + (char) tolower(p[i]);
	}
	return res;
}

void findByName(string name)
{
	for (int i = 0; i < power; i++)
	{
		if (tolowerstr(name) == tolowerstr(list[i].name))
		{
			printFilm(i);
		}
	}
}

void findByProducer(string name)
{
	for (int i = 0; i < power; i++)
	{
		if (tolowerstr(name) == tolowerstr(list[i].producer))
		{
			printFilm(i);
		}
	}
}

void findByGenre(string name)
{
	for (int i = 0; i < power; i++)
	{
		if (tolowerstr(name) == tolowerstr(list[i].genre))
		{
			printFilm(i);
		}
	}
}

void findByRank(int rank)
{
	for (int i = 0; i < power; i++)
	{
		if (tolower(rank) == tolower(list[i].rank))
		{
			printFilm(i);
		}
	}
}
void addFiml(string name, string producer, string  genre,int rank, int price)
{

	list[power].name = name;
	list[power].producer = producer;
	list[power].genre = genre;
	list[power].rank = rank;
	list[power].price = price;
	power = power + 1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	addFiml("Гарри Поттер и Кубок огня", "Майк Ньюэлл", "Фэнтези", 7.7, 200);
	addFiml("Гран Туризмо", "Нил Бломкамп", "Приключения", 7.2, 150);
	addFiml("Оппенгеймер", "Кристофер Нолан", "Исторический", 8, 250);
	addFiml("Джон Уик", "Дэвид Литч", "Боевик", 6, 150);
	addFiml("Варкрафт", "Данкан Джонс", "фэнтези", 5.5, 125);

	string pos;
	string req;
	int found;
	do
	{
		cout << "Поиск: 'n' - по названию, 'g' - по жанру, 'p' - по режиссеру, 'a' - все фильмы, '+' добавить новый, 'x' - выйти\n";
		cout << "Ваш выбор: ";
		getline(cin, pos);
		pos = tolowerstr(pos);
		if (tolowerstr(pos) == "n")
		{
			cout << "Введите название фильма: ";
			getline(cin, req);
			findByName(req);
		}
		if (pos == "g")
		{
			cout << "Введите жанр фильма: ";
			getline(cin, req);
			findByGenre(req);
		}
		if (pos == "p")
		{
			cout << "Введите режисера фильма: ";
			getline(cin, req);
			findByProducer(req);
		}
		if (pos == "+")
		{
			string name;
			string producer;
			string genre;
			double rank;
			double price;
			cout << "Название: ";
			getline(cin, name);
			cout << "Режиссер: ";
			getline(cin, producer);
			cout << "Жанр: ";
			getline(cin, genre);
			cout << "Рейтинг: ";
			cin >> rank;
			cout << "Цена: ";
			cin >> price;
			addFiml(name, producer, genre, rank, price);

			
		}
	} while (pos != "x");
}
