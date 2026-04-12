#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
int h[110],lb[110],rb[110],in[110];
ll dp[110][110];
int n;
vector<int> lsh;
inline ll quickpow(ll base,int ind)
{
	ll ans=1;
	while(ind>0)
	{
		if(ind&1)ans=ans*base%MOD;
		ind>>=1;
		base=base*base%MOD;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&h[i]);
		lsh.push_back(h[i]);
	}
	lsh.push_back(1);
	sort(lsh.begin(),lsh.end());
	lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
	int m=lsh.size();
	for(int i=0;i<m;i++)
	{
		rb[i]=lsh[i];
		if(i)lb[i]=rb[i-1]+1;
		else lb[i]=1;
	}
	lb[m]=rb[m-1]+1;
	rb[m]=inf;
	for(int i=0;i<n;i++)
	{
		in[i]=lower_bound(lsh.begin(),lsh.end(),h[i])-lsh.begin();
//		cout<<i<<" "<<in[i]<<endl;
	}
//	system("pause");
	for(int i=1;i<=in[0]+1;i++)
	{
		int lowest=lb[i],higest=min(rb[i],h[0]);
//		cout<<"l "<<lowest<<" "<<higest<<endl;
		if(lowest<=higest)
			dp[0][i]=2ll*(quickpow(2,h[0]-lowest+1)-quickpow(2,h[0]-higest)+MOD)%MOD;
		else dp[0][i]=2;
//		cout<<i<<" "<<dp[0][i]<<endl;
	}
//	system("pause");
	for(int i=0;i+1<n;i++)
	{
		if(h[i]>=h[i+1])
		{
			for(int j=1;j<=in[i]+1;j++)
			{
				if(j<=in[i+1])
				{
					dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
				}
				else
				{
					dp[i+1][in[i+1]+1]=(dp[i+1][in[i+1]+1]+dp[i][j]*2ll)%MOD;
				}
			}
		}
		else
		{
			int ind=h[i+1]-h[i];
			for(int j=1;j<=in[i];j++)
			{
				dp[i+1][j]=(dp[i+1][j]+dp[i][j]*quickpow(2,ind)%MOD)%MOD;
			}
			for(int j=in[i]+1;j<=in[i+1]+1;j++)
			{
				int lowest=lb[j],higest=min(h[i+1],rb[j]);
	//			cout<<j<<" "<<lowest<<" "<<higest<<" "<<lb[j]<<" "<<rb[j]<<" "<<h[i+1]<<" "<<in[i+1]<<endl;
				if(lowest<=higest)
				{
					dp[i+1][j]=(dp[i+1][j]+
					dp[i][in[i]+1]*2ll%MOD*(quickpow(2,h[i+1]-lowest+1)-quickpow(2,h[i+1]-higest)+MOD)%MOD)%MOD;
				}
				else
				{
					dp[i+1][j]=(dp[i+1][j]+dp[i][in[i]+1]*2ll)%MOD;
				}
			}
		}
		
	//	for(int j=1;j<=in[i+1]+1;j++)
	//		cout<<j<<" "<<dp[i+1][j]<<endl;
	//	system("pause");
	}
	ll ans=0;
	for(int i=1;i<=in[n-1]+1;i++)
		ans=(ans+dp[n-1][i])%MOD;
	printf("%lld\n",ans);
	return 0;
}