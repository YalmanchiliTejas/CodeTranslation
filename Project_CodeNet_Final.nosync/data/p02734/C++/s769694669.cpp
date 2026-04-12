//love yjl forever
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int INF=0x3f3f3f3f,N=3000+5;
const ll mo=998244353;
ll n,s;
ll a[N];
ll dp[N];
ll ans;
int main()
{
/*	freopen("","r",stdin);
	freopen("","w",stdout);*/
	int i;
	cin>>n>>s;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	
//	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]>s) continue;		
		if(a[i]==s)
			ans=(ans+(n-i+1)*i%mo)%mo;
		else 
			ans=(ans+dp[s-a[i]]*(n-i+1)%mo)%mo;
		

			
		for(int j=s;j>0;j--)
		{
			if(j+a[i]<s)
				dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mo;
		}
		if(a[i]<s)
			dp[a[i]]=(dp[a[i]]+i)%mo;

	}
	cout<<ans<<endl;
}