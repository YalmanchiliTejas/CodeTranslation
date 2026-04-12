#include <bits/stdc++.h>
#define int long long
#define rep(i, a, n) for (int i = a; i < n; i++)
#define sz(v) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_taple
const int INF = 1 << 30;
using namespace std;

int N, X;
int a[51], b[51];

int dfs(int lev, int x) {
	if (lev < 0) return x > 0;
	if (x <= a[lev]+1) return dfs(lev-1, x-1);
	if (x <= a[lev]+2) return b[lev]+1;
	return b[lev]+1+dfs(lev-1, x-a[lev]-2);
}

signed main() {
	cin >> N >> X;
	a[0] = 1;
	b[0] = 1;
	rep(i, 0, 49) {
		a[i+1] = 2*a[i]+3;
		b[i+1] = 2*b[i]+1;
	}
	cout << dfs(N-1, X) << endl;
}
