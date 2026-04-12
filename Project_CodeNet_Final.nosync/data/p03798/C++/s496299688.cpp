#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = int64_t;
#define int ll

#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define REP(i, b) FOR(i, 0, b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(), x.end()

using pi = pair<int, int>;
using vi = vector<int>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  REP(i, (int)v.size()) {
    if (i)
      os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

ll read() {
  ll i;
  scanf("%" SCNd64, &i);
  return i;
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

string readString() {
  static char buf[3341000];
  scanf("%s", buf);
  return string(buf);
}

char *readCharArray() {
  static char buf[3341000];
  static int bufUsed = 0;
  char *ret = buf + bufUsed;
  scanf("%s", ret);
  bufUsed += strlen(ret) + 1;
  return ret;
}

template <class T, class U> void chmax(T &a, U b) {
  if (a < b)
    a = b;
}

template <class T, class U> void chmin(T &a, U b) {
  if (b < a)
    a = b;
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

char change(char &s) {
  if (s == 'S')
    return 'W';
  else
    return 'S';
}
char calc(char &type, char &claim, char &neighbor) {
  if ((type == 'S' && claim == 'o') || (type == 'W' && claim == 'x'))
    return neighbor;
  else
    return change(neighbor);
}
signed main() {
  int n = read();
  string s = readString();
  auto solv = [&](char &s1, char &s2) {
    string ret;
    ret += s1, ret += s2;
    FOR(i, 2, n) { ret += calc(ret[i - 1], s[i - 1], ret[i - 2]); }
    char pred1 = calc(ret[n - 1], s[n - 1], ret[n - 2]);
    char predn = calc(s1, s[0], s2);
    if (ret[0] == pred1 && ret[n - 1] == predn)
      return ret;
    else
      return string();
  };
  string ans;
  char type[2] = {'S', 'W'};
  REP(i, 2) REP(j, 2) {
    ans = solv(type[i], type[j]);
    if (ans.size()) {
      std::cout << ans << std::endl;
      return 0;
    }
  }
  print(-1);
}
