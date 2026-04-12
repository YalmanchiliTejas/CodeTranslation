#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{  	ios_base::sync_with_stdio(false); cin.tie(0);
    int n,a,temp;cin>>n;
    ll sum=0,dp[n+1][n+1]={},arr[n+1]={};
    for(int i=1;i<=n;i++){ cin>>arr[i]; sum+=arr[i]; }
    a=(1+n)%2;
    for(int i=n;i>=0;i--)
    { for(int j=i;j<=n;j++)
          { if((i+j)%2==a) { temp=1; } else { temp=0; }
            if(temp==1) {  if(i==j) { dp[i][j]=arr[i]; } else { dp[i][j]=max(arr[i]+dp[i+1][j],arr[j]+dp[i][j-1]); } }
       else if(temp==0) {  if(i==j) { dp[i][j]   =  0; } else { dp[i][j]=min(   dp[i+1][j]    ,  dp[i][j-1]     ); } }
          }
    }
    cout<<2*dp[1][n]-sum;
return 0;
}
