#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
template <class T> inline void chmin(T &a, const T& b) { if (b < a) a = b; }
template <class T> inline void chmax(T &a, const T& b) { if (b > a) a = b; }
/* clang-format on */

using ull = unsigned long long;

enum type {
  MUL_0 = 0,
  MUL_1 = 1,
  ADD_0 = 2,
  ADD_1 = 3,
};

vec<int, 2> solve(int N,const vector<int>& typeY, const vector<int>& typeX) {
  vec<int, 2> res = make_v(N, N, -1);
  vector<int> resY(N), resX(N), cntY(N), cntX(N);
  for (int y = 0; y < N; y++) resY[y] = (typeY[y] >> 1) ? 0 : 1;
  for (int x = 0; x < N; x++) resX[x] = (typeX[x] >> 1) ? 0 : 1;
  auto write = [&](int y, int x, int v) {
    res[y][x] = v;
    ++cntY[y];
    ++cntX[x];
    if (typeY[y] >> 1) {
      resY[y] |= v;
    } else {
      resY[y] &= v;
    }
    if (typeX[x] >> 1) {
      resX[x] |= v;
    } else {
      resX[x] &= v;
    }
  };
  auto fillY = [&](int y) {
    for (int x = 0; x < N; x++) {
      if (res[y][x] != -1) continue;
      write(y, x, typeX[x] == MUL_0 ? 0 : 1);
    }
  };
  auto fillX = [&](int x) {
    for (int y = 0; y < N; y++) {
      if (res[y][x] != -1) continue;
      write(y, x, typeY[y] == MUL_0 ? 0 : 1);
    }
  };
  for (int y = 0; y < N; y++) {
    if (typeY[y] == MUL_1) for (int x = 0; x < N; x++) write(y, x, 1);
    if (typeY[y] == ADD_0) for (int x = 0; x < N; x++) write(y, x, 0);
  }
  for (int x = 0; x < N; x++) {
    if (typeX[x] == MUL_1) for (int y = 0; y < N; y++) write(y, x, 1);
    if (typeX[x] == ADD_0) for (int y = 0; y < N; y++) write(y, x, 0);
  }
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (typeY[y] == MUL_0 && typeX[x] == MUL_0) write(y, x, 0);
      if (typeY[y] == ADD_1 && typeX[x] == ADD_1) write(y, x, 1);
    }
  }
  while (true) {
    bool found = false;
    for (int y = 0; y < N; y++) {
      if (typeY[y] == MUL_0 && resY[y] == 0 && cntY[y] < N) {
        found = true;
        fillY(y);
      }
      if (typeY[y] == ADD_1 && resY[y] == 1 && cntY[y] < N) {
        found = true;
        fillY(y);
      }
    }
    for (int x = 0; x < N; x++) {
      if (typeX[x] == MUL_0 && resX[x] == 0 && cntX[x] < N) {
        found = true;
        fillX(x);
      }
      if (typeX[x] == ADD_1 && resX[x] == 1 && cntX[x] < N) {
        found = true;
        fillX(x);
      }
    }
    if (!found) break;
  }
  int s = 0;
  for (int y = 0; y < N; y++) {
    int p = s;
    bool found = true;
    for (int x = 0; x < N; x++) {
      if (res[y][x] != -1) continue;
      found = true;
      res[y][x] = p;
      p ^= 1;
    }
    if (found) s ^= 1;
  }
  return res;
}

bool check(int N, const vec<ull, 2> &res, const vector<int>& S, const vector<int>& T, const vector<ull>& U, const vector<ull>& V) {
  bool ok = true;
  for (int y = 0; y < N; y++) {
    ull v = S[y] ? 0ull : ~(0ull);
    for (int x = 0; x < N; x++) {
      if (S[y]) {
        v |= res[y][x];
      } else {
        v &= res[y][x];
      }
    }
    ok &= (v == U[y]);
  }
  for (int x = 0; x < N; x++) {
    ull v = T[x] ? 0ull : ~(0ull);
    for (int y = 0; y < N; y++) {
      if (T[x]) {
        v |= res[y][x];
      } else {
        v &= res[y][x];
      }
    }
    ok &= (v == V[x]);
  }
  return ok;
}

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  int N;
  while (cin >> N) {
    vector<int> S(N), T(N);
    vector<ull> U(N), V(N);
    for (auto& x : S) cin >> x;
    for (auto& x : T) cin >> x;
    for (auto& x : U) cin >> x;
    for (auto& x : V) cin >> x;
    vec<ull, 2> res = make_v(N, N, 0ull);
    for (int b = 0; b < 64; b++) {
      vector<int> typeY(N), typeX(N);
      for (int i = 0; i < N; i++) {
        int u = (U[i] >> b) & 1;
        int v = (V[i] >> b) & 1;
        typeY[i] = S[i] * 2 + u;
        typeX[i] = T[i] * 2 + v;
      }
      auto sub = solve(N, typeY, typeX);
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          res[i][j] += ull(sub[i][j]) << b;
        }
      }
    }
    if (check(N, res, S, T, U, V)) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          cout << res[i][j] << " ";
        }
        cout << endl;
      }
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
