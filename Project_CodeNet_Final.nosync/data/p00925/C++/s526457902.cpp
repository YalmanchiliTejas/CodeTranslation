#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

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

char str[100];

ll calc(ll lhs, char c, ll rhs) {
  if (c == '+') { return lhs + rhs; }
  return lhs * rhs;
}
char *skip(char *p) {
  while (isdigit(*p)) { p++; }
  return p;
}

ll calc1() {
  char *p = str;
  ll lhs = atoi(p);
  p = skip(p);
  while (*p != 0) {
    char c = *p;
    p++;
    ll rhs = atoi(p);
    lhs = calc(lhs, c, rhs);
    p = skip(p);
  }
  return lhs;
}

ll calc2() {
  char *p = str;
  vector<ll> vs;
  ll lhs = atoi(p);
  p = skip(p);
  while (*p != 0) {
    char c = *p;
    p++;
    if (c == '+') { 
      vs.push_back(lhs);
      lhs = atoi(p);
    } else {
      ll rhs = atoi(p);
      lhs *= rhs;
    }
    p = skip(p);
  }
  FORIT(it, vs) { lhs += *it; }
  return lhs;
}

int main() {
  ll ans;
  while (scanf("%s %lld", str, &ans) > 0) {
    ll v1 = calc1();
    ll v2 = calc2();
    if (ans == v1 && ans == v2) {
      puts("U");
    } else if (ans == v1) {
      puts("L");
    } else if (ans == v2) {
      puts("M");
    } else {
      puts("I");
    }
  }
}