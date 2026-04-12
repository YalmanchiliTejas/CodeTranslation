#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> v;
vector<vector<ll>> dp(3005, vector<ll>(3005, INF));

ll f(int x, int y, bool flag) {
	if (x > y) return 0;
	if (dp[x][y] != INF) return dp[x][y];

	if (flag) {
		dp[x][y] = max(f(x + 1, y, !flag) + v[x], f(x, y - 1, !flag) + v[y]);
	} else {
		dp[x][y] = min(f(x + 1, y, !flag) - v[x], f(x, y - 1, !flag) - v[y]);
	}

	return f(x, y, flag);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; read(n);
	v = vector<ll>(n);
	rep(i, 0, n) cin >> v[i];

	die(f(0, n - 1, 1));
}
