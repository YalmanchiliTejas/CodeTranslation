#include <bits/stdc++.h>
#define ft first
#define sc second
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


int main() {
  string N;
  cin >> N;
  ll K;
  cin >> K;
  ll dp[111][5][2]={};
  ll i, j, k;
  
  
  dp[0][0][1]=1;
  for(i=0; i<N.size(); i++) {
    for(j=0; j<=K; j++) {
      
      if(N[i]-'0'>0) {
        
        for(k=1; k<N[i]-'0'; k++)
          dp[i+1][j+1][0]+=dp[i][j][1];
        
        dp[i+1][j+1][1]+=dp[i][j][1];
        dp[i+1][j][0]+=dp[i][j][1];
        
        
        for(k=1; k<10; k++)
          dp[i+1][j+1][0]+=dp[i][j][0];
        
        dp[i+1][j][0]+=dp[i][j][0];
        
        
      }else {
        dp[i+1][j][1]+=dp[i][j][1];
        
        for(k=1; k<10; k++)
          dp[i+1][j+1][0]+=dp[i][j][0];
        
        dp[i+1][j][0]+=dp[i][j][0];
      }
    }
  }
  
  
  pt(dp[N.size()][K][1]+dp[N.size()][K][0]);
  
  
}


















