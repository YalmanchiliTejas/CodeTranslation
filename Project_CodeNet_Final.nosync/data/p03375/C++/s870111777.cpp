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

ll MOD;

const int SZ = 312345;
ll inv[SZ];
ll fact[SZ];
ll fact_inv[SZ];
ll choose(int n, int r) {
  if (n < 0 || r < 0 || n < r) return 0;
  return fact[n] * fact_inv[n-r] % MOD * fact_inv[r] % MOD;
}


ll mod_pow(ll a, ll b, ll p) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

ll memoP[3010][3010];
ll P(int k, int r) {
  if (k == 0 && r == 0) return 1;
  if (k > 0 && r == 0) return 1;
  if (k < r) return 0;
  if (memoP[k][r] != -1) return memoP[k][r];
  ll res = 0;
  res += P(k-1, r-1);
  res += P(k-1, r) * (r+1) % MOD;
  res %= MOD;
  return memoP[k][r] = res;
}

ll ways2(const int N, const int k, const int r) {
  ll t = ((N-k)*r + mod_pow(2, N-k, MOD-1)) % (MOD-1);
  ll res = P(k, r) * mod_pow(2, t, MOD) % MOD;
  return res;
}

ll ways(const int N, const int k) {
  ll res = 0;
  for (int r = 0; r <= k; r++) {
    (res += ways2(N, k, r)) %= MOD;
  }
  return res;
}

int main2() {
  CLR(memoP, -1);
  int N = nextInt();
  MOD = nextInt();
  {
    inv[1] = 1;
    for (int i = 2; i < SZ; i++) inv[i] = inv[(int) (MOD % i)] * (MOD - MOD / i) % MOD;
    fact[0] = 1;
    for (int i = 1; i < SZ; i++) fact[i] = fact[i-1] * i % MOD;
    fact_inv[0] = 1;
    for (int i = 1; i < SZ; i++) fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
  }

  ll ans = 0;
  for (int k = 0; k <= N; k++) {
    int f = (k % 2 == 0 ? +1 : -1); 
    ll add = f * choose(N, k) % MOD * ways(N, k) % MOD;
    // cout << add << endl;
    add = (add % MOD + MOD) % MOD;
    (ans += add) %= MOD;
  }
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
