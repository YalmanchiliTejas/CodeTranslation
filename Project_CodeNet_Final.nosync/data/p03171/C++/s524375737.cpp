#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)

ll dp[3010][3010];
ll a[3010];

ll rec(int i, int j, bool b) {
	ll res;
	if(dp[i][j] != -1e18){
		return dp[i][j];
	} 
	else {
		if(b){
			 res = max(rec(i,j-1,false)+a[j], rec(i+1,j,false) + a[i]);
		} 
		else {
			 res = min(rec(i+1,j,true)-a[i], rec(i,j-1,true)-a[j]);
		}
	}
	return dp[i][j] = res;
}

int main() {
	int n;
	cin >> n;
	rep(i,n) {
		cin >> a[i];
	}
	rep(i,n) rep(j,n) dp[i][j] = -1e18;
	rep(i,n) {
		if(n%2==1) dp[i][i] = a[i];
		else dp[i][i] = -1*a[i];
	}
	cout << rec(0,n-1,true) << endl;
	/*rep(i,n) {
		rep(j,n) {
			if(dp[i][j] == -1e18) cout << setw(3) << "NA";
			else cout << setw(3) << dp[i][j];
		}
		cout << endl;
	}*/

  return 0;
}
