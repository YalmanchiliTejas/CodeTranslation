#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int h,w;
  cin >> h >> w;
  int cnt = 0;
  rep(i,h) rep(j,w) {
    char c; cin >> c;
    if (c == '#') cnt++;
  }
  if (cnt == h+w-1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}