#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;

int n;
ll ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll a; cin >> a;
		ll change = (a % MOD) * (sum % MOD) % MOD;
		ans = (ans % MOD + change % MOD) % MOD;
		ans %= MOD;
		sum += a;
	}
	
	
	cout << ans;
}
