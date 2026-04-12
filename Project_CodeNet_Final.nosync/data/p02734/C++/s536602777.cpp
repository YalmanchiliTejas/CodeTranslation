#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
#define trace3(x, y, z) cerr << #x << ": " << x << ", " << #y < ": " << y << ", " << #z << ": " << z << endl;
#define all(v) v.begin(), v.end()
#define MOD 998244353

int main() {
	int n, s;
	cin >> n >> s;
	vi a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vvll dp(n + 1, vll(s + 1, 0)), dpsum(n + 1, vll(s + 1, 0));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= s; j++) {
			if(a[i] == j) {
				dp[i][j] = i;
			}
			else if(a[i] < j) {
				dp[i][j] = dpsum[i - 1][j - a[i]];
			}
			(dpsum[i][j] = dpsum[i - 1][j] + dp[i][j]) %= MOD;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		(ans += dp[i][s] * (n - i + 1)) %= MOD;
	}
	cout << ans << endl;
}