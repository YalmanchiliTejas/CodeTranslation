#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> P2;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
const int X = 123123;
const int Y = 321321;

int A, B;
int D[10][10];
int N;
int down[101], up[101];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> A >> B;
  rep(x, A) rep(y, B) cin >> D[x][y];
  bool ok = true;
  rep(x, A) rep(y, B-1) if (D[x][y] > D[x][y+1]) ok = false;
  rep(x, A-1) rep(y, B) if (D[x][y] > D[x+1][y]) ok = false;
  if (!ok) {
    cout << "Impossible\n";
    return 0;
  }
  vector<P2> edges;
  int s = 0, t = 1;
  N = 2;
  down[0] = s;
  up[0] = t;
  for (int i=1; i<=100; i++) {
    down[i] = N++;
    edges.pb(P2(P(down[i-1], down[i]), X));
  }
  for (int i=1; i<=100; i++) {
    up[i] = N++;
    edges.pb(P2(P(up[i], up[i-1]), Y));
  }
  vector<P2> vs;
  for (int a=0; a<=100; a++) {
    for (int b=0; b<=100; b++) {
      int c = 0;
      for (int x=1; x<=A; x++) {
        for (int y=1; y<=B; y++) {
          c = max(c, D[x-1][y-1]-a*x-b*y);
        }
      }
      vs.pb(P2(P(a, b), c));
      edges.pb(P2(P(down[a], up[b]), c));
    }
  }
  for (int x=1; x<=A; x++) {
    for (int y=1; y<=B; y++) {
      int dist = INF;
      for (P2 p : vs) {
        int a = p._1._1, b = p._1._2, c = p._2;
        dist = min(dist, a*x+b*y+c);
      }
      if (dist != D[x-1][y-1]) {
        cout << "Impossible\n";
        return 0;
      }
    }
  }
  cout << "Possible\n";
  cout << N << " " << edges.size() << "\n";
  for (P2 p : edges) {
    cout << p._1._1+1 << " " << p._1._2+1 << " ";
    int w = p._2;
    if (w == X) cout << "X\n";
    else if (w == Y) cout << "Y\n";
    else cout << w << "\n";
  }
  cout << "1 2\n";
  return 0;
}
