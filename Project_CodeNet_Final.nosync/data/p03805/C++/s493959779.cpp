#define MYDEBUG
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <queue>
#include <set>
#include <cstdio>
#include <unordered_map>

#ifdef MYDEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x)
#endif
#define ll long long
#define ull unsigned long long
#define eps 1e-14
#define all(x) x.begin(), x.end()
using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "[";
	size_t last = v.size() - 1;
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i];
		if (i != last)
			out << ",";
	}
	out << "]";
	return out;
}
int n, m;
const int MAXN = 8 + 1;
int g[MAXN][MAXN];
int vis = 0;
long long dfs(int now, int rest, int vis) {
	if (rest == 0)
		return 1;
	ll ans = 0;
	for (int i = 2; i <= n; ++i) {
		if ((vis >> i) % 2 == 0 && g[now][i] == 1) {
			vis = vis | (1 << i);
			ans += dfs(i, rest - 1, vis);
			vis -= 1 << i;
		}
	}
	return ans;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < MAXN; ++i) {
		for (int k = 0; k < MAXN; ++k) {
			g[i][k] = g[k][i] = 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}
	vis = 1 << 1;
	ll cnt = dfs(1, n - 1, vis);
	cout << cnt << endl;
}
int main() {
	solve();
	return 0;
}
