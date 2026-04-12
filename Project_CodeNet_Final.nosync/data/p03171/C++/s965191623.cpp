#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
typedef long long int ll;
using namespace std;

ll n;
ll a[3005];
ll dp[3005][3005];

ll go(ll s,ll e)
{
	if (s>e)
	return 0;
	if (s==e)
	return a[s];
	else if (dp[s][e]!=-1)
	return dp[s][e];
	else
	{
		ll x;
		x=max(a[s]-go(s+1,e),a[e]-go(s,e-1));
		dp[s][e]=x;
		return x;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for (int i=1;i<=n;i++)
    cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<go(1,n)<<endl;

}
