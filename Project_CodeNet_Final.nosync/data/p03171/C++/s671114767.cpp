#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define endl "\n"
#define pi 3.14159265358979323846264338327950288
#define MOD 1000000007
#define INF -100000000000000
#define ordered_set tree<pair< ll int ,ll  int>, null_type,less<pair<ll int, ll int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define lld long double
using namespace __gnu_pbds;

int main()
{
    fast;ll int n;
    cin>>n;
    ll int a[n];ll int i,k,w,f,j;
    for(i=1;i<=n;i++)
    {	
    	cin>>a[i];
    }
    ll int dp[n+1][n+1];
    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=n;j++)
    		dp[i][j]=0;
    }
    if(n%2==0)
    	f=1;
    else
    	f=0;//     0 for j and 1 for t;
    for(i=1;i<=n;i++)
    {
    	w=i;
    	f=1^f;
    	for(j=1;j<=(n-i+1);j++)
    	{
    		k=j+i-1;
    		if(i==1 && f==0)
    		{
    			dp[j][k]=-1*a[k];
    		}
    		else if(i==1 && f==1)
    			dp[j][k]=a[k];
    		else if(f==0)
    		{
    			dp[j][k]=min(dp[j+1][k]-a[j],dp[j][k-1]-a[k]);
    		}
    		else if(f==1)
    			dp[j][k]=max(a[j]+dp[j+1][k],a[k]+dp[j][k-1]);
    	}
    }
    cout<<dp[1][n]<<endl;
  /*  for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    		cout<<dp[i][j]<<" ";
    	cout<<endl;
    }*/
   
}