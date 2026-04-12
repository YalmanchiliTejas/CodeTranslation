#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

const static ll MOD = 1000000007;
string K;
ll D;
ll dp[10005][2][2][105];

ll solve(int i, int j, int k, int l){
  if(dp[i][j][k][l] >= 0) return dp[i][j][k][l];
  if(i == 0){
    if(j==0){
      ll ret = 0;
      rep(ii,10){
        if(k == 1 && ii == 0) continue;
        if(ii%D == l) ret++;
      }
      return dp[i][j][k][l] = ret;
    } else {
      ll ret = 0;
      rep(ii,(int)(K[K.size()-1-i]-'0')+1){
        if(k == 1 && ii == 0) continue;
        if(ii%D == l) ret++;
      }
      return dp[i][j][k][l] = ret;
    }
  }
  
  if(j == 0){
    ll ret = 0;
    if(k == 1){
      rep(ii,10){
        if(ii == 0) ret += solve(i-1,0,1,(100*D+l-ii)%D);
        else ret += solve(i-1,0,0,(100*D+l-ii)%D);
        ret %= MOD;        
      }
    }else{
      rep(ii,10){
        ret += solve(i-1,0,0,(100*D+l-ii)%D);
        ret %= MOD;        
      }      
    }
    return dp[i][j][k][l] = ret;      
  }else{
    ll ret = 0;
    if(k == 1){
      rep(ii,(int)(K[K.size()-1-i]-'0')+1){
        if(ii == 0){
          if(ii == (int)(K[K.size()-1-i]-'0')) ret += solve(i-1,1,1,(100*D+l-ii)%D);
          else ret += solve(i-1,0,1,(100*D+l-ii)%D);
        }else{
          if(ii == (int)(K[K.size()-1-i]-'0')) ret += solve(i-1,1,0,(100*D+l-ii)%D);
          else ret += solve(i-1,0,0,(100*D+l-ii)%D);
        }
        ret %= MOD;
      }
    }else{
      rep(ii,(int)(K[K.size()-1-i]-'0')+1){
        if(ii == (int)(K[K.size()-1-i]-'0')) ret += solve(i-1,1,0,(100*D+l-ii)%D);
        else ret += solve(i-1,0,0,(100*D+l-ii)%D);
        ret %= MOD;
      }
    }
    return dp[i][j][k][l] = ret;
  }
}

int main(){
  cin >> K;
  cin >> D;

  rep(i,10005) rep(j,2) rep(k,2) rep(l,105) dp[i][j][k][l] = -1;
  
  cout << solve(K.size()-1,1,1,0) << endl;
  
  return 0;
}
