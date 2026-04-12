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

int a[3005];
ll dp[3005][3005];
bool fg[3005][3005];
int n;
ll dfs(int l, int r) {
   if (r - l == 0) return 0;

   if (fg[l][r]) return dp[l][r];
   fg[l][r] = true;
   return dp[l][r] = max(a[l] - dfs(l + 1, r), a[r - 1] - dfs(l, r - 1));
}
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n;
   cin >> n;
   rep(i, 0, n) cin >> a[i];
   ll ans = dfs(0, n);
   cout << ans << endl;
   return 0;
}