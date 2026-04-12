#include <bits/stdc++.h>
//#include <NTL/ZZ.h>
using namespace std;
//using namespace NTL;
typedef long long ll;
const int inf = 2147483647;

int n, mod;
int power(int x, int times, int mod) {
  int rt = 1, base = x;
  while (times) {
    if (times & 1) rt = 1LL * rt * base % mod;
    base = 1LL * base * base % mod;
    times >>= 1;
  }
  return rt;
}

const int maxn = 3000 + 7;
long long power2[maxn], super_power2[maxn];
long long f[maxn], s[maxn][maxn], g[maxn][maxn];
long long c[maxn][maxn];
int main() {
  scanf("%d%d", &n, &mod);

  for (int i = 1; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }

  power2[0] = 1;
  for (int i = 1; i <= n; i++) power2[i] = power2[i - 1] * 2 % mod;

  super_power2[0] = 1;
  for (int i = 1; i <= n; i++) super_power2[i] = super_power2[i - 1] * 2 % (mod - 1);
  for (int i = 0; i <= n; i++) super_power2[i] = power(2, super_power2[i], mod);

  s[1][1] = 1;
  for (int i = 2; i <= n; i++) 
    for (int j = 1; j <= n; j++) 
      s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * j) % mod;

  f[0] = 1;

  g[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    g[i][0] = 1;
    for (int j = 1; j <= n; j++) 
      g[i][j] = (g[i - 1][j - 1] + g[i - 1][j] * j + g[i - 1][j]) % mod;
    long long cur = 1;
    for (int j = 0; j <= n; j++) {
      f[i] = (f[i] + g[i][j] * cur) % mod;
      cur = (cur * power2[n - i]) % mod;
    }
      //f[i] = (f[i] + g[i][j] * power(power2[n - i], j, mod)) % mod;
      //f[i] = (f[i] + g[i][j] * super_power2[n - i]) % mod;
  }
  

  //cout << f[n] << endl;
  for (int i = 0; i <= n; i++) 
    f[i] = f[i] * (super_power2[n - i]) % mod;

  //for (int i = 0; i <= n; i++) cout << f[i] << ' ';
  //cout << endl;

  int flag = 1;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = (ans + flag * c[n][i] * f[i]) % mod;
    flag = -flag;
  } 
  cout << (ans + mod) % mod << endl;
  return 0;
}