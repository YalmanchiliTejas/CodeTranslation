#include <bits/stdc++.h>
using namespace std;

template <typename T> T gcd(T x, T y) {
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

template <typename T> T lcm(T x, T y) {
  if (x == 0 || y == 0)
    return 0;
  return x / gcd(x, y) * y;
}

int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

vector<int> p;
vector<int> r;

void init(int n) {
  p.reserve(n);
  r.reserve(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
    r[i] = 0;
  }
}

int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }

bool same(int x, int y) { return root(x) == root(y); }

void unite(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y)
    return;

  if (r[x] < r[y])
    p[x] = y;
  else {
    p[y] = x;
    if (r[x] == r[y])
      r[x]++;
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < H; i++) {
    bool res = true;
    for (int j = 0; j < W; j++) {
      if (a[i][j] == '#') {
        res = false;
        break;
      }
    }
    if (res) {
      for (int j = 0; j < W; j++) {
        a[i][j] = ' ';
      }
    }
  }
  for (int i = 0; i < W; i++) {
    bool res = true;
    for (int j = 0; j < H; j++) {
      if (a[j][i] == '#') {
        res = false;
        break;
      }
    }
    if (res) {
      for (int j = 0; j < H; j++) {
        a[j][i] = ' ';
      }
    }
  }
  for (int i = 0; i < H; i++) {
    bool res = false;
    for (int j = 0; j < W; j++) {
      if (a[i][j] != ' ') {
        cout << a[i][j];
        res = true;
      }
    }
    if (res)
      cout << endl;
  }
}