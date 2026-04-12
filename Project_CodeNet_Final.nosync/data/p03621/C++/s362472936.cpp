#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const modulo = 998244353;
int fact[1 + nmax], quick[1 + nmax];

void gcd(int a, int b, int &x, int &y) {
  if(b == 0) {
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
    int aux = x;
    x = y;
    y = aux - a/ b * y;
  }
}

int inverse(int number) {
  int x, y;
  gcd(number, modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return x;
}

void precompute() {
  fact[0] = 1;
  for(int i = 1;i <= nmax; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
  for(int i = 0; i <= nmax; i++)
    quick[i] = inverse(fact[i]);
}

/*
The paths have lengths:
a1, a2 ... ak
a1 + a2 + ... ak + empt = n

The number of solutions is
(n + k)! / ((a1 + 1)! * (a2 + 1)! * ... (ak + 1)!) * n! 
^
chosing the positions in permutations; ^ choosing the ids
*/

int const lgmax = 14;
class dp{
public:
  std::vector<int> vp;
  void setsize(int n) {
    vp.resize(n);
  }
  dp operator * (dp a) {
    dp result;
    int n = vp.size();
    result.setsize(n);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n - i; j++) {
        result.vp[i + j] += 1LL * vp[i] * a.vp[j] % modulo;
        if(modulo <= result.vp[i + j])
          result.vp[i + j] -= modulo;
      }
    return result;
  }
} powp[1 + lgmax];

int main() {
  precompute();

  std::string a, b;
  std::cin >> a >> b;
  int n = 0, k = 0;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] == '1') {
      if(b[i] == '1')
        n++;
      else
        k++;
    }
  }
  if(k == 0) {
    std::cout << 1LL * fact[n] * fact[n] % modulo;
    return 0;
  }
  

  int lim = n + 1;
  powp[0].setsize(lim);
  for(int i = 0; i < lim; i++)
    powp[0].vp[i] = quick[i + 1];
  for(int i = 1; i < lgmax; i++)
    powp[i] = powp[i - 1] * powp[i - 1];
  dp result = powp[0];
  int k2 = k;
  k2--;
  for(int i = lgmax - 1; 0 <= i; i--) {
    if((1 << i) <= k2) {
      k2 -= (1 << i);
      result = result * powp[i];
    }
  }

  int total = 0;
  for(int i = 0; i < lim; i++) {
    total += 1LL * fact[n] * fact[n + k] % modulo * result.vp[i] % modulo;
    if(modulo <= total)
      total -= modulo;
  }
  std::cout << 1LL * total * fact[k] % modulo;
  return 0;
}
