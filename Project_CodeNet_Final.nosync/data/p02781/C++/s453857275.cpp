#include <bits/stdc++.h>
using namespace std;
int main(){
  string N;
  int K;
  cin>>N>>K;
  long long dp[100][1000];
  dp[1][1]=9;
  dp[2][1]=0;
  dp[3][1]=0;
  for(int i=2;i<=(int)N.size();i++){
    dp[1][i]=9*i;
    dp[2][i]=9*dp[1][i-1]+dp[2][i-1];
    dp[3][i]=9*dp[2][i-1]+dp[3][i-1];
    //cout<<dp[1][i]<<" "<<dp[2][i]<<" "<<dp[3][i]<<" "<<dp[1][i]+dp[2][i]+dp[3][i]<<endl;
  }
  if(K==1){cout<<dp[1][(int)N.size()-1]+(N.at(0)-'0')<<endl;}
  if(K==2){
    long long ans=dp[1][(int)N.size()-1]*(N.at(0)-'0'-1)+dp[2][(int)N.size()-1];
    while((int)N.size()>=2){
      N=N.substr(1);
      if(N.at(0)!='0'){
        ans+=dp[1][(int)N.size()-1];
        ans+=N.at(0)-'0';
        break;
      }
    }
    cout<<ans<<endl;
  }
  if(K==3){
    long long ans=dp[3][(int)N.size()-1]+dp[2][(int)N.size()-1]*(N.at(0)-'0'-1);
    while((int)N.size()>=3){
      N=N.substr(1);
      if(N.at(0)!='0'){
        ans+=dp[2][(int)N.size()-1];
        ans+=dp[1][(int)N.size()-1]*(N.at(0)-'0'-1);
        while((int)N.size()>=2){
          N=N.substr(1);
          if(N.at(0)!='0'){
            ans+=dp[1][(int)N.size()-1];
            ans+=N.at(0)-'0';
            if(ans!=0){
              cout<<ans<<endl;
              return 0;
            }
          }
          cout<<ans<<endl;
          return 0;
        }
      }
    }
  }
}