#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, s;
	vector<int> a;
	vector<vector<ll> > dp;
	vector<vector<ll> > pre;
	cin>>n>>s;
	
	a.assign(n+1, 0);
	dp.assign(n+1, vector<ll>(s+1, 0));
	pre.assign(n+1, vector<ll>(s+1, 0));

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			if(j==a[i])
				dp[i][j] = i;
			else{
				if(j>=a[i])
					dp[i][j] = pre[i-1][j-a[i]]%998244353;
			}
			pre[i][j] = (pre[i-1][j]+dp[i][j])%998244353;
			//cout<<i<<" "<<j<<" "<<" "<<pre[i-1][j]<<" "<<dp[i][j]<<" "<<pre[i][j]<<"\n";
		}
	}

	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans = (ans+((n-i+1)*dp[i][s])%998244353)%998244353;
	}
	cout<<ans<<"\n";

	return 0;
}