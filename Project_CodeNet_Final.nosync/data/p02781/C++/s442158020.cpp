#include <bits/stdc++.h>
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



int main(void) {
  ll i, j, k;
  string L;
  ll K;
  cin >> L;
  cin >> K;
  ll N=(ll)L.size();
  ll dp[111][5][2]={};
  
  
  dp[0][0][1]=1;
  
  //例 L=18037
  for(i=0; i<N; i++) {
    for(j=0; j<=K; j++) {
      ll LIM=L[i]-'0';
      
      //18'?'(i=2)
      if(LIM==0) {

        //18'0'
        dp[i+1][j][1]+=dp[i][j][1];
        
        
        //17'0'
        dp[i+1][j][0]+=dp[i][j][0];
        
        //17'k'(k=1~9)
        for(k=1; k<10; k++)
          dp[i+1][j+1][0]+=dp[i][j][0];
        
      }
      //1803'?'(i=4)
      else {
        
        //1803'0'
        dp[i+1][j][0]+=dp[i][j][1];
        
        //1803'k'(k=1~6)
        for(k=1; k<LIM; k++)
          dp[i+1][j+1][0]+=dp[i][j][1];
        
        //1803'7'
        dp[i+1][j+1][1]+=dp[i][j][1];
        
        
        //1752'0'
        dp[i+1][j][0]+=dp[i][j][0];
        
        //1752'k'(k=1~9)
        for(k=1; k<10; k++)
          dp[i+1][j+1][0]+=dp[i][j][0];
        
      }
      
    }
  }
  
  pt(dp[N][K][0]+dp[N][K][1]);
  
}



