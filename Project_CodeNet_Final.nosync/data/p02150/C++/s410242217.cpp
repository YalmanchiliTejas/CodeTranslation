/*  -*- coding: utf-8 -*-
 *
 * 3052.cc: 
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

const long long MOD = 1000000007LL;

/* typedef */

typedef long long ll;

/* global variables */

/* subroutines */

/* main */

int main() {
  ll a, b, x;
  scanf("%lld%lld%lld", &a, &b, &x);

  ll sum = x % MOD;
  if (x >= a) {
    ll k = (x - a) / (a - b) + 1;
    sum = (sum + (k % MOD) * (b % MOD)) % MOD;
  }

  printf("%lld\n", sum);
  return 0;
}

