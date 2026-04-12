#include <bits/stdc++.h>
#include <string>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/




int main(void) {
  ll i, j, k;
  string L;
  ll K;
  cin >> L >> K;
  ll N=L.size();
  
  ll dp[111][5][2]={};
  
  dp[0][0][1]=1;
  for(i=0; i<N; i++) {
    for(j=0; j<=K; j++) {
      
      for(k=0; k<10; k++) {
        dp[i+1][j+(k!=0)][0]+=dp[i][j][0];
      }
      
      ll MX=L[i]-'0';
      for(k=0; k<MX; k++) {
        dp[i+1][j+(k!=0)][0]+=dp[i][j][1];
      }
      
      dp[i+1][j+(MX!=0)][1]+=dp[i][j][1];
    }
  }
  
  pt(dp[N][K][0]+dp[N][K][1]);
  
}

