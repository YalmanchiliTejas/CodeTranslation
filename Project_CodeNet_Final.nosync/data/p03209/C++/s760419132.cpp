#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

long long sum[51], p[51];

long long rec(long long n, long long x) {
  if (n == 0) {
    if (x >= 1) return 1;
    else return 0;
  }
  if (sum[n-1] + 1 < x) {
    return p[n-1] + 1 + rec(n-1, x-2-sum[n-1]);
  } else {
    return rec(n-1, x-1);
  }
}

int main() {
  long long n, x; cin>>n>>x;
  sum[0] = 1, p[0] = 1;;
  rep(i, 50) {
    sum[i+1] = 3 + 2*sum[i];
    p[i+1] = 1 + 2*p[i];
  }
  print(rec(n, x));

  return 0;
}