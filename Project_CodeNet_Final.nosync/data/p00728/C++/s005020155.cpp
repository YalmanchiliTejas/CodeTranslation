#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define Rep(b, e, i) for (int i = b; i <= e; i++)
#define Repr(e, b, i) for (int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n - 1, i)
#define repr(n, i) Repr(n - 1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define uniq(x) (x).erase(unique(all(x)), (x).end())

const int MAX = 200000;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1 <<29;
const int MOD = 1000000007;

void solve(void) {
  while (1) {
    int N;
    scanf("%d\n", &N);
    if (N == 0) break;
    vector<int> ps;
    int ans = 0;
    rep(N, i) {
      int p;
      scanf("%d\n", &p);
      ps.pb(p);
      ans += p;
    }
    sort(all(ps));
    ans -= ps[0] + ps[N-1];
    printf("%d\n", ans / (N-2));
  }
}

int main(void) {
  solve();
  return 0;
}

