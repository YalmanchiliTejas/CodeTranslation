#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; i++)
#define DEC(i, a, b) for(int i = (int)a; i >= (int)b; i--)
typedef pair<int, bool> pi;
typedef pair<int, pi> pii;
#define f first
#define s second
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
ll arr[200005];
map<pii, ll> memo;

ll dp(ll idx, ll taken, bool pre) {
	if (idx == n+1) {
		if (taken == n/2) return 0;
		else return (ll) -1e16;
	}
	if (taken + (n - idx + 2)/2 < n/2) return -1e16;
	pii cur = pii(idx, pi(taken, pre));
	if (memo.find(cur) != memo.end()) return memo[cur];
	
	ll ans = dp(idx+1, taken, 0);
	if (!pre) ans = max(ans, dp(idx+1, taken+1, 1) + arr[idx]);
	return memo[cur] = ans;
}

int main() {
	fastio; cin >> n;
	FOR(i, 1, n) cin >> arr[i];
	cout << dp(1, 0, 0);
}