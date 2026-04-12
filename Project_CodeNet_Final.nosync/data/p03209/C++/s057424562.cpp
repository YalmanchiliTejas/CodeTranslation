#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int main() {
  i64 N, X;
  cin >> N >> X;
  auto P = [](i64 N) -> i64 { return (1LL << (N + 1)) - 1; };
  auto C = [](i64 N) -> i64 { return (1LL << (N + 2)) - 3; };
  i64 ans = 0;
  for(int L = N - 1;L >= 0;L--) {
    X--;
    if(X == 0) { cout << ans << endl; return 0; }
    if(X - C(L) < 0) continue;
    X -= C(L);
    ans += P(L);
    if(X == 0) { cout << ans << endl; return 0; }
    X--;
    ans++;
    if(X == 0) { cout << ans << endl; return 0; }
    if(X - C(L) < 0) continue;
    X -= C(L);
    ans += P(L);
    if(X == 0) { cout << ans << endl; return 0; }
    X--;
    cout << ans << endl;
    return 0;
  }
  cout << ans + X << endl;
}
