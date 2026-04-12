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

int dp[105][4][2];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   string s;
   int K;
   cin >> s >> K;
   int n = s.size();
   dp[0][0][0] = 1;
   rep(i, 0, n) rep(j, 0, 4) rep(k, 0, 2) {
      int nd = s[i] - '0';
      rep(d, 0, 10) {
         int ni = i + 1, nj = j, nk = k;
         if (d != 0) nj++;
         if (nj > K) continue;
         if (k == 0) {
            if (d > nd) continue;
            if (d < nd) nk = 1;
         }
         dp[ni][nj][nk] += dp[i][j][k];
      }
   }
   cout << dp[n][K][0] + dp[n][K][1] << endl;
   return 0;
}