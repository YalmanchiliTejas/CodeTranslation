#include <bits/stdc++.h>
 
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define int long long
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int N = 10010, D = 100;
const int MOD = 1000000007;
const int LOG = 20;
 
int d;
string n;
ll dp[N][D];
 
int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> d;
	dp[0][0] = 1;
	for (int i = 1; i < n.size(); i++){
		for (int j = 0; j < d; j++){
			for (int k = 0; k < 10; k++){
				int num = (j - k) % d;
				num += d;
				num %= d;
				dp[i][j] += dp[i - 1][num];
				dp[i][j] %= MOD;
			}
			//cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}
	}
	ll sum = 0;
	ll ans = 0;
	for (int i = 0; i < n.size(); i++){
		for (int j = 0; j < n[i] - '0'; j++){
			ll nw = sum + j;
			nw %= d;
			nw = d - nw;
			nw %= d;
			ans += dp[n.size() - i - 1][nw];
			ans %= MOD;
			//cout << n.size() - i - 1 << ' ' << nw << ' ' << dp[n.size() - i - 1][nw] << '\n';
		}
		sum += n[i] - '0';
		sum %= d;
	}
	ans --;
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	if (sum % d == 0) ans ++;
	cout << ans % MOD;
 
 
	return 0;
}