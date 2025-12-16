#include <iostream>
//Да се напише функция, която приема 3 цели числа n, pos - позиция и бит b - 0 или 1 и сменя бита на n на позиция pos с бита b.
int changeBit(int n, size_t pos, bool b)
{
	if (b)
	{
		int mask = b << pos;
		return n | mask;
	}
	int mask = !b << pos;
	mask = ~mask;
	return n & mask;
}
int main()
{
	int num;
	size_t pos;
	bool b;

	std::cout << "Input number, position and bit: ";
	std::cin >> num >> pos >> b;

	std::cout << "result: " << changeBit(num, pos, b);

}
