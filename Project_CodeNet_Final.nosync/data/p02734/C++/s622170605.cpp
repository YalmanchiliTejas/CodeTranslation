#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,n,m) for(int i=n;i<=m;i++)
#define read(n) cin>>n;
#define write(n) cout<<n;
using namespace std;
const int N=3005;
const int Mod=998244353;
int n,m,x[N],sum;
ll ans=00000000;
int dp[9005];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)
	{
		if(x[i]<=m)ans=(ans+1ll*dp[m-x[i]]*(n-i+1)%Mod+1ll*(x[i]==m)*(n-i+1)*i%Mod)%Mod;
		for(int j=m;j>=0;j--)
			dp[j+x[i]]+=dp[j],dp[j+x[i]]%=Mod;//grow
		dp[x[i]]+=i;//add
		dp[x[i]]%=Mod;
	}
	cout<<ans<<"\n";
	return 0;
}