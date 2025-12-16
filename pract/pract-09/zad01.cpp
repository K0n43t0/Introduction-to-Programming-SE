#include <iostream>
//Напишете функция, която приема число k, (0 < k <= 16) и масив от символи репрезентиращи числото в k-ична бройна система
//и приема число m, (0 < m <= 16). Функцията извежда на стандартния изход числото в m-ична бройна с-ма.
const int MIN_VAL = 0;
const int MAX_VAL = 16;
const size_t SIZE = 1024;
int charToNum(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';

	if (ch > 'A' && ch < 'Z')
		return ch - 'A' + 10;

	return -1;
}
char numToChar(int num)
{
	if (num < 0 || num > 15)
		return '?';

	if (num >= 0 && num <= 9)
		return num + '0';

	return num - 10 + 'A';
}
void revArray(char array[], size_t size)
{
	int limit = size / 2;
	for (int i = 0; i < limit; ++i)
	{
		size_t index = size - i - 1;
		array[i] = array[index] ^ array[i];
		array[index] = array[index] ^ array[i];
		array[i] = array[index] ^ array[i];
	}
}
void showNumInDifNumSystem(int k, int m, const char num[], char result[], size_t sizeNum, size_t& sizeResult)
{
	if (k <= MIN_VAL || k > MAX_VAL || m < MIN_VAL || m > MAX_VAL)
		return;

	int res = 0;
	for (int i = 0; i < sizeNum; ++i)
	{
		res *= k;
		res += charToNum(num[i]);
	}
	
	sizeResult = 0;
	while (res != 0)
	{
		result[sizeResult] = numToChar(res % m);
		res /= m;
		sizeResult++;
	}

	revArray(result, sizeResult);
}
void inputArray(char array[], size_t size)
{
	for (int i = 0; i < size; ++i)
		std::cin>>array[i];

	std::cout << '\n';
}
void printArray(const char array[], size_t size)
{
	for (int i = 0; i < size; ++i)
		std::cout << array[i];
}
int main()
{
	int k, m;
	std::cout << "Input values for k and m: ";
	std::cin >> k >> m;

	size_t size;
	std::cout << "Input the size of the number: ";
	std::cin >> size;

	char num[SIZE];
	std::cout << "Input the number: ";
	inputArray(num, size);

	char result[SIZE];
	size_t rSize = 1;
	showNumInDifNumSystem(k, m, num, result, size, rSize);

	printArray(result, rSize);
}
