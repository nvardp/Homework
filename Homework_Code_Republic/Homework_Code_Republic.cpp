#include <vector>
#include<algorithm> 
#include <bitset>
#include <iostream>
#include<cmath>


using namespace std;

int a1 = 0;
string S = "";

int sum_of_multiplier()
{
	for (int i = 0; i < 1000; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
			a1 += i;
	}
	return a1;
}
bool is_power_of_2(int a)
{
	return (a & (a - 1)) == 0;
}
int Longest_String(string str)
{
	int res = 0; // result 
	for (int i = 0; i < str.length(); i++) {
		vector<bool> visited(256); // Default false
		for (int j = i; j < str.length(); j++)
		{
			if (visited[str[j]] == true)
			{
				break;
			}
			else
			{
				res = max(res, j - i + 1);
				visited[str[j]] = true;
				//substring.push_back(str.at(j));
			}
			//	for (std::vector<char>::const_iterator k = substring.begin(); k != substring.end(); ++k)
				//	std::cout << *k << ' ';
		}
	}
	return res;
}

class working_with_bits
{
public:

	long Arr[4] = {};

	void set_bits(string str)
	{
		//count_bits();
		//int bits_in_variable;
		//if (bits_in_variable < 32)// 8 bit *4 =32
		//{
		//	char a = 0;
		//	char b = 0;
		//	char c = 0;
		//	char d = 0;
		//}
		//else if (bits_in_variable < 128) //32*4
		//{
		//	int a = 0;
		//	int b = 0;
		//	int c = 0;
		//	int d = 0;
		//}
		//else if (bits_in_variable > 128) // 64*4=256
		//{
		//	long a = 0;
		//	long b = 0;
		//	long c = 0;
		//	long d = 0;
		//}

		for (char ch : str)
		{
			int index = (int)ch / 64;
			long shifted_bit = 0;

			// ցիկլի n-րդ անդամից հանում ենք վերջին սիմվոլը, որ իմանանք 1-ը քանի անգամ շիֆթ անենք, որ հետո տեղադրենք => | անենք զրոների/ արդեն ունեցած աղյուսակի հետ
			shifted_bit = 1 << ((char)(64 + (index * 64)) - ch);

			if (Arr[index] & shifted_bit == Arr[index])
			{// do nothing, is not unique
			}
			else
			{
				Arr[index] = Arr[index] | shifted_bit;
			}
		}
	}

	//void get_bits(string str)
	//{
	//	for (char ch : a) // chem karoxanum a-i biteri vra pttvem
	//	{
	//		char result = (char)(ch + '@');
	//	}

	//	for (char ch : b) 
	//	{
	//		char result = (char)(ch + '@');
	//	}for (char ch : c) 
	//	{
	//		char result = (char)(ch + '@');
	//	}for (char ch : d) 
	//	{
	//		char result = (char)(ch + '@');
	//	}
	//}

	int count_bits()
	{
		int count = 0;
		for (int i = 0; i <= 4; i++)
		{
			while (Arr[i])
			{
				count += Arr[i] & 1;
				Arr[i] >>= 1;
			}
		}
		return count;
	}

	int count_size()
	{
		int count = 0;
		for (int i = 0; i <= 4; i++)
		{
			while (Arr[i]) // while-i mej chi mtnum
			{
				count++;
			}
		}
		return count;
	}

private:

};

bool is_number_palindrome(int x)
{
	int origin_number, num = x, digit, rev = 0;
	origin_number = x;
	do
	{
		digit = x % 10;
		rev = (rev * 10) + digit;
		x = x / 10;
	} while (x != 0);
	if (origin_number == rev)
		return true;
	else return false;
}

