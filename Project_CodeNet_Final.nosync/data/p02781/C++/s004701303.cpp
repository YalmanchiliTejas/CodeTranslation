#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:1024000000")
#pragma warning( disable : 6031)
#pragma warning( disable : 4244)
#pragma warning( disable : 26451)
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <utility>
#include <bitset>
#include <cmath>
#include <sstream>
#include <functional>
#include <iomanip>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define eps (1e-15)

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<double> vd;
typedef vector< vd > vvd;
typedef vector< string > vs;
typedef pair< int, int > pii;
typedef vector< pii > vpii;
typedef vector<ll> vl;
typedef vector<vector<long long>> vvl;
typedef tuple<int, int, int> tiii;
const long long mod = int(1e9) + 7;
const int INF = 1e9;

ll get_k1(string n)
{
	if (sz(n) <= 0)
		return 0;
	return (sz(n) - 1) * 9 + (n[0] - '0');
}

ll get_k2(string n)
{
	if (sz(n) < 2)
		return 0;
	ll tn = sz(n) - 1;
	ll res = 0;
	if (tn >= 2)
		res = (tn * (tn - 1)) / 2LL * 81;
	for (int i = 1; i <= n[0] - '0'; i++)
	{
		string ts = string(sz(n) - 1, '9');
		if (i == n[0] - '0')
			ts = n.substr(1);
		while (ts[0] == '0')
			ts.erase(0, 1);
		res += get_k1(ts);
	}
	return res;
}

ll get_k3(string n)
{
	if (sz(n) < 3)
		return 0;
	ll tn = sz(n) - 1;
	ll res = 0;
	if (tn >= 3)
	{
		res = (tn - 2) * (tn - 1) * (tn) / 6LL * 729LL;
	}
	for (int i = 1; i <= n[0] - '0'; i++)
	{
		string ts = string(sz(n) - 1, '9');
		if (i == n[0] - '0')
			ts = n.substr(1);
		while (ts[0] == '0')
			ts.erase(0, 1);
		res += get_k2(ts);
	}
	return res;
}

ll solve(string n, int k)
{
	if (k == 1)
	{
		return get_k1(n);
	}
	else if (k == 2)
	{
		return get_k2(n);
	}
	else if (k == 3)
	{
		return get_k3(n);
	}
	return 0;
}
ll brute(string n, int k)
{
	stringstream ss;
	ss << n;
	int nn;
	ss >> nn;
	ll res = 0;
	for (int i = 1; i <= nn; i++)
	{
		int tk = 0;
		int ti = i;
		while (ti)
		{
			if (ti % 10 > 0)
				tk++;
			ti /= 10;
		}
		if (tk == k)
			res++;

	}
	return res;
	
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout << setprecision(18) << fixed;
#ifdef LOCAL_MACHINE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	string s;
	int k;
	cin >> s >> k;
	cout << solve(s, k);
	return 0;
}