#include <cstdio>
#include <iostream>
#include <algorithm>

// Definitions
#define MAXN 200010
#define MOD (int64)1000000007
#define elif else if
typedef long long int64;
typedef long double num128;
typedef unsigned long long uint64;

#define PUTLINE printf("[%d] current line.\n", __LINE__)
#define STARTFUNC printf("[%s] function start.\n", __FUNCTION__)
#define File(s) freopen(#s".in", "r", stdin), freopen(#s".out","w", stdout)

// Improve the speed of read-in.
inline bool IsNum(char x) { return ('0' <= x) && (x <= '9'); }
inline int64 ReadNum() {
  int64 sign = 1, val = 0; char tmp = getchar();
  while (!IsNum(tmp)) { if (tmp == '-') {sign = -sign;} tmp = getchar(); }
  while (IsNum(tmp)) { val = val * 10 + tmp - 48; tmp = getchar(); }
  return val * sign;
}

// Variables
int n;
int64 ans,
      a[MAXN], pfxsum[MAXN];

// Functions
inline void Initialize(bool prgmsta) {
  if (!prgmsta) {
    
  } else {
    
  }
}
inline void Process() {
  for (int i = 1; i < n; i++)
    ans += a[i] * pfxsum[i + 1] % MOD,
    ans %= MOD;
}
inline void ReadIn() {
  n = ReadNum();
  for (int i = 1; i <= n; i++)
    a[i] = ReadNum() % MOD;
  for (int i = n; i; i--)
    pfxsum[i] = pfxsum[i + 1] + a[i],
    pfxsum[i] %= MOD;
}
inline void PrintAns() {
  printf("%lld\n", ans % MOD);
}

int main() {
  #ifndef ONLINE_JUDGE
    File(data);
  #endif
  Initialize(0);
  ReadIn();
  Initialize(1);
  Process();
  PrintAns();
  return 0;
}
/*

*/
