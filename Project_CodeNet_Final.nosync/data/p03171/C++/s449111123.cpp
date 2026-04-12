#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL);
#define MOD 1000000007

ll dp[3005][3005];
ll a[3005];

int main() 
{  
	int n,i,j;
    cin>>n;

    for(i=0;i<n;i++)
    	cin>>a[i];
    
    for(i=n-1;i>=0;i--)
    {
    	for(j=i;j<n;j++)
    	{
    		if(i==j)
    			dp[i][j]=a[i];
    		else
    		    dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
    	}
    }
   /* 
    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=k;j++)
    		cout<<dp[i][j]<<" ";
    	    cout<<"\n";
    	}
    */		
    cout<<dp[0][n-1]<<"\n";
 	return 0;
}