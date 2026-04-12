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

int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int a, b, c;
   cin >> a >> b >> c;
   int x, y;
   cin >> x >> y;
   int ans = 1e9 + 1;
   for (int i = 0; i <= 2 * max(x, y); i += 2) {
      int sum = a * max(0, (x - i / 2));
      sum += b * max(0, (y - i / 2));
      sum += c * i;
      chmin(ans, sum);
   }
   cout << ans << endl;
   return 0;
}