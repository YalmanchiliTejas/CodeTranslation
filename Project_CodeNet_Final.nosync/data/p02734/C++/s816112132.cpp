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
// const int MOD = 1000000007;
const int MOD = 998244353;

int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n, s;
   cin >> n >> s;
   vector<ll> dp(s + 1);
   ll ans = 0;
   rep(i, 0, n) {
      int a;
      cin >> a;
      dp[0] += 1;
      vector<ll> dp2(s + 1);
      rep(j, 0, s + 1) {
         (dp2[j] += dp[j]) %= MOD;
         if (j + a <= s) (dp2[j + a] += dp[j]) %= MOD;
      }
      dp = dp2;
      (ans += dp[s]) %= MOD;
   }

   cout << ans << endl;
   return 0;
}