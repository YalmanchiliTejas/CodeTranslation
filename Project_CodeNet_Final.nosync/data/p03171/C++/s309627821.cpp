#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,j,n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(), i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 1e9 + 7;
 
typedef long long i64;
typedef pair<int, int> pi;
 
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
 
i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcm(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vt<int> a(n);
  rep(i, 0, n) cin >> a[i];

  vvt<i64> dp(n + 1, vt<i64>(n + 1));
  rep(i, 0, n) dp[i][i] = 0;

  rep(len, 1, n + 1) {
    rep(i, 0, n - len + 1) {
      int j = i + len;

      if((n - len) % 2 == 0) dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
      else dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
    }
  }

  cout << dp[0][n] << endl;
}