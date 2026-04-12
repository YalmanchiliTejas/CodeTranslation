#include <bits/stdc++.h>
typedef long long int lld;
typedef unsigned long long int llu;
#define INF (lld)(9223372036854775807)
#define IINF (int)(2147483647)

using namespace std;

vector<lld> v;
lld l, k;

lld f(lld d, lld c, bool m) {
  if (l == d) {
    return c == 0;
  }
  lld s = f(d + 1, c, m && v[d] == 0);
  if (c == 0) {
    return s;
  }
  if (m) {
    if (v[d] == 0) {
      return s;
    }
    return s + (v[d] - 1) * f(d + 1, c - 1, false) + f(d + 1, c - 1, true);
  } else {
    return s + 9 * f(d + 1, c - 1, false);
  }
}

int main(void) {
  string n;
  cin >> n >> k;
  l = n.length();
  v = vector<lld>(l);
  for (lld i = 0; i < l; i++) {
    v[i] = n.c_str()[i] - '0';
  }
  cout << f(0, k, true) << "\n";
}