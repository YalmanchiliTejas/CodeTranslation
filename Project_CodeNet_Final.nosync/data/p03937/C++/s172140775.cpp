#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dx[4] = {1, 0};
int dy[4] = {0, 1};

int main() {
  int h, w, cnt = 0;
  cin >> h >> w;
  char c;
  rep(i, h) rep(j, w) {
    cin >> c;
    if (c == '#') cnt++;
  }
  cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;
  return 0;
}
