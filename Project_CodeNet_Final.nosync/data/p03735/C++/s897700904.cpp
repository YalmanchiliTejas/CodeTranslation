#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

#define int long long
typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF (1LL<<60)
#define MOD 1000000007

int N;
P X[200000];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  vector<int> a, b;
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    if (y < x) swap(x, y);
    X[i] = P(x, y);
    a.pb(x);
    b.pb(y);
  }
  sort(X, X+N);
  sort(all(a));
  sort(all(b));

  long long s = 1LL * (a.back() - a.front()) * (b.back() - b.front());
  int lim = X[N-1]._1, m = INF, nm = INF;
  vector<P> v;
  rep(i, N) {
    if (X[i]._2 <= lim) {
      m = min(m, X[i]._2);
      nm = min(nm, X[i]._2);
    }
    else {
      m = min(m, X[i]._1);
      v.pb(X[i]);
    }
  }
  int diff = lim - m;
  vector<int> mi(v.size()+1);
  mi[v.size()] = INF;
  for (int i=v.size()-1; i>=0; i--) {
    mi[i] = min(mi[i+1], v[i]._1);
  }
  for (int i=0; i<v.size(); i++) {
    P p = v[i];
    lim = max(lim, p._2);
    nm = min(nm, mi[i+1]);
    if (lim<nm) break;
    diff = min(diff, lim-nm);
  }

  s = min(s, 1LL*diff*(b.back() - a.front()));
  cout << s << "\n";
  return 0;
}
