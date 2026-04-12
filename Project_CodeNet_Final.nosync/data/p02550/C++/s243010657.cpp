#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <random>
//#include <math.h>
#include <cmath>
#include <fstream>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <bitset>

#pragma comment(linker, "/STACK:36777216")
using namespace std;

#define flu fflush(stdout)
#define gg return 0
#define mp make_pair

typedef long double ptype;

long long mod = /*27449*//*998244353*/ /*1e9 + 7*/998244353 /*1e9 + 9*/;
int inf = 1e9;
double eps = 1e-7;
long double pi = acosl(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ifstream in("input.txt");
ofstream out("output.txt");

int used[100010];

void solve()
{
	long long n;
	cin >> n;
	long long x, m;
	cin >> x >> m;
	long long cur = x;
	int id = 1;
	vector<int> vals;
	vals.push_back(0);
	int cyclelen = 0;
	int start = 1;
	while (1)
	{
		if (used[cur] != 0)
		{
			start = used[cur];
			cyclelen = id - used[cur];
			break;
		}
		used[cur] = id;
		vals.push_back(cur);
		cur = cur * cur % m;
		id++;
	}
	long long ans = 0;
	for (int i = 1; n > 0 && i < start; i++, n--)
	{
		ans += vals[i];
	}
	long long cyclesum = 0;
	for (int i = start; i < vals.size(); i++)
	{
		cyclesum += vals[i];
	}
	ans += n / cyclelen * cyclesum;
	n %= cyclelen;
	for (int i = 0; i < n; i++)
	{
		ans += vals[start + i];
	}
	cout << ans;
}

int main()
{
	cout << setprecision(20) << fixed;
	cin.tie();
	cout.tie();
	clock_t t1 = clock();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	//cin >> t;
	t = 1;
	while (t--) {
		solve();
		//test();
	}
	//cout << (clock() - t1) * 1.0 / CLOCKS_PER_SEC;
	gg;
}