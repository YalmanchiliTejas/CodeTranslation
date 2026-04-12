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
ll a[maxn],dp[maxn],f[maxn];
int main()
{
	io();
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	ll ans=0; 
	for(int i=1;i<=n;i++)
	{
		dp[0]+=1;
		for(int j=k;j>=a[i];j--)
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		ans=(ans+dp[k])%mod;
	}
	cout<<ans<<endl;
	return 0;
}