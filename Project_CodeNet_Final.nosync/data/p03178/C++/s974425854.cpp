  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  #include <utility>
  #include <map>
  using namespace std;
  typedef long long ll;
  #define rep(i,n) for (int i=0;i < (int)(n);i++)

  ll dp[10001][101][2];
  const ll mod = 1e9+7;

  int main(){
    string s;
    cin >> s;
    int n = s.size();
    int D;
    cin >> D;

    dp[0][0][0] = 1;
    rep(i,n) rep(j,D) rep(k,2){
      ll nd = s[i]-'0';
      rep(d,10){
        int ni = i+1,nj = (j + d)%D,nk = k;
        if (k == 0){
          if (d > nd) continue;
          if (d < nd) nk = 1;
        }
        dp[ni][nj][nk] += dp[i][j][k];
        dp[ni][nj][nk] %= mod;
      }
    }
    int ans = dp[n][0][0] + dp[n][0][1];
    ans -= 1;
    if (ans < 0) ans += mod;
    cout << ans << endl;

    return 0;
  }
