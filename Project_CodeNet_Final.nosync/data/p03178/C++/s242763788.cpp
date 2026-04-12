#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int mod=1e9+7;

int main(){
  string k;
  cin>>k;
  int d;
  cin>>d;
  vector<vector<long>> dp(d, vector<long>(2));
  dp[0][0]=1;
  for(int i=0;i<k.size();i++)
  {
    vector<vector<long>> newdp(d, vector<long>(2));
    for(int sum=0;sum<d;sum++)
    {
      for(bool sm_already : {false,true})
      {
        for(int digit=0;digit<10;digit++)
        {
          if(digit>k[i]-'0'&&!sm_already)
            break;
          newdp[(sum+digit)%d][sm_already or digit<k[i]-'0']+=dp[sum][sm_already];
          newdp[(sum+digit)%d][sm_already or digit<k[i]-'0']%=mod;
        }
      }
    }
    dp=newdp;
  }
  long ans=(dp[0][false]+dp[0][true])%mod;
  ans--;
  if(ans==-1)
	ans=mod-1;
  cout<<ans;
  
}