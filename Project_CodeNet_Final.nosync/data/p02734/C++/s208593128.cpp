#include <bits/stdc++.h>
 
using namespace std;
using LL = long long int; 

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MAXN = 1e6;

int n, s;
LL dp[MAXN];
LL mod = 998244353;
int t[MAXN];

int main() {
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }

  LL res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 3000; j >= 0; --j) {
      if (dp[j] != 0) {
        dp[j + t[i]] += dp[j] % mod;
      }
    }
    dp[t[i]] += i;
    dp[t[i]] % mod;
    res += dp[s] % mod;
  }
  cout << res % mod << endl;
}
