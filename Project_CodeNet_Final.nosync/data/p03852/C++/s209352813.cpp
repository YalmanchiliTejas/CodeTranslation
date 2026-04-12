#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = int64_t;
#define int ll

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)

#define rng(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) {
    if (i)
      os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
  for (auto val : array)
    std::cout << val << ", ";
  std::cout << "\n";
}

void printSpace() { printf(" "); }

void printEoln() { printf("\n"); }

void print(ll x, int suc = 1) {
  printf("%" PRId64, x);
  if (suc == 1)
    printEoln();
  if (suc == 2)
    printSpace();
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  char c;
  std::cin >> c;
  char vowel[] = {'a', 'i', 'u', 'e', 'o'};
  bool ok = false;
  for (char &v : vowel) {
    if (c == v)
      ok = true;
  }
  std::cout << (ok ? "vowel" : "consonant") << std::endl;
}
