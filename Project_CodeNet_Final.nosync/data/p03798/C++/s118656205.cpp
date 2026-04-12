#include <bits/stdc++.h>

using namespace std;

int reverse(char s) {
  if (s == 'S') return 'W';
  if (s == 'W') return 'S';
  return 0;
}
int may_reverse(bool flag, char s) {
  if (flag) {
    if (s == 'S') return 'W';
    if (s == 'W') return 'S';
  }
  return s;
}

int n;
int next(int i) {
  if (++i == n) return 0;
  return i;
}
int prev(int i) {
  if (--i < 0) return n-1;
  return i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> n >> s;

  string assume;
  assume.resize(n);
  char type[] = "SW";
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      assume[1] = type[j];
      assume[0] = type[i];

      int pos = 1;
      for (int k = 0; k < n + 2; ++k) {
        assume[next(pos)] =
          may_reverse(assume[pos] == 'S' ^ s[pos] == 'o',
                      assume[prev(pos)]);
        pos = next(pos);
      }
      if (assume[0] == type[i] && assume[1] == type[j]) {
        cout << assume <<" \n";
        return 0;
      }

    }
  }
  cout << -1 << "\n";
}
