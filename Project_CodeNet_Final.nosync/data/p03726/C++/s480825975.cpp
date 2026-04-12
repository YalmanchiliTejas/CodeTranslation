// http://agc014.contest.atcoder.jp/submissions/1263665
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i, n) for (in i = 0; i < (n); ++i)
#define forv(i, v) forn(i, sz(v))
#define fors(i, s) for (auto i = (s).begin(); i != (s).end(); ++i)
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
in n;
VVI egs;
void first() {
  cout << "First" << endl;
  exit(0);
}
void second() {
  cout << "Second" << endl;
  exit(0);
}
in dfs0(in u, in pr) {
  in avc = 0;
  forv(i, egs[u]) {
    if (egs[u][i] == pr) continue;
    avc += dfs0(egs[u][i], u);
  }
  if (avc >= 2) first();
  if (avc == 0) return 1;
  return 0;
}

int dfs(int u, int pr) {
  int avc = 0;
  for(auto c: egs[u]) {
    if (c == pr) continue;
    avc += dfs(c, u);
  }

  if (avc >= 2) first();
  if (avc == 0) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  egs.resize(n);
  in ta, tb;
  forn(z, n - 1) {
    cin >> ta >> tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  if (dfs(0, 0)) {
    first();
  }
  second();
  return 0;
}