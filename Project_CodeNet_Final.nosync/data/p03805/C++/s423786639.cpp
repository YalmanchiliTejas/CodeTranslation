// https://atcoder.jp/contests/abc054/tasks/abc054_b
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define EACH(i, n) for (auto &i: n)

struct Line {
  int from, to;
  bool used;
};

int scan(int n, int p, vector<Line> lines, set<int> used) {
  if (used.size() == n) return 1;

  int sum = 0;
  EACH(l, lines) {
    if (l.used) continue;
    int to = -1;
    if (l.from == p) {
      to = l.to;
    } else if (l.to == p) {
      to = l.from;
    }
    if (to == -1) continue;

    if (used.find(to) != used.end()) continue;

    l.used = true;
    used.insert(to);
    sum += scan(n, to, lines, used);
    used.erase(to);
    l.used = false;
  }
  return sum;
}

int solv(int n, int m) {
  vector<Line> lines;
  FOR(i, m) {
    Line l;
    cin >> l.from >> l.to;
    l.used = false;
    lines.push_back(l);
  }

  set<int> used;
  used.insert(1);

  return scan(n, 1, lines, used);
}

int main() {
  int n, m;

  while (cin >> n >> m) {
    cout << solv(n, m) << endl;
  }

  return 0;
}
