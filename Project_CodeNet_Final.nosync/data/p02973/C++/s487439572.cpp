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

   int n;
   cin >> n;
   vector<int> a(n);
   rep(i, 0, n) cin >> a[i];
   deque<int> d;
   rep(i, 0, n) {
      int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
      if (p == 0) {
         d.push_front(a[i]);
      } else {
         d[p - 1] = a[i];
      }
   }
   int ans = d.size();
   cout << ans << endl;
   return 0;
}