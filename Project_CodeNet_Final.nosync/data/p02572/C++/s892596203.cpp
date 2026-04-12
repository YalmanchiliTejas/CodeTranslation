#include <bits/stdc++.h>

#define debug_input freopen("stdin.in", "r", stdin)
#define debug_output freopen("stdout.out", "w", stdout)
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORALL(i, n) for(ll i = 0; i < n; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())
#define NP(a) next_permutation(a.begin(), a.end())
#define endl "\n"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n;
ll a[200005];
ll sum[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll mod = 1e9 + 7;
	ll tot = 0;
	ll ans = 0;

	cin >> n;	

	sum[0] = 0;
	FOR(i, 1, n) {
		cin >> a[i];
		sum[i] = (sum[i - 1] + a[i]) % mod;
	}

	FOR(i, 1, n) {
		ans = (ans + (a[i] * ((mod + sum[n] - sum[i]) % mod) % mod)) % mod;
	}

	cout << ans << endl;
	return 0;
}