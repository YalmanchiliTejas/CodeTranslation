/*  -*- coding: utf-8 -*-
 *
 * g.cc: G: Coinage
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

/* typedef */

typedef long long ll;

/* global variables */

/* subroutines */

// exgcd:
//   For given x>0 and y>0, solve a, b, c such that ax+by=c (=gcd(x,y))

void exgcd(int x, int y, int &a, int &b, int &c) {
  int r0 = x, r1 = y;
  int a0 = 1, a1 = 0;
  int b0 = 0, b1 = 1;

  while (r1 > 0) {
    int q1 = r0 / r1;
    int r2 = r0 % r1;
    int a2 = a0 - q1 * a1;
    int b2 = b0 - q1 * b1;
    r0 = r1, r1 = r2;
    a0 = a1, a1 = a2;
    b0 = b1, b1 = b2;
  }
  c = r0;
  a = a0;
  b = b0;
}

/* main */

int main() {
  int l;
  string s, t;
  cin >> l >> s >> t;

  int sn = s.size(), tn = t.size();
  int a, b, c;
  exgcd(sn, tn, a, b, c);
  ll da = tn / c, db = sn / c;
  //printf("%d,%d -> a,b,c=%d,%d,%d\n", sn, tn, a, b, c);
  ll aa = (ll)a * l / c, bb = (ll)b * l / c;
  //printf("-> %lld,%lld,%d (%lld,%lld)\n", aa, bb, l, da, db);
  
  if (s + t < t + s) {
    if (bb < 0) {
      ll d = (-bb + db - 1) / db;
      bb += db * d;
      aa -= da * d;
    }
    else if (bb > 0) {
      ll d = bb / db;
      bb -= db * d;
      aa += da * d;
    }
    for (int i = 0; i < aa; i++) cout << s;
    for (int i = 0; i < bb; i++) cout << t;
    cout << endl;
  }
  else {
    if (aa < 0) {
      ll d = (-aa + da - 1) / da;
      aa += da * d;
      bb -= db * d;
    }
    else if (aa > 0) {
      ll d = aa / da;
      aa -= da * d;
      bb += db * d;
    }
    for (int i = 0; i < bb; i++) cout << t;
    for (int i = 0; i < aa; i++) cout << s;
    cout << endl;
  }
  //printf("a=%d, b=%d\n", a, b);

  return 0;
}
