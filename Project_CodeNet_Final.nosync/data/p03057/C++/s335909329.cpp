#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int P = 1e9 + 7;
const int inf = 1e9;
int mul(int a,int b){
  return a * b % P;
}
void add(int &a, int b){
  a += b;
  if(a >= P)
    a -= P;
}

void sub(int &a, int b){
  a -= b;
  if(a < 0)
    a += P;
}

int licz(int n,int lim){
  debug(n,lim);
  vector<int> dp(n + 1);
  dp[0] = 1;
  dp[1] = 1;
  for(int i = 1;i < n;i++){
    add(dp[i + 1], dp[i]);
    add(dp[i + 1], dp[i]);
    if(i > lim){
      sub(dp[i + 1], dp[i - lim - 1]);
    }
  }
  debug(dp);
  int res = 0;
  R(i, lim + 1){
    add(res, mul(dp[n - 1 - i], i + 1));
  }
  return res;
}
int n,m;
string s;
void nope(){
  cout << "0\n";
  exit(0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> s;
  if(s[0] == 'B'){
    for(char& el:s)
      el = 'R' + 'B' - el;
  }
  int naj = inf;
  int ak = 0;
  bool czB = 0;
  R(i,m)if(s[i] == 'R'){
    ak++;
  }else{
    if(!czB || ak&1){
      mini(naj, ak);
    }
    czB = 1;
    ak = 0;
  }
  if(!czB){
    cout << licz(n, 1) << "\n";
  }else{
    if(n&1)nope();
    cout << mul(2, licz(n / 2, naj / 2)) << "\n";
  }
}
