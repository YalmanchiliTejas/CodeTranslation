#include <iostream>
#include <string>
#include <utility>

int ctoi(char c)
{
	switch (c)
	{
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case'9':
		return 9;
	default:
		return 0;
	}
}

std::string GetResidueString(const std::string& str)
{
	// 上から2桁目以降で最初に0以外が現れるpositionを探す
	const size_t nonZeroPos = str.find_first_not_of("0", 1);

	if (nonZeroPos == std::string::npos)
	{
		// すべて0だった
		return "";
	}

	return str.substr(nonZeroPos);
}

long long GetOneDigitNum(const std::string& str)
{
	if (str.empty())
	{
		return 0;
	}

	return (static_cast<int>(str.size()) - 1) * 9 + ctoi(str.front());
}

long long GetTwoDigitNum(const std::string& str)
{
	if (str.empty())
	{
		return 0;
	}

	const int size = static_cast<int>(str.size());
	if (size == 1)
	{
		return 0;
	}

	long long sum = (size - 1) * (size - 2) * 81 / 2;
	for (int i = 1; i < ctoi(str.front()); ++i)
	{
		sum += (size - 1) * 9;
	}

	sum += GetOneDigitNum(GetResidueString(str));

	return sum;
}

long long GetThreeDigitNum(const std::string& str)
{
	const int size = static_cast<int>(str.size());
	if (size < 3)
	{
		return 0;
	}
	
	long long sum = (size - 1) * (size - 2) * (size - 3) * 243 / 2;
	for (int i = 1; i < ctoi(str.front()); ++i)
	{
		sum += (size - 1) * (size - 2) * 81 / 2;
	}
	sum += GetTwoDigitNum(GetResidueString(str));

	return sum;
}

int main()
{
	std::string n;
	int k = 0;
	std::cin >> n >> k;

	if (k == 1)
	{
		std::cout << GetOneDigitNum(n) << std::endl;
	}
	else if (k == 2)
	{
		std::cout << GetTwoDigitNum(n) << std::endl;
	}
	else
	{
		std::cout << GetThreeDigitNum(n) << std::endl;
	}
}