int main()
{


#pragma region Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero
	vector<int> threeSum{ -1, 0, 1, 2, -1, -4 };
	for (int i = 0; i < threeSum.size() - 2; i++)
	{
		for (int j = 2; j < threeSum.size(); j++)
		{
			if (j < threeSum.size())
				if (threeSum[i] + threeSum[i + 1] + threeSum[j] == 0)
					cout << threeSum[i] << threeSum[i + 1] << threeSum[j] << endl;
		}
	}
#pragma endregion


#pragma region x raised to the power n (i.e. xn).
	double result4 = 1.0, number5 = 2.0, n = -2.0;
	if (n > 0)
		for (int i = 0; i < n; ++i)
		{
			result4 *= number5;
		}
	else
	{
		n = n * (-1);
		for (int i = 0; i < n; ++i)
		{
			result4 *= 1 / number5;
		}
	}
	cout << result4 << endl;
#pragma endregion





#pragma region Find the largest palindrome made from the product of two 3-digit numbers.
	int asas = 0;
	long long ex_result = 0;
	int first = 100, last = 999; long long result1 = 0;
	for (int j = 0; j < last; j++)
	{
		for (size_t i = 0; i < last - j; i++)
		{
			if ((first + i + 1) < 100)
			{
				result1 = first * (first + (i + 1));
				bool res = is_number_palindrome(result1);
				if (res == true)
				{
					//	ex_result = result1;
				//	result1=	max(result1, ex_result);
					ex_result = result1;
				}
			}
		}
		first++;
	}
	cout << "the largest palindrome made from the product of two 3-digit numbers is " << ex_result << endl;

#pragma endregion



#pragma region the smallest positive number that is evenly divisible by all of the numbers from 1 to 20

	int number3 = 0;
	int _break = 2;
	int arr[] = { 3, 4, 5, 7, 8, 9, 11, 13, 16, 17, 19 };
	int index = 0;
	for (int j = 1; j < _break; j++)
	{
		if (j % arr[index] != 0)
		{
			_break++;
			index = 0;
		}
		else {
			_break++;
			index++;
			number3 = j;
			j--;
			if (index == 11)
				_break = 0;
		}
	}
	cout << number3 << endl;
#pragma endregion


#pragma region Prime Factor
	int number2 = 0;
	cout << "enter integer to see Prime factor    ";
	cin >> number2;
	for (int i = 2; i <= number2; i++)
	{
		if (number2 % i == 0)
		{
			cout << i << " ";
			number2 = number2 / i;
			i = 1;
		}
	}
#pragma endregion


#pragma region Roman numbers
	cout << "Enter number you want to see as Roman" << endl;
	int number[] = { 1,       4,   5,    9,  10,   40,  50,  90,   100, 400,  500, 900, 1000 };
	string roman[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	int Enterd_number;
	cin >> Enterd_number;
	int i = 12;
	while (number > 0)
	{
		int div = Enterd_number / number[i];
		Enterd_number = Enterd_number % number[i];
		while (div--) // in case 0 will not enter the loop
		{
			cout << roman[i];
		}
		i--;
	}
#pragma endregion



#pragma region Fibonacci
	int result = 1;
	int a = 0, b = 1, c = 1, zero = 0;;
	cout << "Fibonacci numbers are \n 0, 1, ";
	while (c < 4000000) // Question!! if I put here for(size==100) members after 45 are negative. How????
	{
		c = a + b;
		std::cout << c << ", ";
		a = b;
		b = c;
		int even = (zero & (zero >> 1));
		//զույգերը սկսում մեկով և վերջանում զրոյով => even ստանալու համար AND անելուց հետո կստանանք 100000
		// 		int odd = (zero & (zero << 1)) & (zero & (zero >> 1)); // որ ստանանք 100001
		if (c & even == even) // չի աշխատում- կենտերն ա վերցնում զույգերի փոխարեն
		{
			result += c;
		}
		/*if (c % 2 == 0)
		{
			result += c;
		}*/
	}
	cout << endl << "the sum of the even-valued terms is " << result << endl << endl;
#pragma endregion

	working_with_bits newTest;
	newTest.set_bits("abc");
	cout << "my string is <abc> and this is count_bits function " << newTest.count_bits();
	cout << endl;
	cout << "this is count_size function which is not working " << newTest.count_size() << endl << endl;
	/*string test = "b";
	for (char ch : test)
	{
		cout << (int)ch;
	}*/
#pragma region bajanarar
	int number1 = 0;
	cin >> number1;
	int one_down = number1;
	int time = number1;
	while (time--)
	{
		one_down--;
		if (number1 % (one_down) == 0)
			cout << one_down << " ";
	}
#pragma endregion

#pragma region Day 1  Exercise 1
	sum_of_multiplier();
	std::cout << "Sum of  all the multiples of 3 or 5 below 1000 is " << a1;
	std::cout << endl << endl;
#pragma endregion


#pragma region Day 1 Excercise 2

	string str = "";
	cout << "Enter a string   ";
	cin >> str;
	int len = Longest_String(str);
	std::cout << "The length of the substring is " << len << endl;
#pragma endregion

	int a1 = 16;
	cout << "is " << a1 << " power of 2?  " << is_power_of_2(a1) << endl;


	int const size = 5;
	int Arr[size] = { 1, 1, 2, 2, 8 };
	hash<bool> tbl;
	for (int i = 0; i < size; ++i)
	{
		if (tbl(Arr[i]) == true)
		{
		}
		else
			tbl(Arr[i]); // chi toxnum = true anem=> misht mtnum a else-i mej
		cout << tbl(Arr[i]); // stex el cuyc a talis hash arac@ voch  te arjeqner@...
	}


	return 0;
}


