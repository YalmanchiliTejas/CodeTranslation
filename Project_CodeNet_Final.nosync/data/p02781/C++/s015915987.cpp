#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int dp[105][2][4];

int main(){
  string s;
  int x;
  cin>>s>>x;
  int n=s.size();
  dp[0][0][0]=1;
  for(int i=0; i<n; ++i){
    int D=s[i]-'0';
    for(int j=0; j<2; ++j){
      for(int k=0; k<=x; ++k){
        for(int d=0; d<=(j?9:D); ++d){
          if(k+(d!=0)>x)continue;
          dp[i+1][j||(d<D)][k+(d!=0)]+=dp[i][j][k];
        }
      }
    }
  }
  cout<<dp[n][0][x]+dp[n][1][x]<<endl;
}