#include<bits/stdc++.h>
#define m 1000000007
typedef long long ll;
using namespace std;

ll dp[3001][3001][2];

ll f(int i, int j, ll *a)
{
 if(i==j)
 {
     return a[i];
 }
 if(dp[i][j][1]!=-1)
 {
     return dp[i][j][0];
 }
    dp[i][j][0]=max((a[i]-f(i+1, j, a)), (a[j]-f(i, j-1, a)));
    dp[i][j][1]=0;
    return dp[i][j][0];
}

int main()
{
   memset(dp, -1, sizeof(dp));
   int n;
   cin>>n;
   ll a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   cout<<f(0, n-1, a)<<endl;
   return 0;
}

