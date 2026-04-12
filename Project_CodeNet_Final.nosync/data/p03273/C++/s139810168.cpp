#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init) \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T>
using VEC = std::vector<T>;
template <class T>
using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail>
void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, map<T1, T2> &m) {
  os << "{";
  for (auto p : m) os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}

int main() {
  int H, W;
  cin >> H >> W;
  auto a = MATINIT(char, H, W, 0);
  REP(i, 0, H) {
    REP(j, 0, W) { cin >> a[i][j]; }
  }
  VEC<bool> fh(H, 0), fw(W, 0);
  REP(i, 0, H) {
    bool all = 1;
    REP(j, 0, W) {
      if (a[i][j] == '#') all = 0;
    }
    if (all) fh[i] = 1;
  }
  REP(i, 0, W) {
    bool all = 1;
    REP(j, 0, H) {
      if (a[j][i] == '#') all = 0;
    }
    if (all) fw[i] = 1;
  }
  REP(h, 0, H) {
    if (fh[h] == 0) {
      REP(w, 0, W) {
        if (fw[w] == 0) cout << a[h][w];
      }
      cout << endl;
    }
  }

  return 0;
}
