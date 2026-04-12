#include<bits//stdc++.h>
#define mod 1000000007
using namespace std;

long int rec(vector<vector<long int> >&dp,vector<long int>&a,int st,int en)
{
   if(st>en)
   return 0;
   if(dp[st][en])
   return dp[st][en];
   long int x=rec(dp,a,st+2,en);
   if(x>rec(dp,a,st+1,en-1))
   x=rec(dp,a,st+1,en-1);
   x+=a[st];
   long int y=rec(dp,a,st+1,en-1);
   if(y>rec(dp,a,st,en-2))
   y=rec(dp,a,st,en-2);
   y+=a[en];
   if(x>y)
   dp[st][en]=x;
   else
   dp[st][en]=y;
   return dp[st][en];
}
int main()
{
  int n;
  cin>>n; 
  vector<long int>a(n,0);
  long int sum=0;
  for(int i=0;i<n;i++)
  {cin>>a[i];sum+=a[i];}

  vector<long int>tmp(n,0);
  vector<vector<long int> >dp(n,tmp);
  for(int i=0;i<n;i++)
  dp[i][i]=a[i];
  
  long int ans=rec(dp,a,0,n-1);
  cout<<(2*ans-sum)<<endl;
}