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

using namespace std;

int n;
string s;
bool make(string res)
{
	for (int i = 1; i < n - 2; i++)
	{
		if (s[i] == 'o')
		{
			if (res[i] == 'S')
			{
				res[i + 1] = res[i - 1];
			}
			else
			{
				if (res[i - 1] == 'S')
				{
					res[i + 1] = 'W';
				}
				else
				{
					res[i + 1] = 'S';
				}
			}
		}
		else
		{
			if (res[i] == 'W')
			{
				res[i + 1] = res[i - 1];
			}
			else
			{
				if (res[i - 1] == 'S')
				{
					res[i + 1] = 'W';
				}
				else
				{
					res[i + 1] = 'S';
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int prev, next;
		prev = i - 1;
		next = i + 1;
		if (prev == -1)
		{
			prev = n - 1;
		}
		if (next == n)
		{
			next = 0;
		}
		if (s[i] == 'o')
		{
			if (res[i] == 'S')
			{
				if (res[prev] != res[next])
				{
					return false;
				}
			}
			else if (res[i] == 'W')
			{
				if (res[prev] == res[next])
				{
					return false;
				}
			}
		}
		else if (s[i] == 'x')
		{
			if (res[i] == 'S')
			{
				if (res[prev] == res[next])
				{
					return false;
				}
			}
			else if (res[i] == 'W')
			{
				if (res[prev] != res[next])
				{
					return false;
				}
			}
		}
	}
	cout << res << '\n';
	return true;
}
int main(void)
{
	string res;

	cin >> n;
	cin >> s;

	res.resize(n);
	if (s[0] == 'o')
	{
		//sheep
		res[0] = 'S';
		res[1] = 'S';
		res[n - 1] = 'S';
		if (make(res) == true)
		{
			return 0;
		}
		res.clear();
		res.resize(n);
		res[0] = 'S';
		res[1] = 'W';
		res[n - 1] = 'W';
		if (make(res) == true)
		{
			return 0;
		}
		res.clear();
		res.resize(n);
		//wolf
		res[0] = 'W';
		res[n - 1] = 'W';
		res[1] = 'S';
		if (make(res) == true)
		{
			return 0;
		}
		res.clear();
		res.resize(n);
		res[0] = 'W';
		res[1] = 'W';
		res[n - 1] = 'S';
		if (make(res) == true)
		{
			return 0;
		}
	}
	else
	{
		//WOLF
		res[0] = 'W';
		res[1] = 'S';
		res[n - 1] = 'S';
		if (make(res) == true)
		{
			return 0;
		}
		res.clear();
		res.resize(n);
		res[0] = 'W';
		res[1] = 'W';
		res[n - 1] = 'W';
		if (make(res) == true)
		{
			return 0;
		}
		res.clear();
		res.resize(n);
		//SHEEP
		res[0] = 'S';
		res[n - 1] = 'W';
		res[1] = 'S';
		if (make(res) == true)
		{
			return 0;
		}
		res.clear();
		res.resize(n);
		res[0] = 'S';
		res[1] = 'W';
		res[n - 1] = 'S';
		if (make(res) == true)
		{
			return 0;
		}
	}

	cout << -1 << '\n';
	return 0;
}