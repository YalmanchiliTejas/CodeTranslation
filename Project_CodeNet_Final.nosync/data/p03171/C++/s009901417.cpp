#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
ll n,a[100005],dp[3000][3000]={0};
ll g(int f,int l)
{
	if(dp[f][l]!=-1)
		return dp[f][l];
	if(f==l)
		return dp[f][l]=a[f];
	if(f+1==l)
		return dp[f][l]=max(a[f],a[l]);
	return dp[f][l]=max(a[f]+min(g(f+2,l),g(f+1,l-1)),a[l]+min(g(f,l-2),g(f+1,l-1)));
	
}
int main()
{fast
	cin>>n;
	ll i,sum=0;
	memset(dp,-1,sizeof(dp));
	for(i=0;i<n;i++){cin>>a[i];
	sum+=a[i];
	}
 	ll ans=2*g(0,n-1)-sum;
 	cout<<ans<<endl;
	
}