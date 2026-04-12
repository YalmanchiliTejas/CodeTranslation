
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <bitset>

long long mod = 1e9+7;
class Mint {
public:
  long long x;
  Mint(){}; // 引数なしでも定義できるように引数なしコンストラクタも用意しておく
  Mint(long long a){
    x = a%mod;
    while(x<0){
      x += mod;
    }
  };
  Mint& operator += (const Mint &a){
    x+=a.x;
    x%=mod;
    return *this;
  }
  Mint& operator -= (const Mint &a){
    x += (mod - a.x);
    x%=mod;
    return *this;
  }
  Mint& operator *= (const Mint &a){
    x*=a.x;
    x%=mod;
    return *this;
  }

  // a^n mod を計算する
  // Useaeg: Mint z = Mint(2).pow(n);
  Mint pow(long long n) const {
    if (n==0) return Mint(1);
    Mint y = pow(n>>1); // pow(n/2)を計算する
    y *= y;
    if (n%2==1) y *= *this;
    return y;
  }

  // a^{-1} mod を計算する
  Mint modinv(const Mint &a) const {
    return a.pow(mod-2);
  }

  Mint& operator /= (const Mint &a) {
    x *= modinv(a).x;
    x %= mod;
    return *this;
  }

  Mint operator + (Mint &a) const {
    Mint y(*this);
    y += a;
    return y;
  }

  Mint operator - (Mint &a) const {
    Mint y(*this);
    y -= a;
    return y;
  }

  Mint operator * (Mint &a) const {
    Mint y(*this);
    y *= a;
    return y;
  }

  Mint operator / (Mint &a) const {
    Mint y(*this);
    y/=a;
    return y.x;
  }

  // nCk @mod を計算する
  Mint nCk(Mint &n, const long long k) const {
    Mint y = Mint(1);
    Mint one = Mint(1);
    for (Mint i(0); (i.x)<k; i.x++){
      y *= (n-i);
      y /= (i + one);
    }
    return y;
  }

  // nPk @mod を計算する
  Mint nPk(Mint &n, long long k) const {
    Mint y(1);
    for (Mint i(0); (i.x)<k; i.x++){
      y *= (n-i);
    }
    return y;
  }
};

long long dp[200004][3];
int main() {
  int N;
  std::cin >> N;
  std::vector<long long > A(N);
  for (int i=0; i<N; i++) {
    std::cin >> A[i];
  }
  for (int i=0; i<200004; i++) {
    dp[i][0] = -1e18;
    dp[i][1] = -1e18;
    dp[i][2] = -1e18;
  }
  dp[0][0] = A[0];
  dp[1][1] = A[1];
  dp[2][2] = A[2];
  for (int i=2; i<N; i++) {
    dp[i][0] = std::max(dp[i][0], dp[i-2][0] + A[i]);
    dp[i][1] = std::max(dp[i][1], dp[i-2][1] + A[i]);
    dp[i][2] = std::max(dp[i][2], dp[i-2][2] + A[i]);
    if (i>=3) {
      dp[i][1] = std::max(dp[i][1], dp[i-3][0]+A[i]);
      dp[i][2] = std::max(dp[i][2], dp[i-3][1]+A[i]);
    }
    if (i>=4) {
      dp[i][2] = std::max(dp[i][2], dp[i-4][0]+A[i]);
    }
  }
  long long ans = -1e18;
  /*for (int i=0; i<N; i++) {
    printf("dp[%d][0]=%lld\n", i, dp[i][0]);
    printf("dp[%d][1]=%lld\n", i, dp[i][1]);
    printf("dp[%d][2]=%lld\n", i, dp[i][2]);
  }*/
  if (N%2==0) {
    ans = std::max(ans, dp[N-2][0]);
    ans = std::max(ans, dp[N-1][1]);
  } else {
    ans = std::max(ans, dp[N-1][2]);
    ans = std::max(ans, dp[N-2][1]);
    ans = std::max(ans, dp[N-3][0]);
  }
  std::cout << ans << std::endl;
  return 0;
}