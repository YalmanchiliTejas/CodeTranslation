#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)(a).size())
#define rep(i, n) for (int i = 0; i < n; i++)

#ifdef __DEBUG
#define debug if (true)
#else
#define debug if (false)
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T> struct vector2 : public vector<vector<T>> { vector2(int n, int m, const T& k = T()) : vector<vector<T>>(n, vector<T>(m, k)) {} };
template <typename T> struct vector3 : public vector<vector2<T>> { vector3(int n, int m, int k, const T &l = T()) : vector<vector2<T>>(n, vector2<T>(m, k, l)) {} };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  for (int b = k + 1; b <= n; b++) {
    ll mult = n / b;
    ans += mult * (b - k);
    ans += max(0LL, n - (mult * b + k) + 1);
    if (k == 0) {
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}
