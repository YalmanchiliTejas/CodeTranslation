#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>
#include <set>
#include <array>
#include <stdio.h>
#include <string.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS_VEC(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
#define CONTAINS_SET(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }

bool field[101][101];

signed main()
{
	int W, H;
	cin >> H >> W;
	REP(y, H)
	{
		string s;
		cin >> s;
		REP(x, W)
		{
			field[x][y] = s[x] == '#';
		}
	}

	bool skip_w[101] = {};
	bool skip_h[101] = {};

	for (int x = 0; x < W; x++)
	{
		bool has_black = false;
		for (int y = 0; y < H; y++)
		{
			if (field[x][y]) 
				has_black = true;
		}
		if (!has_black)
		{
			skip_w[x] = true;
		}
	}

	for (int y = 0; y < H; y++)
	{
		bool has_black = false;
		for (int x = 0; x < W; x++)
		{
			if (field[x][y])
				has_black = true;
		}
		if (!has_black)
		{
			skip_h[y] = true;
		}
	}

	for (int y = 0; y < H; y++)
	{
		if (!skip_h[y])
		{
			for (int x = 0; x < W; x++)
			{
				if (!skip_w[x])
				{
					cout << (field[x][y] ? '#' : '.');
				}
			}
			cout << endl;
		}
	}
}

