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

const ll mod = 1000000007;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int d;
  string str;
  cin >> str >> d;
  int n = str.size();
  vector<vector< vector<ll> > > dp(n+5, vector<vector<ll> >(2, vector<ll>(d+5, 0)));
  dp[0][0][0] = 1;
  rep(i,n) {
    rep(j,d) {
      rep(k,10) { //i桁目がN未満 -> i+1がN未満
        dp[i+1][1][(j+k) % d] += dp[i][1][j];
        dp[i+1][1][(j+k) % d] %= mod;
      }
      int x = str[i]-'0';
      rep(k,x) { //i桁目がNと同じ -> i+1がN未満
        dp[i+1][1][(j+k) % d] += dp[i][0][j];
        dp[i+1][1][(j+k) % d] %= mod;
      }
      //i桁目がNと同じ -> i+1がNと同じ
      dp[i+1][0][(j+x) % d] = dp[i][0][j];
      dp[i+1][0][(j+x) % d] %= mod;
    }
  }
  cout << (dp[n][1][0] + dp[n][0][0] - 1 + mod) % mod << endl;
  return 0;
}