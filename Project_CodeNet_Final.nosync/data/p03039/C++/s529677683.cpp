#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
template<class T> inline istream& operator >> (istream & c, vector<T> & A) {rep(i, A.size()) c >> A[i];return c;}
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int modPow(long long a, long long n, long long p) {//0でバグる
	if (n == 1) return a % p;
	if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
	long long t = modPow(a, n / 2, p);
	return (t * t) % p;
}

ll comb(ll n, ll p) {
	if (p * 2 > n) p = n - p;
	if (p > n - p) p = n - p;
	ll a = 1, b = 1;
	rrep(i, p + 1) {
		a = (a * (n - i + 1)) % mod;
		b = (b * i) % mod;
	}
	return a * (modPow(b, mod - 2, mod)) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			ll tmp1 = i, tmp2 = j, tmp3 = n - i - 1, tmp4 = m - j - 1;
			ll tmp = 0;
			(tmp += m * (tmp1 + 1) * tmp1 / 2) %= mod;
			(tmp += m * (tmp3 + 1) * tmp3 / 2) %= mod;
			(tmp += n * (tmp2 + 1) * tmp2 / 2) %= mod;
			(tmp += n * (tmp4 + 1) * tmp4 / 2) %= mod;
			(ans += tmp) %= mod;
		}
	}
	(ans *= comb(n * m - 2, k - 2)) %= mod;
	while (ans % 2 != 0) {
		ans += mod;
	}
	ans /= 2;
	ans %= mod;
	cout << ans << endl;
	return 0;
}