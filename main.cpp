/*
1. Написать функцию которая выводит массив double чисел на экран. Параметры
функции это сам массив и его размер. Вызвать эту функцию из main.
2. Задать целочисленный массив, состоящий из элементов 0 и 1.
Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в
принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
3. Задать пустой целочисленный массив размером 8. Написать функцию, которая с
помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на
экран. Для продвинутых:
4. * Написать функцию, которой на вход подаётся одномерный массив и число n
(может быть положительным, или отрицательным), при этом метод должен циклически
сместить все элементы массива на n позиций.
5. ** Написать функцию, которой передается не пустой одномерный целочисленный
массив, она должна вернуть истину если в массиве есть место, в котором сумма
левой и правой части массива равны.
Примеры: checkBalance([1, 1, 1, || 2, 1]) → true,
checkBalance ([2, 1, 1, 2, 1]) → false,
checkBalance ([10, || 1, 2, 3, 4]) → true.
Абстрактная граница показана символами ||, эти символы в массив не входят.
*/

#include <iostream>

const size_t INDEX_4 = 10U;
const size_t INDEX_5 = 5U;

void PrintArray(const double*, const size_t, const std::string s = "");
void PrintArray(const int*, const size_t, const std::string s = "");
void Change_0n1(int*, const size_t);
void FillArray(int*, const size_t);
void CycleReplaceArr(int*, const int);
bool CheckBalance(int*, const size_t);

int main()
{
	/* TASK #1 */
	std::cout << "\t\tTask #1\n";
	
	const size_t index = 5U;
	double aDoubles[index] = { 5.3, 6.123E+3, 9.21E-1, 1.0E+10, 3.420E-17 };

	PrintArray(aDoubles, index);

	std::cout << "_________________________________________\n\n";
	system("pause");

	/* TASK #2 */
	std::cout << "\t\tTask #2\n";

	const size_t index_2 = 10U;
	int aInts[index_2] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

	PrintArray(aInts, index_2, "Before:\n");
	Change_0n1(aInts, index_2);
	PrintArray(aInts, index_2, "\nAfter:\n");

	std::cout << "_________________________________________\n\n";
	system("pause");

	/* TASK #3 */
	std::cout << "\t\tTask #3\n";

	const size_t eight = 8U;
	int aInts8[eight] = {};

	FillArray(aInts8, eight);
	PrintArray(aInts8, eight);

	std::cout << "_________________________________________\n\n";
	system("pause");

	/* TASK #4 */
	std::cout << "\t\tTask #4\n";

	int shift = 0;
	int aInts10[INDEX_4] = {};

	FillArray(aInts10, INDEX_4);
	PrintArray(aInts10, INDEX_4, "Before:\n");
	std::cout << "\nEnter a shift: ";
	std::cin >> shift;
	CycleReplaceArr(aInts10, shift);
	PrintArray(aInts10, INDEX_4, "\nAfter:\n");

	std::cout << "_________________________________________\n\n";
	system("pause");

	/* TASK #5 */
	std::cout << "\t\tTask #5\n";

	int aInts5[INDEX_5] = {};
	bool result = false;

	std::cout << "Enter " << INDEX_5 << " int numbers one by one:\n";
	for (int i = 0; i < INDEX_5; i++)
	{
		std::cin >> aInts5[i];
	}

	result = CheckBalance(aInts5, INDEX_5);
	std::cout << std::boolalpha << result << std::endl;

	std::cout << "_________________________________________\n\n";
	system("pause");

	return 0;
}

void PrintArray(const double * pArr, const size_t count, const std::string s)
{
	std::cout << s;
	for (size_t i = 0U; i < count; i++)
	{
		std::cout << "Array[" << i << "] = " << pArr[i] << std::endl;
	}
}

void PrintArray(const int* pArr, const size_t count, const std::string s)
{
	std::cout << s;
	for (size_t i = 0U; i < count; i++)
	{
		std::cout << "Array[" << i << "] = " << pArr[i] << std::endl;
	}
}

void Change_0n1(int* pArr, const size_t count)
{
	for (size_t i = 0U; i < count; i++)
	{
		pArr[i] = (pArr[i] + 1) % 2;
	}
}

void FillArray(int* pArr, const size_t count)
{
	for (size_t i = 0U; i < count; i++)
	{
		pArr[i] = 1 + i * 3;
	}
}

void CycleReplaceArr(int* pArr, const int n)
{
	int aTmps[INDEX_4] = {};
	size_t loc_i = 0;

	for (size_t i = 0U; i < INDEX_4; i++)
	{
		if (n >= 0)
		{
			loc_i = (i + n) % INDEX_4;
		}
		else
		{
			loc_i = (i + (INDEX_4 - abs(n) % INDEX_4)) % INDEX_4;
		}

		aTmps[loc_i] = pArr[i];
	}

	for (loc_i = 0; loc_i < INDEX_4; loc_i++)
	{
		pArr[loc_i] = aTmps[loc_i];
	}
}

bool CheckBalance(int* pArr, const size_t count)
{
	bool balance = false;
	int sum_i = 0;
	int sum_j = 0;

	for (size_t i = 0U; (i < count - 1) && (balance == false); i++)
	{
		sum_i += pArr[i];
		sum_j = 0;
		for (size_t j = i + 1; j < count; j++)
		{
			sum_j += pArr[j];
		}
		if (sum_i == sum_j)
		{
			balance = true;
		}
	}

	return balance;
}