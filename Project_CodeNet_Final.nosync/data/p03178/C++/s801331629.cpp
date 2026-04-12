#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)

#define MOD 1000000007

vector<vector<ll>> dp0,dp1;

int main() {
	string K;
	int D;
	cin >> K >> D;
	int len = K.length();
	dp0 = vector<vector<ll>>(len, vector<ll>(D));
	dp1 = vector<vector<ll>>(len, vector<ll>(D));
	int c1 = K[0]-'0';
	rep(j, len) rep(i,D) {
		dp0[j][i%D] = 0;
		dp1[j][i%D] = 0;
	}
	rep(i,c1) dp0[0][i%D] += 1;
	dp1[0][c1%D] += 1;
	for(int i=0; i<len; i++) {
		if(i == 0) continue;
		int c = K[i] - '0';
		rep(j,10) {
			rep(s,D) {
				dp0[i][(s+j)%D] += dp0[i-1][s];
				dp0[i][(s+j)%D] %= MOD;
			}
		}
		rep(j,c) {
			rep(s,D) {
				dp0[i][(s+j)%D] += dp1[i-1][s];
				dp0[i][(s+j)%D] %= MOD;
			}
		}
		rep(s,D) {
			dp1[i][(s+c)%D] += dp1[i-1][s];
			dp1[i][(s+c)%D] %= MOD;
		}
	}
	/*rep(i,len) {
		rep(j,D) cout << setw(3) << dp0[i][j];
		cout << endl;
	}
	rep(i,len) {
		rep(j,D) cout << setw(3) << dp1[i][j];
		cout << endl;
	}*/
	ll ans = 0;
	ans = (ans + dp0[len-1][0]) % MOD;
	ans = (ans + dp1[len-1][0]) % MOD;
	ans--;
	if(ans < 0) ans += MOD;
	cout << ans << endl;


  return 0;
}
