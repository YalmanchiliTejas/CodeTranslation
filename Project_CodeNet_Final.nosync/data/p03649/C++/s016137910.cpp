
#include <cstdio>
#include <algorithm>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;

ll vs[55];
int n;

ll go(void) { // 手順通りやる
  ll maxi = 0;
  int idx = -1;
  REP(i, n) {
    if(vs[i] > maxi) {
      maxi = vs[i];
      idx = i;
    }
  }
  vs[idx] -= n;
  REP(i, n) {
    if(i != idx) {
      ++vs[i];
    }
  }
  return 1;
}

ll go2(void) { // 最大の箇所から、n+1手でn+1減らす、というのを十分小さくなるまで一気にやる
  ll maxi = 0;
  int idx = -1;
  REP(i, n) {
    if(vs[i] > maxi) {
      maxi = vs[i];
      idx = i;
    }
  }
  ll cnt = vs[idx] / (n+1);
  ll res = cnt * (n+1);
  vs[idx] -= cnt * (n+1);
  return res;
}

bool toContinue1(void) { // 全ての箇所がn-1以下なら終わる
  REP(i, n) {
    if(vs[i] > n-1) {
      return true;
    }
  }
  return false;
}

bool toContinue2(void) { // 全ての箇所がn-1以上になるまでやる
  REP(i, n) {
    if(vs[i] < n-1) {
      return true;
    }
  }
  return false;
}

bool toContinue3(void) { // 全ての箇所がn以下になるまでやる
  REP(i, n) {
    if(vs[i] > n) {
      return true;
    }
  }
  return false;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%lld", &vs[i]);
  }

  ll res = 0;
  while(toContinue1()) { // 全ての箇所がn-1以下になるまでやる
    if(toContinue2()) { // 「全ての箇所がn-1以上である」でない
      // cerr << "> a" << endl;
      res += go();
    } else if(toContinue3()){ // 「全ての箇所がn以下である」でない
      // cerr << "> b" << endl;
      res += go2();
    } else {
      // cerr << "> c" << endl;
      res += go();
    }
  }

  printf("%lld\n", res);
  
  return 0;
}
