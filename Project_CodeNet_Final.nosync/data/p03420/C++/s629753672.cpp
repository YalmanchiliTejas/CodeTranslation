/*
Author: Snickeen 
Email : ff@snickeen.com
If you find any bug, please tell me.
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL INF = 1e18+7;
const LL MOD = 1e9+7;
const LL MAXN = 1e6+7;

/////**********************************************/////



signed main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	LL i,j,k,n,ans=0;
	cin>>n>>k; 
	if(k!=0)for(i=k+1;i<=n;i++)
		ans+=n/i*(i-k)+max(0ll,n%i-k+1);
	else ans=n*n;
	cout<<ans<<endl;
	return 0;
}