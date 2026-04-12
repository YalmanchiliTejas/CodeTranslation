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
  int n = s.size();
  int K;
  cin>>K;

  dp[0][0][0] = 1;
  REP(i,n)REP(j,K+1)REP(k,2) {
    int nd = s[i] - '0';
    REP(d,10) {
      int ni=i+1, nj=j, nk=k;
      if(d<nd) nk=1;
      if(k==0) {
        if(nk==0 && d!=nd) continue;
        if(nk==1 && d>=nd) continue;
      }
      if(d) nj++;
      if(nj>K) continue;
      dp[ni][nj][nk] += dp[i][j][k];
      // printf("d:%d, dp[%d][%d][%d]: %d -> dp[%d][%d][%d]: %d, nd:%d\n",d,i,j,k,dp[i][j][k],ni,nj,nk,dp[ni][nj][nk],nd);
    }
    // printf("\n");
  }

  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;

  return 0;
}
