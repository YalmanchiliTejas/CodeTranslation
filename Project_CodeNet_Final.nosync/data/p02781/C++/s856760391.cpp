#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }
void debug_out() { cout << "\n"; }
template <class T, class... Args>
void debug_out(const T &x, const Args &... args) { cout << x << " "; debug_out(args...);}
#ifdef _DEBUG
  #define debug(...) debug_out(__VA_ARGS__)
#else
  #define debug(...) 
#endif

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  string str;
  int k;
  cin >> str >> k;
  int n = str.length();
  vector<vector<vector<ll> > > dp(n+5, vector<vector<ll> >(2, vector<ll>(k+5,0)));
  dp[0][0][0] = 1;
  rep(i,n) {
    rep(j,k+1) { //0以外の個数
      dp[i+1][1][j+1] += dp[i][1][j]*9; //0以外
      dp[i+1][1][j] += dp[i][1][j]; //0

      int x = str[i]-'0';
      if (x > 0) {
       dp[i+1][1][j+1] += dp[i][0][j]*(x-1); //0以外
       dp[i+1][1][j] += dp[i][0][j]; //0
      }

      if (x == 0) dp[i+1][0][j] += dp[i][0][j]; //0をつける
      else dp[i+1][0][j+1] += dp[i][0][j]; //0以外がつく
    }
  }
  cout << dp[n][1][k] + dp[n][0][k] << endl;
  return 0;
}