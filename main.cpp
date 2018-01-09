#include "stdafx.h"
#include "iostream"
#include <string>
#include "typeinfo"
#include "map"

using namespace std;

//Переменные любого типа - массив, элемент для поиска в массиве
//Длина массива
template <class Items, class Item >
int get_count(Items elements[], Item an_element, int size) {
	int count = 0;
	//проверяем типы переменных в массиве и искомую, если все ок - идем смотреть сколько их
	if (typeid(*elements).name() == typeid(an_element).name())
	for (int i = 0; i < size; i++) {
		count++;
	}
	return count;
}

//переменные любого типа: массив;любой элемент массива который есть в массиве
//Длина масива - int
//Я не знаю как создать словарь без типа, поэтому сделал костыль
template <class Items, class Item>
void sorts(Items elements[],Item temp, int size) {

	//словарь для хранения результатов
	map<Item, int> myresult;

	//перебираем все значения и увеличиваем на 1 кажды элемент для словаря
	for (int i = 0; i < size; i++) {
		myresult[ elements[i] ]++;
	}

	//выводим идя по словарю
	//словарь имеет 2 параметра: первый(ключ) и второй(значение)
	//когда выводим - обращаемся именно к ним
	for (auto it = myresult.begin(); it != myresult.end(); it++){
		cout << it->first << " : " << it->second << endl;
	}
}

int main(){
	int numbers[11] = { 1,2,3,4,5,6,7,1,1,1,2 };
	int searchi = 1;
	cout << get_count(numbers, 1, 11) << " of " << searchi << endl;

	string strings[6] = { "one", "two", "three", "four", "one", "two" };
	string searchs = "one";
	cout << get_count(strings, searchs, 6) << " of " << searchs << endl;

	double doubles[6] = { 1.111, 2.222, 3.333, 4.444, 5.555, 6.666 };
	double searchd = 1.111;
	cout << get_count(doubles, searchd, 6) << " of " << searchd << endl;


	cout << get_count(doubles, "1", 6) << " of " << searchd << endl;

	sorts(strings,strings[0],6);

	system("pause");
    return 0;
}

