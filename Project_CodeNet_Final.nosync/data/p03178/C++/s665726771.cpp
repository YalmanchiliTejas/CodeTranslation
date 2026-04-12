#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<int>n;
long long dp[10009][2][109];

int main(){
  string s;
  int d;
  cin>>s>>d;

  int l=s.size();
  for(int i=0;i<l;i++){
    n.push_back(s[i]-'0');
  }

  dp[0][0][0]=1;
  for(int i=0;i<l;i++){
    for(int smaller=0;smaller<2;smaller++){
      for(int j=0;j<d;j++){
        for(int x=0;x<=(smaller?9:n[i]);x++){
          dp[i+1][smaller||x<n[i]][(j+x)%d] += dp[i][smaller][j];
          dp[i+1][smaller||x<n[i]][(j+x)%d] %= mod;
        }
      }
    }
  }

  cout<<(dp[l][0][0]+dp[l][1][0]-1+mod)%mod<<endl;

  return(0);
}
