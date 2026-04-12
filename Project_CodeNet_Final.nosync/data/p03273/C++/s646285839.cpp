#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
#include <random>
#include <bitset>
#include <time.h>
#include <string>
#include <cstdio>
#include <vector>
#include <cassert>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
#define endl '\n'
#define mp make_pair
#define pbc push_back
#define pob pop_back()
#define empb emplace_back
#define sp system("pause")
#define queuel queue<long long>
#define all(x) (x).begin(), (x).end()
#define matrix vector<vector<ll>>
#define pin(p) cin >> p.first >> p.second;
#define rev(v) reverse(v.begin(), v.end());
#define mx(a) max_element(a.begin(), a.end());
#define mn(v) min_element(v.begin(), v.end());
#define sout(s, c) for (auto i : s) cout << i << c;
#define pout(p) cout << p.first << " " << p.second;
#define er(v, l, r) erase(v.begin() + l, v.begin() + r);
#define vin(v) for (ll i = 0; i < v.size(); ++i) cin >> v[i];
#define vout(v, c) for (int i = 0; i < v.size(); ++i) cout << v[i] << c;
#define pushi(v, a) for (int i = 0; i < a.size(); ++i) v.push_back(a[i]);
#define sin(s, n) for (int i = 0; i < n; ++i){int a; cin >> a; s.insert(a);}
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
using namespace std;
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> > fd;
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
const ll INF = 1e18;
const int inf = 1e9;
const ld PI = acos(-1.0);
const ll mod1 = inf + 7;
const ll mod2 = inf + 9;
const int MAXN = 100001;
const ld EPS = 1.0e-8;

signed main()
{
	fastio();
	int h, w;
	cin >> h >> w;
	vector<vector<char>> f;
	for (int i = 0; i < h; ++i)
	{
		vector<char> nw(w);
		vin(nw);
		if (count(all(nw), '#'))
		{
			f.pbc(nw);
		}
	}
	vector<vector<char>> nem(f.size());
	for (int j = 0; j < w; ++j)
	{
		vector<char> nw;
		for (int i = 0; i < f.size(); ++i)
		{
			nw.pbc(f[i][j]);
		}
		if (count(all(nw), '#'))
		{
			for (int i = 0; i < nw.size(); ++i)
			{
				nem[i].pbc(nw[i]);
			}
		}
	}
	for (int i = 0; i < f.size(); ++i)
	{
		for (int j = 0; j < nem[i].size(); ++j)
		{
			cout << nem[i][j];
		}
		cout << endl;
	}
}	