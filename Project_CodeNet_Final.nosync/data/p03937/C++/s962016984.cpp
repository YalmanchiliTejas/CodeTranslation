#include <bits/stdc++.h>
#define sz(arr) (int)(arr).size()
#define rng(arr) arr.begin(), arr.end()
#define show(x) cout << #x << " = " << x << endl;

using namespace std;
typedef long long ll;

void _cin() {}
template <class Head, class... Tail>
void _cin(Head&& head, Tail&&... tail) {
  cin >> head;
  _cin(forward<Tail>(tail)...);
}

#define Cin(T, ...) \
  T __VA_ARGS__;    \
  _cin(__VA_ARGS__)

#define Cins(T, n, xs) \
  vector<T> xs(n);     \
  for (int i = 0; i < n; ++i) cin >> xs[i]

void Main() {
  Cin(int, h, w);
  Cins(string, h, a);

  int x = 0, y = 0;
  vector<vector<bool>> checked(h, vector<bool>(w, false));
  while (true) {
    if (a[y][x] != '#') {
      puts("Impossible");
      return;
    }
    checked[y][x] = true;
    if (x == w - 1 && y == h - 1) break;
    if (x < w - 1 && y < h - 1) {
      if (a[y + 1][x] == '#' && a[y][x + 1] == '#') {
        puts("Impossible");
        return;
      }
    }
    if (x < w - 1)
      if (a[y][x + 1] == '#') {
        x++;
        continue;
      }
    if (y < h - 1)
      if (a[y + 1][x] == '#') {
        y++;
        continue;
      }
    puts("Impossible");
    return;
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '#' && !checked[i][j]) {
        puts("Impossible");
        return;
      }
    }
  }
  puts("Possible");
}

int main() {
  cout << fixed << setprecision(15);
  Main();
  return 0;
}