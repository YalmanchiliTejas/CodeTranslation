//
//  sublime text 3,
//  emre yazicioglu
//

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <pll> vpll;
#define pb push_back
#define INF (ll) (1e18 + 7)
#define MOD (ll) (1e9 + 7)
#define F first
#define S second

const int N = 2e6 + 7;
ll mn = INF, mx = -INF;
ll n, m, k, s, q, t[N];
ll a, b, c, d, e;
ll ans[N], cur, sum, cnt;
ll ar[N], p[N], dp[N];
string tr; bool h[N];
pll pp[N]; vll v;

inline void fastInputOutput () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
}

inline void ReadWriteFromFile () {
  freopen("../in.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);
}

void U (int n, int s, int e, int i, int v) {
  if (s == e) 
    t[n] += v;
  else {
    int m = s + (e - s) / 2;
    if (i <= m)
      U(n * 2, s, m, i, v);
    else 
      U(n * 2 + 1, m + 1, e, i, v);
    t[n] = max(t[n * 2], t[n * 2 + 1]);
  }
}

int Q (int n, int s, int e, int l, int r) {
  if (l <= s && r >= e)
    return t[n];
  if (l > e || r < s)
    return 0;
  int m = s + (e - s) / 2;
  return max(Q(n * 2, s, m, l, r), Q(n * 2 + 1, m + 1, e, l, r));
}

bool comp (pll &a, pll &b) {
  if(a.F != b.F)
    return a.F < b.F;
  return a.S > b.S;
}

int main() {
  fastInputOutput();
  // ReadWriteFromFile();

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    pp[i] = {ar[i], i};
  }
  sort(pp + 1, pp + n + 1, comp);
  for (int i = 1; i <= n; i++) {
    q = Q(1, 1, n, pp[i].S + 1, n);
    U(1, 1, n, pp[i].S, q + 1);
    ans[pp[i].S] = q + 1;
    mx = max(mx, ans[pp[i].S]);
  }
  cout << mx;
}