#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;
#define REP(i, n) for(int i = 0; i < n; ++i)
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1LL << 60;
constexpr int MAX = 3030;


ll n, k, a[MAX], b[MAX];
ll c[MAX][MAX];

ll rec(bool turn, int l, int r) {
	if (c[l][r] != INF) return c[l][r];
	if (turn) {
		if (l == r) return a[l];
		// taro
		ll res = -INF;
		res = max(res, rec(0, l + 1, r) + a[l]);
		res = max(res, rec(0, l, r - 1) + a[r]);
		return c[l][r] = res;
	}
	else {
		if (l == r) return -a[l];
		// jiro
		ll res = INF;
		res = min(res, rec(1, l + 1, r) - a[l]);
		res = min(res, rec(1, l, r - 1) - a[r]);
		return c[l][r] = res;
	}
}

int main() {
	cin >> n;
	REP(i, n) cin >> a[i];
	REP(i, MAX) REP(j, MAX) c[i][j] = INF;
	cout << rec(1, 0, n - 1);
}