#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init)                                          \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T> using VEC = std::vector<T>;
template <class T> using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail> void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
VEC<bool> build(string s, VEC<bool> isSheep) {
  int n = s.length();
  for (int i = 1; i < n + 1; i++) {
    if (s[i % n] == 'o') {
      if (isSheep[i % n]) {
        isSheep[(i + 1) % n] = isSheep[(i - 1) % n];
      } else {
        isSheep[(i + 1) % n] = !isSheep[(i - 1) % n];
      }
    } else {
      if (isSheep[i % n]) {
        isSheep[(i + 1) % n] = !isSheep[(i - 1) % n];
      } else {
        isSheep[(i + 1) % n] = isSheep[(i - 1) % n];
      }
    }
  }
  return isSheep;
}
bool isValid(string s, VEC<bool> isSheep) {
  int n = s.length();
  REPC(pos, 1, n) {
    if (s[pos%n] == 'o') {
      if (isSheep[pos % n]) {
        if (isSheep[(pos - 1) % n] != isSheep[(pos + 1) % n])
          return 0;
      } else {
        if (isSheep[(pos - 1) % n] == isSheep[(pos + 1) % n])
          return 0;
      }
    } else {
      if (isSheep[pos % n]) {
        if (isSheep[(pos - 1) % n] == isSheep[(pos + 1) % n])
          return 0;
      } else {
        if (isSheep[(pos - 1) % n] != isSheep[(pos + 1) % n])
          return 0;
      }
    }
  }
  return 1;
}
void disp(VEC<bool> s) {
  int n = s.size();
  REP(i, 0, n) { cout << (s[i] ? "S" : "W"); }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  VEC<bool> isSheep(n, 0);
  VEC<bool> ans(n);
  isSheep[0] = 1;
  isSheep[1] = 1;
  ans = build(s, isSheep);
  DUMP(ans);
  if (isValid(s, ans)){
    disp(ans);
    return 0;
  }
  isSheep[0] = 1;
  isSheep[1] = 0;
  ans = build(s, isSheep);
  DUMP(ans);
  if (isValid(s, ans)) {
    disp(ans);
    return 0;
  }
  isSheep[0] = 0;
  isSheep[1] = 1;
  ans = build(s, isSheep);
  DUMP(ans);
  if (isValid(s, ans)){
    disp(ans);
    return 0;
  }
  isSheep[0] = 0;
  isSheep[1] = 0;
  ans = build(s, isSheep);
  DUMP(ans);
  if (isValid(s, ans)){
    disp(ans);
    return 0;
  }
  cout << -1 << endl;

  return 0;
}
