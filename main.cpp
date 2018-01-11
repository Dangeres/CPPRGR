#include "stdafx.h"
#include "iostream"
#include <string>
#include <map>

using namespace std;

//Переменные любого типа - массив, элемент для поиска в массиве
//Длина массива
template <class Items, class Item >
int get_count(Items elements[], Item an_element, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if(elements[i]==an_element)
			count++;
	}
	return count;
}

//переменные любого типа: массив;любой элемент массива который есть в массиве
//Длина масива - int
//Я не знаю как создать словарь без типа, поэтому сделал костыль
template <class Items, class Item>
map<Item, int> sorts(Items elements[], Item temp, int size) {
	//словарь для хранения результатов
	map<Item, int> myresult;

	//перебираем все значения и увеличиваем на 1 каждый элемент для словаря
	//если входной массив имеет такой вид: "one","two","two"
	//то после выполнения этого цикла будет возвращен результат: "one":1, "two":2
	for (int i = 0; i < size; i++) {
		myresult[ elements[i] ]++;
	}

	return myresult;
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

	map<string, int> myresult = sorts(strings, strings[0], 6);

	cout << "result of second function" << endl;

	//выводим идя по словарю
	//словарь имеет 2 параметра: первый(ключ) и второй(значение)
	//когда выводим - обращаемся именно к ним
	for (auto it = myresult.begin(); it != myresult.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}

	system("pause");
    return 0;
}
