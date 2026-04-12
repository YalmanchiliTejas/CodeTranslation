#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,s;
ll data[3005];
ll dp[3005][3005];
const ll mod=998244353;
int main(){
	//freopen("input.txt","r",stdin);
	cin>>n>>s;
	for(ll i=1;i<=n;i++) cin>>data[i];
	dp[0][0]=1;
	for(ll i=1;i<=n;i++) for(ll j=0;j<=s;j++)
	{
		dp[i][j]=dp[i-1][j];
		if(j-data[i]>=0) dp[i][j]+=dp[i-1][j-data[i]];
		if(j==0) dp[i][j]++;  //因为当j-data[i]==0时，a[i]这一个也要算上 
		dp[i][j]%=mod;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++) ans=(ans+dp[i][s])%mod;
	cout<<ans%mod<<endl;
	return 0;
}