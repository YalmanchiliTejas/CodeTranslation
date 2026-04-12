#include<bits/stdc++.h>
using namespace std;
 
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define pfis(a) printf("%d ",a);
#define pfls(a) printf("%lld ",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb(a) push_back(a);
#define mp(a,b) make_pair(a,b)
#define ll long long
 
const ll mod=1e9+7;
 
int main()
{
    int n;
    sfi(n)
 
    ll arr[n+1];
    f(i,1,n+1)
    	sfl(arr[i])
 
    ll dp[n+1][n+1];
 
    memset(dp,0,sizeof(dp));
 
    for(int i=n;i>0;i--)
    {
    	f(j,i,n+1)
    	{
    		if(i==j)
    			dp[i][j]=arr[i];
    		else
    		{
    			dp[i][j]=max((arr[i]-dp[i+1][j]),(arr[j]-dp[i][j-1]));
    		}
    	}
    }
 
    pfln(dp[1][n])
 
    return 0;
}