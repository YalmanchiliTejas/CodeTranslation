#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, x;
  cin >> n >> x;

  vector<ll> all(51), p(51);
  all[0] = p[0] = 1;
  rep(i, 1, 51) {
    all[i] = all[i - 1] * 2 + 3;
    p[i] = p[i - 1] * 2 + 1;
  }

  ll ans = 0;
  int now = n;
  while (now > 1) {
    //真ん中より左にある場合(真ん中を含む)
    if ((all[now] + 1) / 2 <= x) {
      ans += p[now - 1] + 1;
      // bとpが1個ずつ余分についてるから引いておく
      x -= all[now - 1] + 2;
    } else {
      //真ん中より右にある場合(真ん中は含まない)
      //一番下のbを引いておく
      x--;
    }

    // 1個下の階層のバーガーを調べるためデクリメントする
    now--;
  }

  vector<ll> l1 = {0, 1, 2, 3, 3};
  ans += l1[min(4LL, max(0LL, x - 1))];

  cout << ans << endl;
}
