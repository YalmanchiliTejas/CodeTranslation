//#include <bits/stdc++.h>
#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define ROF(i, j, k) for(int i = (int)(j); i >= (int)(k); --i)
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n)
#define REVERSE(v) reverse((v).begin(), (v).end())

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
typedef pair<int, int> P;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }


int
main(void){  
  int N;
  cin >> N;
  ll a[N];  
  REP(i, N) cin >> a[i];
  SORT(a, N);
  ll ans = 0;

  if(N % 2 == 0) {
    for(int i = 1; i < N/2; i++) {
      ans += (ll)(i*2)*abs(a[i] - a[i-1]);
      ans += (ll)(i*2)*abs(a[N-1-i] - a[N-i]);
    }
    ans += (ll)(N-1)*abs(a[N/2]-a[N/2-1]);
  } else {
    for(int i = 1; i <= N/2; i++) {
      ans += (ll)(i*2)*abs(a[i] - a[i-1]);
      ans += (ll)(i*2)*abs(a[N-1-i] - a[N-i]);
    }
    ll work = min(abs(a[N/2]-a[N/2-1]),	a[N/2+1]-a[N/2]);
    ans -= work;
 
  }
  cout << ans << endl;

  return 0;
}
