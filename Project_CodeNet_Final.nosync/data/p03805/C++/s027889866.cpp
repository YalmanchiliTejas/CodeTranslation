#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> graph(n, vector<bool>(n));
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	vector<int> v(n - 1);
	rep(i, n - 1) v[i] = i + 1;
	int ans = 0;
	do {
		bool flag = true;
		if (!graph[0][v[0]]) flag = false;
		rep(i, n - 2) if (!graph[v[i]][v[i + 1]]) flag = false;
		if (flag) ans++;
	} while (next_permutation(all(v)));
	cout << ans << '\n';
}