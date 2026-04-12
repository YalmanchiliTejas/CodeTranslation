#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define each(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(v) v.begin(), v.end()
#define mset(a, n) memset(a, n, sizeof(a))

typedef long long ll;

const int INF = 1000000000;
const int MOD = 1000000007;

vector<ll> a, p;

ll calc(int n, ll x) {
	if (n == 0) return x <= 0 ? 0 : 1;
	else if (x <= 1 + a[n-1]) return calc(n-1, x-1);
	else return p[n-1] + 1 + calc(n-1, x-2-a[n-1]);
}

int main(int argc, char const *argv[]) {
	ll N, X; cin >> N >> X;
	a.resize(N+1, 1);
	p.resize(N+1, 1);
	REP(i, 1, N+1) {
		a[i] = 2 * a[i - 1] + 3;
		p[i] = 2 * p[i - 1] + 1;
	}
	cout << calc(N, X) << endl;
	return 0;
}