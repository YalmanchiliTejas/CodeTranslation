
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

bool b[9][9];
int wid, hei;
bool getBoard()
{
	memset(b, 0, sizeof(b));
	string s;
	cin >> s;
	if (s == "#")return false;
	int bx = 0, by = 0;
	for (char c : s)
	{
		switch (c)
		{
		case 'b':
			b[bx][by] = true;
			by++;
			break;
		case '/':
			bx++; wid = by; by = 0;
			break;
		default:
		{
			int i = c - '0';
			by += i;
			break;
		}
		}
	}
	hei = bx + 1;
	return true;
}
void setBoard()
{
	string s;
	for (int i = 0; i < hei; ++i)
	{
		for (int j = 0; j < wid; ++j)
		{
			if (b[i][j])s.push_back('b');
			else s.push_back('1');
		}
		s.push_back('/');
	}
	s.pop_back();
	for (int loop = 0; loop < 100; ++loop)
	{
		for (int i = 1; i < s.size(); ++i)
		{
			if ('1' <= s[i] && s[i] <= '9' && '0' <= s[i - 1] && s[i - 1] <= '9')
			{
				s[i]--;
				s[i - 1]++;
			}
		}
	}
	string t;
	for (char c : s)if (c != '0')t.push_back(c);
	cout << t << endl;
}

int main(void)
{
	while (getBoard())
	{
		int p, q, r, s;
		cin >> p >> q >> r >> s;
		b[p - 1][q - 1] = false;
		b[r - 1][s - 1] = true;
		setBoard();
	}
	return 0;
}