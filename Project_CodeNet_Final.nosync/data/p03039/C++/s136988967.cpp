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

const ll MOD = (ll)(1e9 + 7);
const int SZ = 312345;
ll inv[SZ];
ll fact[SZ];
ll fact_inv[SZ];
ll choose(int n, int r) {
  if (n < 0 || r < 0 || n < r) return 0;
  return fact[n] * fact_inv[n-r] % MOD * fact_inv[r] % MOD;
}

ll solve(int N, int M, int K) {
  ll res = 0;
  for (int m = 0; m < M; m++) {
    res += (ll)m*(m+1)/2;
  }
  (res *= N) %= MOD;
  (res *= N) %= MOD;
  (res *= choose(N*M -2, K-2)) %= MOD;
  return res;
}


int main2() {
  int N = nextInt();
  int M = nextInt();
  int K = nextInt();

  ll ans = 0;
  ans += solve(N, M, K);
  ans += solve(M, N, K);
  ans %= MOD;
  cout << ans << endl;
  return 0;
}

int main() {

{
  inv[1] = 1;
  for (int i = 2; i < SZ; i++) inv[i] = inv[(int) (MOD % i)] * (MOD - MOD / i) % MOD;
  fact[0] = 1;
  for (int i = 1; i < SZ; i++) fact[i] = fact[i-1] * i % MOD;
  fact_inv[0] = 1;
  for (int i = 1; i < SZ; i++) fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
}


#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
