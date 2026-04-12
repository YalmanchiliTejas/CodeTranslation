#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
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
const long long MOD = 1000000LL;

/* typedef */

typedef long long ll;
typedef unsigned char uchar;

/* global variables */

int n;
uchar bytes[MAX_N], masks[MAX_N];
ll dp[MAX_N + 1];
int bcs[256];

/* subroutines */

void str2bits(string str, uchar& byte, uchar& mask) {
  byte = mask = 0;
  for (int i = 7, b = 1; i >= 0; i--, b <<= 1) {
    if (str[i] == 'x') mask |= b;
    else if (str[i] == '1') byte |= b;
  }
}

int bcount(uchar bits) {
  int count = 0;
  for (; bits > 0; bits >>= 1)
    if (bits & 1) count++;
  return count;
}

ll utf8_1(int i) {
  if (i > n - 1 ||
      (bytes[i] & 0x80) != 0) return 0LL;
  uchar m0 = masks[i] & 0x7f;
  return (1LL << bcs[m0]);
}

ll utf8_2(int i) {
  if (i > n - 2 ||
      (bytes[i] & 0xe0) != (0xc0 & ~masks[i]) ||
      (bytes[i + 1] & 0xc0) != (0x80 & ~masks[i + 1])) return 0LL;

  int ybc = bcs[bytes[i] & 0x1e];
  int ymc = bcs[masks[i] & 0x1e];
  if (ybc == 0 && ymc == 0) return 0LL;

  ll yn = 1LL << ymc;
  if (ybc == 0) yn--;
  
  uchar m0 = masks[i] & 0x01;
  uchar m1 = masks[i + 1] & 0x3f;
  return yn * (1LL << (bcs[m0] + bcs[m1]));
}

ll utf8_3(int i) {
  if (i > n - 3 ||
      (bytes[i] & 0xf0) != (0xe0 & ~masks[i]) ||
      (bytes[i + 1] & 0xc0) != (0x80 & ~masks[i + 1]) ||
      (bytes[i + 2] & 0xc0) != (0x80 & ~masks[i + 2])) return 0LL;

  int ybc = bcs[bytes[i] & 0x0f] + bcs[bytes[i + 1] & 0x20];
  int ymc = bcs[masks[i] & 0x0f] + bcs[masks[i + 1] & 0x20];
  if (ybc == 0 && ymc == 0) return 0LL;

  ll yn = 1LL << ymc;
  if (ybc == 0) yn--;
  
  uchar m1 = masks[i + 1] & 0x1f;
  uchar m2 = masks[i + 2] & 0x3f;
  return yn * (1LL << (bcs[m1] + bcs[m2]));
}

ll utf8_4(int i) {
  if (i > n - 4 ||
      (bytes[i] & 0xf8) != (0xf0 & ~masks[i]) ||
      (bytes[i + 1] & 0xc0) != (0x80 & ~masks[i + 1]) ||
      (bytes[i + 2] & 0xc0) != (0x80 & ~masks[i + 2]) ||
      (bytes[i + 3] & 0xc0) != (0x80 & ~masks[i + 3])) return 0LL;

  int ybc = bcs[bytes[i] & 0x07] + bcs[bytes[i + 1] & 0x30];
  int ymc = bcs[masks[i] & 0x07] + bcs[masks[i + 1] & 0x30];
  if (ybc == 0 && ymc == 0) return 0LL;

  ll yn = 1LL << ymc;
  if (ybc == 0) yn--;
  
  uchar m1 = masks[i + 1] & 0x0f;
  uchar m2 = masks[i + 2] & 0x3f;
  uchar m3 = masks[i + 3] & 0x3f;
  return yn * (1LL << (bcs[m1] + bcs[m2] + bcs[m3]));
}

/* main */

int main() {
  for (int b = 0; b < 256; b++) bcs[b] = bcount((uchar)b);

  for (;;) {
    cin >> n;
    if (n == 0) break;

    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      str2bits(str, bytes[i], masks[i]);
      //cout << str; printf("=%x/%x\n", bytes[i], masks[i]);
    }

    memset(dp, 0, sizeof(dp));
    dp[n] = 1LL;

    for (int i = n - 1; i >= 0; i--) {
      dp[i] = (dp[i] + utf8_1(i) * dp[i + 1]) % MOD;
      if (i < n - 1) dp[i] = (dp[i] + utf8_2(i) * dp[i + 2]) % MOD;
      if (i < n - 2) dp[i] = (dp[i] + utf8_3(i) * dp[i + 3]) % MOD;
      if (i < n - 3) dp[i] = (dp[i] + utf8_4(i) * dp[i + 4]) % MOD;
    }

    cout << dp[0] << endl;
  }

  return 0;
}