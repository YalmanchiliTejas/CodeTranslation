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
const int INF = 2e9;
const int MOD = 1e9 + 7;

ll dp[3005][3005], color[3005][3005];
int a[3005];
ll f(int n, int l, int r) {
   if (color[l][r]) return dp[l][r];
   color[l][r] = 1;
   if (l == r) return dp[l][r] = a[l];
   if (n % 2)
      dp[l][r] = min(a[l] - f(n + 1, l + 1, r), a[r] - f(n + 1, l, r - 1));
   return dp[l][r] = max(a[l] - f(n + 1, l + 1, r), a[r] - f(n + 1, l, r - 1));
}
int main() {
   int n;
   cin >> n;
   rep(i, 0, n) cin >> a[i];
   ll ans = f(0, 0, n - 1);
   cout << ans << endl;
   return 0;
}