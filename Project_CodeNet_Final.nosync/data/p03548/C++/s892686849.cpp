#include <bits/stdc++.h>
using namespace std;

using LL = long long;

#define ALL(a) begin((a)), end((a))
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define RFOR(i, a, b) for (int(i) = (a); (i) > (b); (i)--)
#define debug(x) cout << #x << " : " << x << '\n'

const int INF = 1e9;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int ans;
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int hoge = X / (Y + Z);
  int piyo = X - hoge * (Y + Z);

  if (piyo >= Z) {
    ans = hoge;
  } else {
    ans = hoge - 1;
  }

  cout << ans << '\n';

  return 0;
}