#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 52;

int n;
ll p[MAX];

int check(ll x) {
  if (x < 0) return 0;
  ll kol = 0;
  
  REP(i, n) {
    ll tmp = p[i] + x - n + 1;
    //    if (!x) TRACE(tmp);
    
    if (tmp > 0)
      kol += (tmp - 1) / (n+1) + 1;
  }
  return kol <= x;
}

int main()
{
  scanf("%d", &n);
  REP(i, n)
    scanf("%lld", &p[i]);

  ll lo=0;
  REP(i, n) lo += p[i];

  for (ll i=lo-2*n*n; ; i++) {
    if (check(i)) {
      printf("%lld\n", i);
      return 0;
    }
  }

  assert(0);
}
