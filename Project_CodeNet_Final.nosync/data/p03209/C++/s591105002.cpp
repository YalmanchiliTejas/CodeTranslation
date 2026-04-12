//$g++ -std=c++11 Template.cpp 

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

priority_queue<int> q_descending;
priority_queue<int, vector<int>, greater<int> > q_ascending;

ll p[51];
ll sum[51];

ll func(ll n, ll x){
  if(n == 0) return 1;
  if(x == 0) return 0;
  ll ans = 0LL;
  
  if(x == 1) return 0;
  else if(x <= sum[n-1] + 1) ans += func(n-1,x-1);
  else if(x == sum[n-1] + 2) ans += p[n-1]+1;
  else if(x >= sum[n-1] + 3 && x <= sum[n] - 1) ans += p[n-1]+1+func(n-1,x-1-sum[n-1]-1);
  else ans += p[n];
  return ans;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  ll n, x;

  cin >> n >> x;

  p[0] = 1LL;
  sum[0] = 1LL;
  
  FOR(i, 1, 51){
    p[i] = 2*p[i-1] + 1;
    sum[i] = 2*sum[i-1] + 3;
  }

  //REP(i, n+1) cout << sum[i] << endl;

  cout << func(n, x) << endl;
  
  
  return 0;
}
