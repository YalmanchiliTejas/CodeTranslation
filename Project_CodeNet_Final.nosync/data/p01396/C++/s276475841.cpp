#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

typedef int Weight;
struct Edge {
  int src;
  int dest;
  Weight weight;
  Edge(int src, int dest, Weight weight) : src(src), dest(dest), weight(weight) {;}
  bool operator<(const Edge &rhs) const {
    if (weight != rhs.weight) { return weight > rhs.weight; }
    if (src != rhs.src) { return src < rhs.src; }
    return dest < rhs.dest;
  }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void PrintMatrix(const Matrix &matrix) {
  for (int y = 0; y < (int)matrix.size(); y++) {
    for (int x = 0; x < (int)matrix[y].size(); x++) {
      printf("%d ", matrix[y][x]);
    }
    puts("");
  }
}

Weight augment(const Graph &g, Matrix &capacity, const vector<int> &level, vector<bool> &finished, int from, int t, Weight cur) {
  if (from == t || cur == 0) { return cur; }
  if (finished[from]) { return 0; }
  for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
    int to = it->dest;
    if (level[to] <= level[from]) { continue; }
    Weight f = augment(g, capacity, level, finished, to, t, min(cur, capacity[from][to]));
    if (f > 0) {
      capacity[from][to] -= f;
      capacity[to][from] += f;
      return f;
    }
  }
  finished[from] = true;
  return 0;
}

Weight MaxFlow(const Graph &g, int s, int t) {
  int n = g.size();
  Matrix capacity(n, Array(n));
  for (int from = 0; from < n; from++) {
    for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
      int to = it->dest;
      capacity[from][to] += it->weight;
    }
  }
  int ans = 0;
  while (true) {
    vector<int> level(n, -1);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    for (int d = n; !que.empty() && level[que.front()] < d; ) {
      int from = que.front();
      que.pop();
      if (from == t) { d = level[from]; }
      for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
        int to = it->dest;
        if (capacity[from][to] > 0 && level[to] == -1) {
          que.push(to);
          level[to] = level[from] + 1;
        }
      }
    }
    vector<bool> finished(n);
    bool end = true;
    while (true) {
      Weight f = augment(g, capacity, level, finished, s, t, 2000000000LL);
      if (f == 0) { break; }
      ans += f;
      end = false;
    }
    if (end) { break; }
  }
  return ans;
}

void AddEdge(Graph &g, int from, int to, Weight capacity) {
  g[from].push_back(Edge(from, to, capacity));
  g[to].push_back(Edge(to, from, 0));
}



int h, w;
int field[1010][1010];
pair<int, int> values[1010];
bitset<1000> ok[1010];

void PrintOK() {
  REP(y, w) {
    REP(x, w) {
      printf("%d",(int)ok[y][x]);
    }
    puts("");
  }
}

inline int IN(int x) { return x; }
inline int OUT(int x) { return x + w; }
inline int SOURCE() { return w + w; }
inline int DEST() { return w + w + 1; }
inline int SIZE() { return w + w + 2; }

bool solve() {
  REP(i, w) {
    ok[i].set();
    ok[i] >>= 1000 - w;
  }
  REP(y, h) {
    REP(x, w) {
      values[x] = make_pair(field[y][x], x);
    }
    sort(values, values + w);
    reverse(values, values + w);
    int index = 0;
    bitset<1000> bits;
    bits.set();
    bits >>= 1000 - w;
    REP(x, w) {
      while (index < w && values[x].first <= values[index].first) {
        bits[values[index].second] = 0;
        index++;
      }
      ok[values[x].second] &= bits;
    }
  }
  bool existHighest = false;
  Graph g(SIZE());
  REP(from, w) {
    existHighest |= ((int)ok[from].count() == w - 1);
    AddEdge(g, SOURCE(), IN(from), 1);
    AddEdge(g, OUT(from), DEST(), 1);
    REP(to, w) {
      if (ok[from][to]) {
        AddEdge(g, IN(from), OUT(to), 1);
      }
    }
  }
  if (!existHighest) { return false; }
  return MaxFlow(g, SOURCE(), DEST()) >= w - 2;
}


int temp[1010][1010];
void transpose() {
  REP(y, h) {
    REP(x, w) {
      temp[x][y] = field[y][x];
    }
  }
  memcpy(field, temp, sizeof(field));
  swap(h, w);
}

int main() {
  scanf("%d %d", &h, &w);
  REP(y, h) {
    REP(x, w) {
      scanf("%d", &field[y][x]);
    }
  }
  if (!solve()) { goto no; }
  transpose();
  if (!solve()) { goto no; }
  puts("YES");
  return 0;
 no:;
  puts("NO");
}