#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<sstream>
using namespace std;
typedef long long ll;
const ll maxn=1e4+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
void io(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
ll a[maxn],dp[maxn],f[3100][3100];
int main()
{
	io();
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	ll ans=0;
//	dp[0]=1; 
//	for(int i=1;i<=n;i++)
//	{
//		dp[0]+=1;
//		for(int j=k;j>=a[i];j--)
//			dp[j]=(dp[j]+dp[j-a[i]])%mod;
//		for(int m=0;m<=k;m++)
//			cout<<dp[m]<<" ";
//		cout<<endl;
//		ans=(ans+dp[k])%mod;
//	}
//	cout<<ans<<endl;
//	cout<<endl<<endl;
	ans=0;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=(f[i-1][0]+1);
		for(int j=1;j<=k;j++)
		{
			if(j<a[i])
				f[i][j]=f[i-1][j]%mod;
			else
				f[i][j]=(f[i-1][j]+f[i-1][j-a[i]])%mod;
		}
//		for(int m=0;m<=k;m++)
//			cout<<f[i][m]<<" ";
//		cout<<endl;
		ans=(ans+f[i][k])%mod;
	}
	cout<<ans<<endl;
	return 0;
}