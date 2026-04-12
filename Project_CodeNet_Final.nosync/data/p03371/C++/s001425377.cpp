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

int main() {
   int A, B, C, X, Y;
   cin >> A >> B >> C >> X >> Y;
   int ans = INF;
   for (int i = max(X, Y); i >= 0; i--) {
      int cost = C * i * 2;
      if (X - i > 0) cost += (X - i) * A;

      if (Y - i > 0) cost += (Y - i) * B;
      ans = min(ans, cost);
   }
   cout << ans << endl;
   return 0;
}