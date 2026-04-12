/*  -*- coding: utf-8 -*-
 *
 * c.cc: E: Ball Coloring
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 200000;

typedef long long ll;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

/* typedef */

typedef pair<int,int> pii;
typedef map<int,int> mii;

/* global variables */

pii rbs[MAX_N];
mii rs, bs;

/* subroutines */

inline void setmin(int &a, int b) { if (a > b) a = b; }
inline void setmax(int &a, int b) { if (a < b) a = b; }

void mreplace(mii &m, int a, int b) {
  mii::iterator mit = m.lower_bound(a);
  if (--mit->second == 0) m.erase(mit);
  m[b]++;
}

/* main */

int main() {
  int n;
  scanf("%d", &n);

  int rmin = INF, rmax = 0, bmin = INF, bmax = 0;
  for (int i = 0; i < n; i++) {
    int &ri = rbs[i].first, &bi = rbs[i].second;
    scanf("%d%d", &ri, &bi);
    if (ri > bi) swap(ri, bi);
    setmin(rmin, ri); setmax(rmax, ri);
    setmin(bmin, bi); setmax(bmax, bi);
    rs[ri]++;
    bs[bi]++;
  }
  sort(rbs, rbs + n);

  ll mulmin = (ll)(rmax - rmin) * (bmax - bmin);

  for (int i = 0; i < n; i++) {
    int &ri = rbs[i].first, &bi = rbs[i].second;
    mreplace(rs, ri, bi);
    mreplace(bs, bi, ri);

    ll mul =
      (ll)(rs.rbegin()->first - rs.begin()->first) *
      (bs.rbegin()->first - bs.begin()->first);
    if (mulmin > mul) mulmin = mul;
  }

  printf("%lld\n", mulmin);
  return 0;
}
