#include<bits/stdc++.h>
#define m 1000000007
typedef long long ll;
using namespace std;

ll dp[3001][3001][2][2];

ll f(int i, int j, ll *a, int turn)
{
 if(i==j)
 {
     if(!turn)
     return a[i];
     else
     {
         return 0;
     }
 }
 if(dp[i][j][turn][1]!=-1)
 {
     return dp[i][j][turn][0];
 }
 if(!turn){
    dp[i][j][turn][0]=max((a[i]+f(i+1, j, a, 1)), (a[j]+f(i, j-1, a, 1)));
    dp[i][j][turn][1]=0;
 }
 else{
    dp[i][j][turn][0]=min((f(i+1, j, a, 0)), (f(i, j-1, a, 0)));
    dp[i][j][turn][1]=0;
 }
    return dp[i][j][turn][0];
}

int main()
{
   memset(dp, -1, sizeof(dp));
   int n;
   cin>>n;
   ll a[n];
   ll ans=0;
   for(int i=0;i<n;i++)
   {cin>>a[i];ans+=a[i];}
   cout<<(2*f(0, n-1, a, 0)-ans)<<endl;
   return 0;
}

