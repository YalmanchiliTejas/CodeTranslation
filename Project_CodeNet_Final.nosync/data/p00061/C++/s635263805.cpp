#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <utility>
#include <numeric>

using namespace std;
typedef long long llong;
typedef unsigned long long ullong;

const ullong MOD = 1000000000 + 7;

struct Info
{
	int p, s;

	Info()
	{

	}

	Info(int p, int s)
	{
		this->p = p;
		this->s = s;
	}
};

int main()
{
	vector<Info> a;

	string str;
	for (; cin >> str;)
	{
		stringstream ss;
		ss << str;

		int p, s;
		ss >> p;
		ss.ignore();
		ss >> s;

		if (p == 0 && s == 0)
		{
			break;
		}

		a.push_back(Info(p, s));
	}

	sort(a.begin(), a.end(),
		[](const Info &a, const Info &b)
	{
		return a.s < b.s;
	});

	reverse(a.begin(), a.end());

	int x;
	for (; cin >> x;)
	{
		int old = -1;
		int rank = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (old != a.at(i).s)
			{
				rank++;
			}

			if (x == a.at(i).p)
			{
				cout << rank << endl;
				break;
			}

			old = a.at(i).s;
		}
	}
}
