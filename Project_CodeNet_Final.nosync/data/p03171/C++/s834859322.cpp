#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int n, k;
long a[3010];
long dp[3010][3010];
bool done[3010][3010];

long solve(int l, int r, int cnt){
  if(done[l][r]) return dp[l][r];
  done[l][r] = true;
  if(cnt%2==0) return dp[l][r] = max(solve(l+1, r, cnt+1)+a[l], solve(l, r-1, cnt+1)+a[r]);
  return dp[l][r] = min(solve(l+1, r, cnt+1)-a[l], solve(l, r-1, cnt+1)-a[r]);
}

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n){
    rep(j, n){
      dp[i][j] = 0;
      done[i][j] = false;
    }
    dp[i][i] = (2*(n%2)-1) * a[i];
    done[i][i] = true;
  }
  cout << solve(0, n-1, 0) << endl;
}