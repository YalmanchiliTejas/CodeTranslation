#include<bits/stdc++.h>
using namespace std;
#define  ll long long int
ll dp[3001][3001] ;
ll a[3001];
ll  cs[3001] ;
ll ans( int i,int j)
{
    if(i==j)
    {
      dp[i][j]=a[i];
      return dp[i][j] ;
    }
    if(!dp[i+1][j])
       dp[i+1][j]=ans(i+1,j);

    if(!dp[i][j-1])
       dp[i][j-1]=ans(i,j-1);

       if(dp[i+1][j]<dp[i][j-1])
    dp[i][j]=cs[j]-cs[i-1]-dp[i+1][j];
       else 
    dp[i][j]=cs[j]-cs[i-1]-dp[i][j-1]; 

   // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    return dp[i][j] ;
}


int main() {
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  cin>>a[i];

ll c_s=0;
   for(int i=1;i<=n;i++)
   {  c_s+=a[i] ;
     cs[i]=c_s ;
   }
   
    ans(1,n) ;
   ll x=0;
   ll y=0;
   int i=1;
   int j=n;
   int count=0;
  cout<< 2*dp[i][j]-cs[j]<<endl;
}