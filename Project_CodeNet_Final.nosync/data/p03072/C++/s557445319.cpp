#include <iostream>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

using namespace std;

signed main() {
  IOS;
  int N,H,maxx, i, ans=1;
  cin >> N;
  cin >> H;
  maxx = H;
  for (i = 1; i < N; ++i) {
    cin >> H;
    if (H >= maxx) ans++;
    maxx = max(H, maxx);
  }
  cout << ans << endl;
  return 0;
}
