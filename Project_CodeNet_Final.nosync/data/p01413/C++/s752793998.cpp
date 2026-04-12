#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
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
#include <numeric>
#include <list>
#include <iomanip>
 
using namespace std;
 
#if __GNUC__
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#else
#include <unordered_map>
#include <unordered_set>
#endif
 
#ifdef __GNUC__
template <class T> int popcount(T n);
template <> int popcount(unsigned int n) { return __builtin_popcount(n); }
template <> int popcount(int n) { return __builtin_popcount(n); }
template <> int popcount(unsigned long long n) { return __builtin_popcountll(n); }
template <> int popcount(long long n) { return __builtin_popcountll(n); }
#else
#define __typeof__ decltype
template <class T> int popcount(T n) { return n ? 1 + popcount(n & (n - 1)) : 0; }
#endif
 
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define rforeach(it, c) for (__typeof__((c).rbegin()) it=(c).rbegin(); it != (c).rend(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CL(arr, val) memset(arr, val, sizeof(arr))
#define COPY(dest, src) memcpy(dest, src, sizeof(dest))
 
template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }
 
typedef long long ll;
typedef pair<int, int> pint;
 
template <class T, class U> ostream& operator<<(ostream& os, pair<T, U>& p) { os << "( " << p.first << ", " << p.second << " )"; return os;  }

template <class T> string to_s(const T& a) { ostringstream os; os << a; return os.str(); }

bool valid_pos(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }
 
template <class T> void print(T a, int n, int br = 1, const string& deli = ", ") { cout << "{ "; for (int i = 0; i < n; ++i) { cout << a[i]; if (i + 1 != n) cout << deli; } cout << " }"; while (br--) cout << endl; }
template <class T> void print(const vector<T>& v, int br = 1, const string& deli = ", ") { print(v, v.size(), br, deli); }
template <class T> void print2d(T a, int w, int h, int width = -1, int br = 1) { for (int i = 0; i < h; ++i) { for (int j = 0; j < w; ++j) {	if (width != -1) cout.width(width); cout << a[i][j] << ' ';	} cout << endl; } while (br--) cout << endl; }
 
template <class T> void input(T& a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }
template <class T, class U> void input(T& a, U& b, int n) { for (int i = 0; i < n; ++i) cin >> a[i] >> b[i]; }

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

const int mod = 1000000007;
const double PI = acos(-1.0); 



int n, W, T;

// city
int px[11], py[11];
vector<pint> item[11];	// pint(weight, value)

void input()
{
	int m;
	cin >> n >> m >> W >> T;

	map<string, pint> sale;	// pint(weight, value)
	for (int i = 0; i < m; ++i)
	{
		string s;
		int v, p;
		cin >> s >> v >> p;
		sale[s] = pint(v, p);
	}

	for (int i = 0; i < n; ++i)
	{
		int l;
		cin >> l >> px[i] >> py[i];
		while (l--)
		{
			string r;
			int q;
			cin >> r >> q;
			int profit = sale[r].second - q;
			if (profit > 0)
				item[i].push_back(pint(sale[r].first, profit));
		}
	}
}
// 個数制限なしナップザック
ll dpru(const vector<int>& w, const vector<int>& v, int limit)
{
	int n = w.size();
	static ll dp[10011];
	CL(dp, 0);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= limit; ++j)
			if (j - w[i] >= 0)
				max_swap(dp[j], dp[j - w[i]] + v[i]);

	return dp[limit];
}
vector<int> calc_profit()
{
	vector<int> max_profit(1 << n);
	for (int s = 0; s < 1 << n; ++s)
	{
		map<int, int> wv;
		for (int i = 0; i < n; ++i)
			if (s >> i & 1)
				for (int j = 0; j < item[i].size(); ++j)
					max_swap(wv[item[i][j].first], item[i][j].second);
		vector<int> w, v;
		foreach (it, wv)
		{
			w.push_back(it->first);
			v.push_back(it->second);
		}
		max_profit[s] = dpru(w, v, W);
	}
	return max_profit;
}
vector<int> calc_time()
{
	int dp[1 << 7][7];
	for (int s = 0; s < 1 << n; ++s)
		for (int i = 0; i < n; ++i)
			dp[s][i] = 1 << 30;
	for (int i = 0; i < n; ++i)
		dp[1 << i][i] = abs(px[i]) + abs(py[i]);

	for (int s = 0; s < 1 << n; ++s)
		for (int i = 0; i < n; ++i)
			if ((s >> i & 1))
				for (int j = 0; j < n; ++j)
					if (!(s >> j & 1))
						min_swap(dp[s | (1 << j)][j]
					, dp[s][i] + abs(px[i] - px[j]) + abs(py[i] - py[j]));

	vector<int> min_time(1 << n, 1 << 30);
	for (int s = 0; s < 1 << n; ++s)
		for (int i = 0; i < n; ++i)
			if (s >> i & 1)
				min_swap(min_time[s], dp[s][i] + abs(px[i]) + abs(py[i]));
	return min_time;
}
int main()
{
	input();

	vector<int> max_profit = calc_profit();
	vector<int> min_time = calc_time();
	ll res = dpru(min_time, max_profit, T);

	cout << res << endl;
}