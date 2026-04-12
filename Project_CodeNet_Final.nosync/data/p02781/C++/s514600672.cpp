#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int, int>;
const ll mod = 1e9+7;

int dp[101][4][2];

int main(int argc, char const* argv[])
{
  string s;
  cin>>s;
  int K;
  cin>>K;

  int n = s.size();

  dp[0][0][0] = 1;
  REP(i,n)REP(j,K+1)REP(k,2) {
    int ni=i+1, nj=j, nk=k;
    int nd = s[i]-'0';
    // printf("nd: %d\n", nd);
    REP(d,10) {
      nj=j, nk=k;
      if(d!=0) nj++;
      if(nj>K) continue;
      if(k==0 && d<nd) nk=1;
      if(k==0 && d>nd) continue;
      dp[ni][nj][nk] += dp[i][j][k];
      // printf("d:%d, dp[%d][%d][%d]: %d -> dp[%d][%d][%d]: %d\n", d,i,j,k,dp[i][j][k],ni,nj,nk,dp[ni][nj][nk]);
    }
  }

  int ans = dp[n][K][0] + dp[n][K][1];
  printf("%d\n", ans);

  return 0;
}