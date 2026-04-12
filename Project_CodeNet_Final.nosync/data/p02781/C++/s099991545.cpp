#include<bits/stdc++.h>
using namespace std;
vector<int>n;
int dp[109][9][9];

int main(){
  string s;
  int m;
  cin>>s>>m;
  int len=s.size();
  for(int i=0;i<len;i++){
    n.push_back(s[i]-'0');
  }
  dp[0][0][0]=1;

  for(int i=0;i<len;i++){
    for(int smaller=0;smaller<2;smaller++){
      for(int j=0;j<=m;j++){
        for(int x=0;x<=(smaller?9:n[i]);x++){
          dp[i+1][smaller||x<n[i]][j+(x!=0)] += dp[i][smaller][j];
        }
      }
    }
  }

  cout<<dp[len][0][m]+dp[len][1][m]<<endl;

  return(0);
}
