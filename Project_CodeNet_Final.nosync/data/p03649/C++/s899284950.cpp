
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
#include <array>
#include <bitset>

long long mod = 1e9 + 7;
class Mint
{
public:
  long long x;
  Mint(){}; // 引数なしでも定義できるように引数なしコンストラクタも用意しておく
  Mint(long long a)
  {
    x = a % mod;
    while (x < 0)
    {
      x += mod;
    }
  };
  Mint &operator+=(const Mint &a)
  {
    x += a.x;
    x %= mod;
    return *this;
  }
  Mint &operator-=(const Mint &a)
  {
    x += (mod - a.x);
    x %= mod;
    return *this;
  }
  Mint &operator*=(const Mint &a)
  {
    x *= a.x;
    x %= mod;
    return *this;
  }

  // a^n mod を計算する
  // Useaeg: Mint z = Mint(2).pow(n);
  Mint pow(long long n) const
  {
    if (n == 0)
      return Mint(1);
    Mint y = pow(n >> 1); // pow(n/2)を計算する
    y *= y;
    if (n % 2 == 1)
      y *= *this;
    return y;
  }

  // a^{-1} mod を計算する
  Mint modinv(const Mint &a) const
  {
    return a.pow(mod - 2);
  }

  Mint &operator/=(const Mint &a)
  {
    x *= modinv(a).x;
    x %= mod;
    return *this;
  }

  Mint operator+(Mint &a) const
  {
    Mint y(*this);
    y += a;
    return y;
  }

  Mint operator-(Mint &a) const
  {
    Mint y(*this);
    y -= a;
    return y;
  }

  Mint operator*(Mint &a) const
  {
    Mint y(*this);
    y *= a;
    return y;
  }

  Mint operator/(Mint &a) const
  {
    Mint y(*this);
    y /= a;
    return y.x;
  }
};
  // nCk @mod を計算する
Mint nCk(Mint &n, const long long k)
{
  Mint y = Mint(1);
  Mint iy = Mint(1);
  Mint one = Mint(1);
  // 割り算の演算は時間がかかるので最後に1度だけ行うようにすること
  for (Mint i(0); (i.x) < k; i.x++)
  {
    y *= (n - i);
    iy *= (i + one);
  }
  return y / iy;
}

// nPk @mod を計算する
Mint nPk(Mint &n, long long k)
{
  Mint y(1);
  for (Mint i(0); (i.x) < k; i.x++)
  {
    y *= (n - i);
  }
  return y;
}

class UnionFind
{
private:
  int n;
  std::vector<int> parent;

public:
  UnionFind(int num) : n(num)
  {
    parent = std::vector<int>(n);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }
  int GetRoot(int i)
  {
    int n = i;
    while (parent[n] != n)
    {
      n = parent[n];
    }
    parent[i] = n;
    return n;
  }

  bool SameGroup(int n, int m)
  {
    n = this->GetRoot(n);
    m = this->GetRoot(m);
    return n == m;
  }

  bool Unite(int n, int m)
  {
    n = this->GetRoot(n);
    m = this->GetRoot(m);
    if (n == m)
      return false;
    parent[n] = m;
    return true;
  }
};

int getgcd(int a, int b)
{
  int max = std::max(a, b);
  int min = std::min(a, b);
  if (min == 0)
    return max;
  return getgcd(min, max % min);
}

Mint nCk_pascar[5000][5000];
// nの値までのnCkをパスカルの三角形から求めておく
void Calc_nCk_pascar(int n){
  for (int i=0; i<=n; i++) {
    for (int j=0; j<=i; j++) {
      if (j==0 || j==i) nCk_pascar[i][j] = Mint(1);
      else nCk_pascar[i][j] = nCk_pascar[i-1][j-1] + nCk_pascar[i-1][j];
    }
  }
  return;
}

Mint mynCk(int n, int k)
{
  if (2 * k > n)
    return mynCk(n, n - k);
  Mint retval(1);
  Mint iretval(1);
  for (int i = 0; i < k; i++)
  {
    retval *= Mint(n - i);
  }
  for (int i = 1; i <= k; i++)
  {
    iretval *= Mint(i);
  }
  return retval / iretval;
}

int main()
{
  int N;
  std::cin >> N;
  std::vector<long long> a(N);
  long long sum = 0;
  for (int i=0; i<N; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  long long num = std::max((long long)0, sum - N*(N-1));
  auto check = [&](long long m) {
    long long cnt = 0;
    for (int i=0; i<N; i++) {
      cnt += std::max((long long)0, (a[i]+num-m+N)/(N+1));
    }
    return cnt <= num;
  };
  long long min = -1, max = 1e18+5;
  while(max-min>1) {
    long long mid = (min+max)/2;
    if (check(mid)) {
      max = mid;
    } else {
      min = mid;
    }
  }
  // printf("num=%lld, max=%lld\n", num,max);
  long long cnt = 0;
  for (int i=0; i<N; i++) {
    a[i]+=num;
    cnt += (a[i]-max+N)/(N+1);
    a[i] = a[i] - ((a[i]-max+N)/(N+1)) * (N+1);
  }
  while(cnt<num) {
    int maxindex;
    int maxa=-1;
    for (int i=0; i<N; i++) {
      if (maxa<a[i]) {
        maxa = a[i];
        maxindex = i;
      }
    }
    a[maxindex] -= N+1;
    cnt++;
  }
  while(true) {
    bool ok = true;
    for (int i=0; i<N; i++) {
      if (a[i]>=N) {
        ok = false;
        break;
      }
    }
    if (ok) {
      std::cout << cnt << std::endl;
      break;
    }
    int maxindex;
    int maxa=-1;
    for (int i=0; i<N; i++) {
      if (maxa<a[i]) {
        maxa = a[i];
        maxindex = i;
      }
    }
    a[maxindex] -= N;
    for (int i=0; i<N; i++) {
      if (i==maxindex) continue;
      a[i]++;
    }
    cnt++;
  }
  return 0;
}