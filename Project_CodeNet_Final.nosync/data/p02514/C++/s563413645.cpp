#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

ll v[6];

int main() {
  while (true) {
    ll total = 0;
    REP(i, 6) {
      scanf("%lld", &v[i]);
      total += v[i];
    }
    if (total == 0) { break; }
    ll a = v[0] + v[3];
    ll b = v[1] + v[4];
    ll c = v[2] + v[5];
    ll ans = 0;
    ans = max(ans, a / 3 + b / 3 + c / 3);
    a--; b--; c--;
    if (a >= 0 && b >= 0 && c >= 0) {
      ans = max(ans, 1 + a / 3 + b / 3 + c / 3);
    }
    a--; b--; c--;
    if (a >= 0 && b >= 0 && c >= 0) {
      ans = max(ans, 2 + a / 3 + b / 3 + c / 3);
    }
    printf("%lld\n", ans);
  }
}