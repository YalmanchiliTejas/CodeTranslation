#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
 
using namespace std;

 ll mod=998244353;
 
ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}

int main()
{
    
    // #ifndef ONLINE_JUDGE
    //     freopen ("data.in","r",stdin);
    //     freopen ("E.out","w",stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests=1;
    // cin>>tests;
    while(tests--)
    {
   		ll i,j,n,ans=-9000000000000000;
   		cin>>n;
   		vector<ll>a(n);
   		for(i=0;i<n;i++) cin>>a[i];
   		// if(n%2==0)
   		// {
   		// 	ll cur=0;
   		// 	for(i=0;i<n;i+=2) cur+=a[i];
   		// 	ans=cur;
   		// 	cur=0;
   		// 	for(i=1;i<n;i+=2) cur+=a[i];
   		// 	ans=max(ans,cur);
   		// 	cout<<ans;
   		// 	return 0;
   		// }
   		
   		ll dp[n+5][3]={0};
   		for(i=0;i<=n;i++)
		{dp[i][0]=dp[i][1]=dp[i][2]=-1e15;}
   		dp[1][0]=a[0];
   		dp[2][1]=a[1];
   		dp[3][0]=a[0]+a[2];
   		dp[3][2]=a[2];
   		for(i=4;i<=n;i++)
   		{
   			// without jump
   			dp[i][0]=max(dp[i][0],dp[i-2][0]+a[i-1]);
   			dp[i][1]=max(dp[i][1],dp[i-2][1]+a[i-1]);
   			dp[i][2]=max(dp[i][2],dp[i-2][2]+a[i-1]);
   			// with jump
   			dp[i][1]=max(dp[i][1],dp[i-3][0]+a[i-1]);
   			dp[i][2]=max(dp[i][2],dp[i-3][1]+a[i-1]);
   			dp[i][2]=max(dp[i][2],dp[i-4][0]+a[i-1]);
   		}
   		if(n%2==1)
   		ans=max(dp[n][2],max(dp[n-1][1],dp[n-2][0]));
   		else
   			ans=max(dp[n][1],dp[n-1][0]);

   		cout<<ans;


   	}
    	return 0;
    
}