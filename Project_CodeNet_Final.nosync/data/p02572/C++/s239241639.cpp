#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n;
	ll mod = 1e9 + 7;
	cin >> n;
	vector<ll>As(n+1,0),A(n);
	ll a;
	rep(i, n) {
		cin >> a;
		A[i] = a;
		As[i + 1] = As[i] + a;
	}
	ll ans = 0;
	rep(i, n - 1) {
		ans += (A[i] * ((As[n] - As[i+1]) % mod));
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

