#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
void hr() {
   cerr << "--------------" << endl;
}
const int INF = 1001001001;
const int MOD = 1000000007;
// const int MOD = 998244353;

ll dp[3005][3005];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n;
   cin >> n;
   vector<int> a(n);
   rep(i, 0, n) cin >> a[i];

   rep(len, 1, n + 1) for (int i = 0; i + len <= n; i++) {
      int j = i + len;
      if ((n - len) % 2) {
         dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
      } else {
         dp[i][j] = max(a[i] + dp[i + 1][j], dp[i][j - 1] + a[j - 1]);
      }
   }
   cout << dp[0][n] << endl;
   return 0;
}