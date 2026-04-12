#include <bits/stdc++.h>
using namespace std;
int n,k;
long dp[3001][3001];
long a[3001];


long solve(int i, int j, int p)
{  
    if(i==j) return p*a[i];
    else if(dp[i][j]) return dp[i][j];
    if(p==1)
    dp[i][j]=max(p*a[i]+solve(i+1,j,-1*p), p*a[j]+solve(i,j-1,-1*p));
    else 
    dp[i][j]=min(p*a[i]+solve(i+1,j,-1*p), p*a[j]+solve(i,j-1,-1*p));
    return dp[i][j];
}
 
int main()
{   cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];;
    }
    cout<<solve(1,n,1);
}