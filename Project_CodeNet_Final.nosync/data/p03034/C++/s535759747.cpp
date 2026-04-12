
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;

ll vs[100000+10];
int n;

vector<ll> cs[100000+10];
vector<ll> cs2[100000+10];

vector<int> memoDs[100000+10];
vector<int> calcDs(int v) {
  vector<int> &ds = memoDs[v];
  if(ds.empty()) {
    for(int d = 1; d*d <= v; ++d) {
      if(v % d == 0) {
        ds.push_back(d);
        if(d*d != v) {
          ds.push_back(v/d);
        }
      }
    }
  }
  return ds;
}

ll calc(int a, int b) {
  if(a <= b) {
    // cerr << "HOGE" <<  " " << a << " " << b << endl;
    return -1;
  }
  if((n-1-b) % (a-b) != 0) {
    // cerr << "HOGE2" <<  " " << a << " " << b << endl;
    return -1;
  }
  ll k = (n-1-b) / (a-b);
  if(b % (a-b) == 0) {
    ll x = b / (a-b) + 1;
    if(x <= k-1) {
      // cerr << "HOGE3" <<  " " << a << " " << b << endl;
      return -1;
    }
  }
  // 落ちずに到着できる。
  ll res = 0;
  res += cs2[a-b][k-1];
  res += cs[a-b][k-1];
  // cerr << ">" << a << " " << b << " " << res << endl;
  return res;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%lld", &vs[i]);
  }
  for(int i = 1; i <= n; ++i) {
    ll cur = 0;
    cs[i].push_back(cur);
    for(int j = i; j < n; j += i) {
      cur += vs[j];
      cs[i].push_back(cur);
    }
  }
  for(int i = 1; i < n; ++i) {
    ll cur = 0;
    cs2[i].push_back(cur);
    for(int j = n-1-i; j >= 0; j -= i) {
      cur += vs[j];
      cs2[i].push_back(cur);
    }
  }

  ll res = 0;
  // for(int a = 2; a <= n-1; ++a) {
  //   int rem = (n-1) % a;
  //   if(rem == 0) {
  //     continue;
  //   }
  //   vector<int> ds = calcDs(rem);
  //   for(int d : ds) {
  //     int b = a - d;
  //     ll cur = calc(a, b);
  //     res = max(res, cur);
  //   }
  // }
  for(int b = 1; b <= n-1; ++b) {
    vector<int> ds = calcDs(n-1-b);
    for(int d : ds) {
      int a = b + d;
      ll cur = calc(a, b);
      res = max(res, cur);
    }
  }
  cout << res << endl;
  return 0;
}
