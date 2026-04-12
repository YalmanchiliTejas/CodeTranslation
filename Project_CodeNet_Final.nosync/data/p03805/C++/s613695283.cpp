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

const int maxN = 8 + 5;
int n, m;
vector<vi> graph(maxN);
int ans;

void dfs(int current, int isStayed, int cnt) {
  if (cnt == n) {
    ans++;
    return;
  }
  isStayed += 1 << current;
  for (auto &v : graph[current]) {
    if (!((isStayed >> v) & 1))
      dfs(v, isStayed, cnt + 1);
  }
}

signed main() {
  std::cin >> n >> m;
  REP(i, m) {
    int a, b;
    std::cin >> a >> b;
    graph[a].PB(b);
    graph[b].PB(a);
  }
  int isStayed = 1;
  dfs(1, isStayed, 1);
  print(ans);
}
