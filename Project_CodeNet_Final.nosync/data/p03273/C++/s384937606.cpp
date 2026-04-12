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
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s, f) cout << fixed << setprecision(f) << s << endl;


int main()
{
	ll h, w;
	cin >> h >> w;

	vector<string> m;
	for (ll i = 0; i < h; i++)
	{
		string s;
		cin >> s;

		bool b = false;
		for (ll j = 0; j < w; j++)
		{
			if (s[j] == '#')
			{
				b = true;
				break;
			}
		}

		if (b)
		{
			m.push_back(s);
		}
	}

	h = m.size();
	for (ll i = 0; i < w; i++)
	{

		bool b = false;
		string s;
		for (ll j = 0; j < h; j++)
		{
			if (m[j][i] == '#')
			{
				b = true;
			}
		}

		if (!b)
		{
			for (ll j = 0; j < h; j++)
			{
				m[j][i] = '-';
			}
		}
	}

	for (ll i = 0; i < h ; i++)
	{

		for (ll j = 0; j < w; j++)
		{
			if (m[i][j] != '-')
			{
				print(m[i][j]);
			}
		}

		println("");
	}

}