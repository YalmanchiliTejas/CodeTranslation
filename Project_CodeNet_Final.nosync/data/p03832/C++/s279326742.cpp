#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
using ll = long long;

class range {private: struct I{int x;int operator*(){return x;}bool operator!=(I& lhs){return x<lhs.x;}void operator++(){++x;}};I i,n;
public:range(int n):i({0}),n({n}){}range(int i,int n):i({i}),n({n}){}I& begin(){return i;}I& end(){return n;}};

const int MOD = 1000*1000*1000+7;
void chadd(int& a, int b) { a = ((ll)a+b)%MOD; }
int mul(int a, int b) { return ((ll)a*b)%MOD; }

int fact[1020], invfact[1020];
int powinvfact[1020][1020];
ll inv(ll a, ll p) {
  return ( a == 1 ? 1 : (1 - p*inv(p%a, a)) / a + p );
}
ll power(ll a,ll b,ll mod) {
  if (b==0) return 1LL;
  if (b%2) return (a*power(a,b-1,mod))%mod;
  else {
    ll x=power(a,b/2,mod);
    return (x*x)%mod;
  }
}

int dp[1020][1020];  // dp[num][total] := counting

int main() {
  fact[0] = 1;
  for (int i : range(1, 1020)) {
    fact[i] = mul(fact[i - 1], i);
  }
  for (int i : range(1020)) invfact[i] = inv(fact[i], MOD);

  for (int i : range(1020)) {
    for (int j : range(1020)) {
      powinvfact[i][j] = power(invfact[i], j, MOD);
    }
  }

  int N;
  int A, B, C, D;
  while (cin >> N >> A >> B >> C >> D) {
    memset(dp, 0, sizeof(dp));
    dp[A - 1][0] = 1;

    for (int n = A; n <= B; ++n)
    for (int total = 0; total <= N; ++total) {
      if (dp[n - 1][total] == 0) continue;
      //cout << n - 1 << " " << total << " : " << dp[n - 1][total] << endl;

      for (int x = C; x <= D; ++x) {
        int ntotal = total + x * n;
        if (ntotal > N) break;

        int pie = N - total;
        int choose = N - ntotal;
        int comb = mul(fact[pie], mul(invfact[choose], invfact[pie - choose]));
        int comb2 = mul(fact[x * n], mul(powinvfact[n][x], invfact[x]));
        int coef = mul(comb, comb2);

        // cout << "#" << n << " " << total << " " << x << " : " << comb <<" " << comb2 << " ( " << ntotal << endl;

        chadd(dp[n][ntotal], mul(dp[n - 1][total], coef));
      }

      // x == 0
      chadd(dp[n][total], dp[n - 1][total]);
    }

    cout << dp[B][N] << endl;
  }
}
