#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 3000 + 10;
const int mod = 998244353;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, s, a[N];
ll dp[N][N];
int main() {
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= s; j ++) {
			dp[i][j] = (dp[i - 1][j] + (j >= a[i] ? dp[i - 1][j - a[i]] : 0)) % mod;
		}
		if(a[i] <= s) (dp[i][a[i]] += i) %= mod;
		if(s >= a[i]) (ans += dp[i - 1][s - a[i]] * (n - i + 1ll) % mod) %= mod;
		if(a[i] == s) (ans += 1ll * i * (n - i + 1ll) % mod) %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}