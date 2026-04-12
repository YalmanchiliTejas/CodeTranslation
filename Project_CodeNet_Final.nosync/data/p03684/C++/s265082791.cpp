#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

const int MAXN = 1e5+10;

struct _Point {
  llint cost;
  int idx;
  int x, y;
  _Point () {}
  _Point (int _idx, int _x, int _y) {
    idx = _idx;
    x = _x;
    y = _y;
  }
  friend bool operator < (const _Point &A, const _Point &B) {
    return A.cost > B.cost;
  }
};

bool bio[MAXN];

int n;

vector<_Point> P;
vector<int> G[MAXN];

priority_queue<_Point> pq;

inline int get_dist(const _Point &A, const _Point &B) {
  return min(abs(A.x - B.x), abs(A.y - B.y));
}

inline bool cmp_x(const _Point &A, const _Point &B) {
  return A.x < B.x;
}

inline bool cmp_y(const _Point &A, const _Point &B) {
  return A.y < B.y;
}

inline bool cmp_id(const _Point &A, const _Point &B) {
  return A.idx < B.idx;
}

llint prim() {
  llint sol = 0;
  P[0].cost = 0;
  pq.push(P[0]);
  while (!pq.empty()) {
    while (!pq.empty() && bio[pq.top().idx]) pq.pop();
    if (pq.empty()) break;

    _Point curr = pq.top();
    pq.pop();
    bio[curr.idx] = true;
    sol += (llint) curr.cost;

    for (int nxt : G[curr.idx]) {
      if (bio[nxt]) continue;
      _Point _nxt = P[nxt];
      _nxt.cost = get_dist(P[curr.idx], P[nxt]);
      pq.push(_nxt);
    }
  }
  return sol;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    P.emplace_back(i, x, y);
  }

  sort(P.begin(), P.end(), cmp_x);
  for (int i = 0; i < P.size() - 1; ++i) {
    G[P[i].idx].push_back(P[i + 1].idx);
    G[P[i + 1].idx].push_back(P[i].idx);
  }

  sort(P.begin(), P.end(), cmp_y);
  for (int i = 0; i < P.size() - 1; ++i) {
    G[P[i].idx].push_back(P[i + 1].idx);
    G[P[i + 1].idx].push_back(P[i].idx);
  }

  sort(P.begin(), P.end(), cmp_id);
  printf("%lld\n", prim());

  return 0;
}

