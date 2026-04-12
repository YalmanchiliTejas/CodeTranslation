#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int main(){
  string s;cin>>s;
  int k;cin>>k;
  vector< vector<int> > dp(k,vector<int>(2,0));
  dp[0][1] = 1;
  
  for(int i=0;i<s.length();++i){
    vector< vector<int> > currDP(k,vector<int>(2,0));
    for(int m=0;m<k;++m){ 
      for(int n=0;n<2;++n){
      // n == 1 equal 
      // n == 0 smaller
        for(int j=0;j<10;++j){
          if(j>(s[i]-'0') && (n==1)){
            break;
          }
          currDP[(m+j)%k][n&&j==(s[i]-'0')] += dp[m][n];
          currDP[(m+j)%k][n&&j==(s[i]-'0')] %= mod;
        }      
      }
    }
    dp = currDP;
  }
  
  int result = (dp[0][0]+dp[0][1])%mod;
  result--;
  
  if (result < 0){
    result = mod -1;
  }
  
  cout<<result<<endl;
  
  return 0;
}