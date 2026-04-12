#include<bits/stdc++.h>
using namespace std;
#define pb push_back 
#define in long long
#define inf INT_MAX

int main()
{
   
in n; cin>>n; in a[n];
for(in i=0;i<n;i++) {cin>>a[i];}
in dp[n][n];

for(in i=n-1;i>=0;i--)
{
    for(in j=i;j<n;j++)
    {
        if(i==j) dp[i][j]=a[i];
        else
        {
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
}
in x=dp[0][n-1];
cout<<x;
return 0;
}
