#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for (int i = a; i < (int)b; ++i)
#define rrep(i, n) for (int i = ((int)n - 1); i >= 0; --i)

using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int Inf = 1e9;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
	int n;
	cin >> n;
	ll sum = 0;
	vector<ll> a(n);
	rep (i, n) {
	  cin >> a[i];
	  sum += a[i];
	}
	ll res = 0;
	rep (i, n) {
	  sum -= a[i];
	  res += (sum % MOD) * a[i] % MOD;
	  res %= MOD;
	}
	cout << res << endl;
    
    return 0;
}
