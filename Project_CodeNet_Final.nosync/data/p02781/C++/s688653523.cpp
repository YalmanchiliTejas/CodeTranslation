#include <bits/stdc++.h>
using namespace std;
int K,i;
long long dp[3][101],ans;
int main(){
  string N;
  cin>>N>>K;
  dp[1][1]=9;
  dp[2][1]=0;
  dp[3][1]=0;
  for(i=2;i<=(int)N.size();i++){
    dp[1][i]=9*i;
    dp[2][i]=81*i*(i-1)/2;
    dp[3][i]=243*i*(i-1)*(i-2)/2;
  }
  if(K==1){cout<<dp[1][(int)N.size()-1]+(N.at(0)-'0')<<endl;}
  if(K==2){
    ans=dp[1][(int)N.size()-1]*(N.at(0)-'0'-1)+dp[2][(int)N.size()-1];
    while((int)N.size()>=2){
      N=N.substr(1);
      if(N.at(0)!='0'){
        ans+=dp[1][(int)N.size()-1]+N.at(0)-'0';
        break;
      }
    }
    cout<<ans<<endl;
  }
  if(K==3){
    ans=dp[3][(int)N.size()-1]+dp[2][(int)N.size()-1]*(N.at(0)-'0'-1);
    while((int)N.size()>=3){
      N=N.substr(1);
      if(N.at(0)!='0'){
        ans+=dp[2][(int)N.size()-1]+dp[1][(int)N.size()-1]*(N.at(0)-'0'-1);
        while((int)N.size()>=2){
          N=N.substr(1);
          if(N.at(0)!='0'){
            ans+=dp[1][(int)N.size()-1]+N.at(0)-'0';
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