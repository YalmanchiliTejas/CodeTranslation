#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(ll i = m, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define clr(ar, val) memset(ar, val, sizeof(ar))
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> e[n], v;
	rep (i, n) v.push_back(i);
	rep (i, m) {
		int a, b;
		cin >> a >> b;
		e[b - 1].push_back(a - 1);
		e[a - 1].push_back(b - 1);
	}
	while (true) {
		bool ok = true;
		if (v[0] != 0) break;
		rep (i, n - 1) {
			int s = v[i], g = v[i + 1];
			if (!any_of(e[s].begin(), e[s].end(), [&](int x) {return x == g; })) ok = false;
		}
		if (ok) {
			// rep (i, n) cout << v[i] + 1 << " "; cout << endl;
			ans++;
		}
		if (!next_permutation(v.begin(), v.end())) break;
	}
	cout << ans << endl;
	return 0;
}