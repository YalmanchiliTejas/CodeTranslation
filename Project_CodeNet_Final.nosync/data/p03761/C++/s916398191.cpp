#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <stack>
#include <sstream>
#include <set>
#include <cmath>
#include <functional>
#include <memory.h>

// pi = atan(1)*4;

#define INTMAX 2100000000

using namespace std;

int main(void)
{
	map <char, int> count[51];
	int n;
	string str;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			count[i][str[j]] += 1;
		}
	}

	str = "";
	for (char c = 'a'; c <= 'z'; c++)
	{
		int Min = INTMAX;
		for (int i = 1; i <= n; i++)
		{
			Min = min(Min, count[i][c]);
		}
		for (int i = 0; i < Min; i++)
		{
			str += c;
		}
	}

	cout << str << '\n';
	return 0;
}