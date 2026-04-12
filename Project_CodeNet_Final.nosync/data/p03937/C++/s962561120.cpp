#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int h, w, cnt = 0;
  cin >> h >> w;
  string s;
  rep(i, h) {
    cin >> s;
    rep(j, w) if (s[j] == '#') cnt++;
  }

  cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;
  return 0;
}
