#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;
template <class T> inline void chmax(T &a, const T b) { a = max(a, b); }
template <class T> inline void chmin(T &a, const T b) { a = min(a, b); }
template <class T> void pp(T v, int n) { REP(i,n) cout<<v[i]<< ' '; cout << endl; }
const ll MOD = 1000 * 1000 * 1000 + 7 ;
inline void chadd(ll &a, const ll b) { a = (a + b) % MOD;}
inline ll add(const ll a, const ll b){ return (a + b) %  MOD;}
inline void chsub(ll &a, const ll b) { a = (a - b + MOD) % MOD;}
inline ll sub(const ll a, const ll b){ return (a - b + MOD) % MOD; }
inline void chmul(ll &a, const ll b) { a = (a * b) %  MOD;}
inline ll mul(const ll a, const ll b){ return (a * b) %  MOD;}
const int MOD_TABLE_SIZE = 2000000 + 10;
ll inv[MOD_TABLE_SIZE];
ll fac[MOD_TABLE_SIZE];
ll facinv[MOD_TABLE_SIZE];

void mod_table_init() {
  inv[1] = 1;
  for(int i = 2; i < MOD_TABLE_SIZE; i++) {
    inv[i] = MOD - (MOD / i) * inv[(int)MOD % i] % MOD;
  }
  fac[0] = facinv[0] = 1;
  for(int i = 1; i < MOD_TABLE_SIZE; i++) {
    fac[i] = (fac[i-1] * (ll)i) % MOD;
    facinv[i] = (facinv[i-1] * inv[i]) % MOD;
  }
}

inline ll P(int a, int b) {
  return fac[a] *  facinv[a-b] % MOD;
}

inline ll C(int a, int b) {
  return (fac[a] * facinv[b] % MOD) * facinv[a-b] % MOD;
}

inline ll H(int a, int b) {
  return C(a+b-1,b);
}

void inline TorF(bool tf, const string &trueMessage, const string &falseMessage) { 
  cout << (tf ? trueMessage : falseMessage) << endl;
}
void inline YESNO(bool tf) { TorF(tf, "YES", "NO"); }
void inline YesNo(bool tf) { TorF(tf, "Yes", "No"); }

int main() {
  mod_table_init();
  int N, M; cin>>N>>M;
  ll K; cin>>K;
  ll ans = 0;
  for(int i = 1; i < N; i++) {
    ll tmp = N-i;
    chmul(tmp, i);
    chmul(tmp, M);
    chmul(tmp, M);
    chadd(ans, tmp);
  }
  //  cout << ans << endl;
  for(int i = 1; i < M; i++) {
    ll tmp = M-i;
    chmul(tmp, i);
    chmul(tmp, N);
    chmul(tmp, N);
    chadd(ans, tmp);
  }
  //  cout << ans << endl;
  ll comb = C(N*M-2, K-2);
  //  cout << ans << "," << comb << endl;
  chmul(ans, comb);
  cout << ans << endl;
  return 0;
}
