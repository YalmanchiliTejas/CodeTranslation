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

int dp[105][4][2];
int main() {
   string N;
   int K;
   cin >> N >> K;
   int n = N.size();
   dp[0][0][0] = 1;
   rep(i, 0, n) rep(j, 0, 4) rep(sm, 0, 2) {
      rep(d, 0, 10) {
         int ni = i + 1, nj = j, nsm = sm;
         if (d != 0) nj++;
         if (nj > K) continue;
         if (nsm == 0) {
            if (d > N[i] - '0') continue;
            if (d < N[i] - '0') nsm = 1;
         }
         dp[ni][nj][nsm] += dp[i][j][sm];
      }
   }
   cout << dp[n][K][1] + dp[n][K][0] << endl;
   return 0;
}