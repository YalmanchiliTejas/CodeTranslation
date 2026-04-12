#include<bits/stdc++.h>
using namespace std;
int dp[10002][102][2];
int mod=1000000007;
int d;
int get(vector<int>& v,int i,int f,int sum)
{
   if(i==v.size())
   {
     if(sum%d==0)
     return 1;
     else
       return 0;
     
   }
  int& ans=dp[i][sum][f];
  if(dp[i][sum][f]!=-1) return ans;
  ans=0;
  
   int l=(f)? v[i]:9;
    for(int k=0;k<=l;k++)
    {
      int f1=f & (k==l);
      
      ans=((long long)ans+get(v,i+1,f1,(sum+k)%d))%mod;
     
    }
  
    return ans;
  
  
  
}
 
 
int main()
{
  string n;
  cin>>n>>d;
  vector<int> v;
  int i=0;
  while(i<n.size())
  {
    v.push_back(n[i]-'0');
    i++;
   // cout<<v.back()<<" ";
  }
  //reverse(v.begin(),v.end());
  memset(dp,-1,sizeof(dp));
  
  int ans=get(v,0,1,0);
  cout<<((ans-1+mod)%mod); 
  
  
  
  
  
}