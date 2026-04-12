#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)

ll dp0[110][5], dp1[110][5];

int main() {
	string s;
	cin >> s;
	int K;
	cin >> K;
	int t = s.length();
	int q = s[0] - '0';
	dp0[1][0] = 1; // 0xxx..
	dp0[1][1] = (s[0] - '0') - 1; //1~s[x]-1xxxx..
	dp1[1][0] = 0;
	dp1[1][1] = 1; //s[0]xxx...
	for(int i=2; i<4; i++) {
		dp0[1][i] = 0;
		dp1[1][i] = 0;
	}
	for(int i=1; i<=t-1; i++) {
		int p = s[i] - '0';
		rep(j, K+1) {
			dp0[i+1][j] += dp0[i][j];
			dp0[i+1][j+1] += dp0[i][j] * 9;
			if(p != 0) {
				dp0[i+1][j+1] += dp1[i][j] * (p-1);
				dp0[i+1][j] += dp1[i][j];
				dp1[i+1][j+1] += dp1[i][j];
			}
			if(p == 0) {
				dp1[i+1][j] += dp1[i][j];
			}
		}
	}
	/*rep(i,t+1) {
		rep(j, K+1) cout << dp0[i][j] << " ";
		cout << endl;
	}
	rep(i,t+1) {
		rep(j, K+1) cout << dp1[i][j] << " ";
		cout << endl;
	}*/
	ll ans = dp0[t][K] + dp1[t][K];
	cout << ans << endl;
  return 0;
}
