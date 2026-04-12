#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;cin>>n;
    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    std::vector<std::vector<ll> > dp(n+1,std::vector<ll>(n));
    for (int i = 0; i <n; ++i)
    {
    	dp[1][i]=a[i];
    }
    for (int i = 2; i <=n; ++i)
    {
    	for (int j = 0; j <=(n-i) ; ++j)
    	{
    		dp[i][j]=max(a[j]-dp[i-1][j+1],a[j+i-1]-dp[i-1][j]);
    	}
    }
    cout<<dp[n][0]<<"\n";
    
}
