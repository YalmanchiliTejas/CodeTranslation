#include <bits/stdc++.h>
using namespace std;

typedef long long int in; 

in dp[3005][3005];

int main() 
{
    in n;
    cin>>n;
    
    in a[n],i,j,k=0;
    
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        dp[i][i]=a[i];
    }
    
    for(i=0;i<n;++i)
    {
        ++k;
        for(j=0;j<n;++j)
        if(j+k<n)
        dp[j][j+k]=max(a[j]-dp[j+1][j+k],a[j+k]-dp[j][j+k-1]);
    }
    
    cout<<dp[0][n-1];
    
	return 0;
}
