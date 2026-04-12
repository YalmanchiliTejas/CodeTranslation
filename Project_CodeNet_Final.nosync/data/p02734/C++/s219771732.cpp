#include <iostream> 
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep2(i,a,b) for(int i=a;i>=b;i--)
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define ll long long
#define pb push_back
int a[3005];
ll dp[3005];
const ll mod=998244353;
ll ad(ll a,ll b)
{
	return ((a%mod)+(b%mod))%mod;
}
ll ap(ll a,ll b)
{
	return ((a%mod)*(b%mod))%mod;
}
int main(int argc, char** argv) {
	int n,s;
	cin>>n>>s;
	rep(i,1,n)
	{
		scanf("%d",&a[i]); 
	}
	ll ans=0;
	rep(i,1,n)
	{
		if(s<a[i])continue;
		if(s==a[i])ans=ad(ans,ap(i,n-i+1));
		if(dp[s-a[i]])
		ans=ad(ans,ap((dp[s-a[i]]),(n-i+1)));
	//	cout<<s-a[i]<<" "<<dp[s-a[i]]<<" "<<i<<endl;
		rep2(j,s,1)
		{
			if(j+a[i]>s)continue;
			dp[j+a[i]]=ad(dp[j+a[i]],dp[j]);
		}
		dp[a[i]]=ad(dp[a[i]],i);
	
		
	}
	cout<<ans;
	
	return 0;
}