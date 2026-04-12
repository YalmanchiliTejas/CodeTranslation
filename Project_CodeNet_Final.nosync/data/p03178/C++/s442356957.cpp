#include<bits/stdc++.h>
using namespace std;
const int mod= 1000000007;

void add_self(int &a, int b){
      a+=b;
      while(a>mod)
            a-=mod;
}

int main(){
      string s;
      int d;
      cin>>s>>d;
      int len=s.length();
      vector<vector<int>>dp(d, vector<int>(2, 0));

      dp[0][0] = 1;

      for(int where = 0; where < len; where++){
            
            vector<vector<int>>new_dp(d, vector<int>(2, 0));
            
            for(int sum = 0; sum < d; sum++){
                  
                  for(bool sm_already: {false, true}){
                        
                        for(int digit = 0; digit < 10; digit++){
                              
                              if((digit > s[where] - '0') && !sm_already){
                                    break;
                              }
                              //add_self(new_dp[(sum + digit)%d][sm_already || (digit < (s[where] - '0'))], dp[sum][sm_already]);
                              new_dp[(sum + digit)%d][sm_already || (digit < (s[where] - '0'))] = (new_dp[(sum + digit)%d][sm_already || (digit < (s[where] - '0'))] + dp[sum][sm_already])%mod;
                        }
                  }
            }
            dp = new_dp;
      }
      int ans=dp[0][1]+dp[0][0];
      ans--;
      ans%=mod;
      if(ans<0)ans=mod-1;
      cout<<ans;
}