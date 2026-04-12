#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

vector<ll> factmemo, factmemoInv;
ll factmemoMod = -1;

ll factorial(int n, int M){
  if(factmemoMod == M) return factmemo[n];
  if(n <= 1) return 1;

  ll res = 1;
  for(int i=1; i<=n; i++) res = res * i % M;
  return res;
}

ll power(ll k, ll n, int M){
  ll res = 1;
  while(n > 0) {
    if (n & 1) res = res * k % M;
    k = k * k % M;
    n /= 2;
  }
  return res;
}

void initFactorial(int n, int M){
  factmemo.assign(n+1, 0);
  factmemoInv.assign(n+1, 0);
  factmemoMod = M;
  factmemo[0] = 1;
  for(int i=1;i<=n;i++) factmemo[i] = factmemo[i-1] * i % M;
  factmemoInv[n] = power(factmemo[n], M-2, M);
  for(int i=n;i>0;i--) factmemoInv[i-1] = factmemoInv[i] * i % M;
}

//nCm nPm nHm (mod M)

/*Combination*/
ll C(int n, int m, int M){
  if(n < m) return 0;
  if(m == 0 || n == m) return 1;

  if(factmemoMod == M)
    return factmemo[n] * factmemoInv[m] % M * factmemoInv[n-m] % M;

  ll numer = factorial(n, M);
  ll denom = factorial(m, M) * factorial(n-m, M) % M;

  denom = power((int)denom, M-2, M);

  return numer * denom % M;
}
/*Permutation*/
ll P(int n, int m, int M){
  if(n < m) return 0;
  if(m == 0) return 1;

  if(factmemoMod == M)
    return factmemo[n] * factmemoInv[n-m] % M;

  ll numer = factorial(n, M);
  ll denom = factorial(n-m, M);

  denom = power((int)denom, M-2, M);

  return numer * denom % M;
}
/*Combination with Repetitions*/
ll H(int n, int m, int M){
  if(n == 0 && m == 0) return 1;
  return C(n+m-1, m, M);
}


ll calc(int H, int W, int K) {
  ll res = 0;

  for (int i=1; i<H; i++) {
    ll r = (ll)(H - i) * W % mod * W % mod * i % mod;

    r = r * C(H*W-2, K-2, mod) % mod;

    res += r % mod;
  }

  return res % mod;
}

int main() {
  int H, W, K;

  cin >> H >> W >> K;

  initFactorial(H * W, mod);

  cout << (calc(H, W, K) + calc(W, H, K)) % mod << endl;

  return 0;
}
