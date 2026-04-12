#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define mod 1000000007
using namespace std;

string s;
int n;
int d;
int dp[10012][2][101];
int solve(int pos,int tight,int sum)
{
   if(pos == n)
   {
    //cout<<kk<<" "<<sum<<endl;

       if(sum == 0){
        return 1;
         }
       else
        return 0;
   }

   if(dp[pos][tight][sum]!= -1)
    return dp[pos][tight][sum];

   int res = 0;

   int ub = (tight)?(s[pos]-'0'):9;
   int newtight;int newsum;

   for(int i = 0;i<=ub;i++)
   {
      if(tight == 1 && i == ub)
        newtight = 1;
      else
        newtight = 0;
      
      newsum = (sum+i)%d;
      res =  (res%mod + solve(pos+1,newtight,newsum))%mod;
   }

   return dp[pos][tight][sum] = res;
}
int main(void)
{
   cin>>s>>d;
   n = s.length();
   //reverse(all(s));
   memset(dp, -1 , sizeof(dp));
   int res = solve(0,1,0);
   res = res-1;
   if(res==-1)
    res+=mod;
  cout<<res<<endl;
}