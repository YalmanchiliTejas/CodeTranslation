#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

//各桁の和を出力
long long Sum(long long n) {
  long long m = 0;
  while (n) {
    m += n % 10;
    n /= 10;
  }
  return m;
}

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void Comuse() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

#define comuse Comuse()
// nCk(comuseを使え)
long long combi(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// pCk(comuseを使え)
long long perm(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] % MOD) % MOD;
}

//最小公倍数(aとbの)
long long lcm(long long a, long long b) {
  long long n;
  n = a / __gcd(a, b) * b;
  return n;
}

// auto A = div(n)
vector<long long> div(long long n) {
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) {
        ret.push_back(n / i);
      }
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

//(aのn乗をmodで割ったあまり)
long long modpow(long long a, long long n, long long mod) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) {
      ans = ans * a % mod;
    }

    a = a * a % mod;

    n >>= 1;
  }

  return ans;
}

void solve();

const int MAX_N = 131072;
// segment tree
int NN;
int seg[MAX_N * 2 - 1];
void seguse() {
  for (int i = 0; i < 2 * NN - 1; i++) {
    seg[i] = INT_MAX;
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << fixed;
  solve();
}

///////////////////////////////////////////////////////////

string S;
void solve() {
  cin >> S;
  if(S == "AAA" || S == "BBB"){
    cout << "No" <<endl;
  } else{
    cout << "Yes" <<endl;
  }
}
