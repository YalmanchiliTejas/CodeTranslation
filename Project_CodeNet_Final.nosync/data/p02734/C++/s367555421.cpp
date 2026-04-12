#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
typedef long long int ll;

ll a[3001]={0};
ll dp[3002][3002][3]={0};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
        
	ll n,s;
	cin>>n>>s;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}

	dp[0][0][0]=1;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<=s;j++){
			(dp[i+1][j][0]+=dp[i][j][0])%=MOD;
			(dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1])%=MOD;
			(dp[i+1][j][2]+=dp[i][j][0]+dp[i][j][1]+dp[i][j][2])%=MOD;
			if(j+a[i]<=s){
				(dp[i+1][j+a[i]][1]+=dp[i][j][0]+dp[i][j][1])%=MOD;
				(dp[i+1][j+a[i]][2]+=dp[i][j][0]+dp[i][j][1])%=MOD;
			}
		}
	}
	cout<<dp[n][s][2]<<endl;

	return 0;
}