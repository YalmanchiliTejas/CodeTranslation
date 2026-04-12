/*  -*- coding: utf-8 -*-
 *
 * 2968.cc: Non-trivial Common Divisor
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

const int MAX_N = 1000;
const int MAX_P = 31700;

/* typedef */

typedef long long ll;
typedef vector<int> vi;

/* global variables */

bool primes[MAX_P + 1];
int as[MAX_N], pnums[MAX_P];

/* subroutines */

int gen_primes(int maxp, int pnums[]) {
  memset(primes, true, sizeof(primes));
  primes[0] = primes[1] = false;

  int p, pn = 0;
  for (p = 2; p * p <= maxp; p++)
    if (primes[p]) {
      pnums[pn++] = p;
      for (int q = p * p; q <= maxp; q += p) primes[q] = false;
    }
  for (; p <= maxp; p++)
    if (primes[p]) pnums[pn++] = p;
  return pn;
}

bool prime_decomp(int n, int pn, int pnums[], vi& pds) {
  pds.clear();

  for (int i = 0; i < pn; i++) {
    int pi = pnums[i];
    if (pi * pi > n) {
      if (n > 1) pds.push_back(n);
      return true;
    }

    if (n % pi == 0) {
      while (n % pi == 0) n /= pi;
      pds.push_back(pi);
    }
  }
  return false;
}

/* main */

int main() {
  int pn = gen_primes(MAX_P, pnums);

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", as + i);

  ll maxsum = 0;
  for (int i = 0; i < n; i++)
    if (as[i] > 1) {
      vi pds;
      prime_decomp(as[i], pn, pnums, pds);
      //printf("pds=%lu\n", pds.size());

      for (vi::iterator vit = pds.begin(); vit != pds.end(); vit++) {
	int p = *vit;
	ll sum = as[i];
	for (int j = i + 1; j < n; j++)
	  if (as[j] % p == 0) sum += as[j];
	if (maxsum < sum) maxsum = sum;
      }
    }

  printf("%lld\n", maxsum);
  return 0;
}

