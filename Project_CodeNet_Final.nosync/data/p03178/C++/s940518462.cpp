//Om Sree Sai Ram
#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9+7;

void add_self(int&a,int b)
{
  a+=b;
  if(a>=mod)
  {
    a-=mod;
  }
}


int main() 
{


string k;
int D;
cin>>k;
cin>>D;
int n = k.length();
vector<vector<int>>dp(D,vector<int>(2));
//dp[i][bool] i represents the current sum%D we are at. 
// we have two states, we may have already choosen smaller number or
// not choosen that is represented by bool flag

dp[0][0] = 1;
//dp[0][1] = 0; because we cannot get into the state with choosing any
//digit
//int sum =0;
for(int i=0;i<n;i++)
{
  vector<vector<int>> new_dp(D,vector<int>(2));
  for(int sum=0;sum<D;sum++)
  {
  //cout<<" i = "<<i<<endl;
  int curr = k[i]-'0';
  for(auto fl:{false,true})
      {
     for(int a=0;a<=9;a++)
        {
        if(!fl && a>(curr))
        {
          break;
        }
        else
        {
          add_self(new_dp[(sum+a)%D][fl||(a<curr)],dp[sum][fl]);
        }
      }
    }
  }
  dp = new_dp;
} 
add_self(dp[0][0],dp[0][1]);
int ans = dp[0][0];
//always 0 is trivial case. we need to discard it.
ans--;
if(ans==-1)
{
  ans = mod-1;
}
cout<<ans<<endl;
return 0;
}
