#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cctype>
#include <numeric>
using namespace std;

#define REP(i,b,n) for(int (i)=b; (i)<(int)(n); ++(i))
#define rep(i,n) REP(i,0,n)
#define foreach(c,i) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define all(a) (a).begin(),(a).end()
#define print(var) cout<<#var":"<<(var)<<endl;
#define printkv(key,var) cout<<#key":"<<(var)<<endl;
#define updatemax(dst,src) dst=max(dst,src);
#define updatemin(dst,src) dst=min(dst,src);

typedef long long ll;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
  if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int N;
string s[52];

string solve() {
  int mincnt[30];
  int cnt[30];

  rep(i,30) mincnt[i] = 100;

  rep(i,N) {
    memset(cnt, 0, sizeof cnt);
    int M = s[i].size();
    rep(j,M) {
      cnt[ s[i][j] - 'a' ]++;
    }
    rep(j,30) {
      mincnt[j] = min(mincnt[j], cnt[j]);
    }
  }

  string ret;
  rep(i,30) {
    rep(j,mincnt[i]) {
      ret += ('a' + i);
    }
  }

  return ret;
}

int main() {
  while (cin>>N) {
    rep(i,N) cin>>s[i];
    cout<<solve()<<endl;
  }
  return 0;
}
