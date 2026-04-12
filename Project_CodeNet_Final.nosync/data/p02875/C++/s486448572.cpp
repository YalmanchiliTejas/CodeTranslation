#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}

int nextInt() { int x; scanf("%d", &x); return x;}
ll nextLong() { ll x; scanf("%lld", &x); return x;}

const ll MOD = 998244353;

const int SZ = 11234567;
ll inv[SZ];
ll fact[SZ];
ll fact_inv[SZ];
ll choose(int n, int r) {
  if (n < 0 || r < 0 || n < r) return 0;
  return fact[n] * fact_inv[n-r] % MOD * fact_inv[r] % MOD;
}

ll two[SZ];


int main2() {
  int N = nextInt();

  ll ng = 0;
  for (int i = N/2 + 1; i <= N; i++) {
    ng += choose(N, i) * two[N - i] % MOD;
    ng %= MOD;
  }

  ll ans = 1;
  REP(i, N) ans = (ans * 3) % MOD;

  ans -= (2 * ng) % MOD;
  ans %= MOD;
  ans += MOD;
  ans %= MOD;

  cout << ans << endl;
  return 0;
}

int main() {

  inv[1] = 1;
  for (int i = 2; i < SZ; i++) inv[i] = inv[(int) (MOD % i)] * (MOD - MOD / i) % MOD;
  fact[0] = 1;
  for (int i = 1; i < SZ; i++) fact[i] = fact[i-1] * i % MOD;
  fact_inv[0] = 1;
  for (int i = 1; i < SZ; i++) fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
  two[0] = 1;
  for (int i = 1; i < SZ; i++) two[i] = two[i-1] * 2 % MOD;

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
