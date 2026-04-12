#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 29;
const long long int Mod = 1000000007;
using ll = long long int;
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; ++i)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)

ll a[200010];

int main() {
	int n;
	cin >> n;


	rep(i, n) cin >> a[i];

	ll ans = 0;
	ll l = 0;

	rep(i, n) {
		l += a[i];
		l %= Mod;
	}

	for (int i = 0; i < n - 1; ++i) {
		l -= a[i];
		if (l < 0) l += Mod;
		ans += a[i] * l;
		ans %= Mod;
	}

	cout << ans % Mod << endl;
}