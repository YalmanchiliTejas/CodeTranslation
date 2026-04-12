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

ll MOD;

const int SZ = 5005;
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

const int MAX_N = 5010;
ll dp[MAX_N][MAX_N];

ll ways(int N, int i) {

  ll res = 0;
  for (int j = 0; j <= i; j++) {
    res += dp[i][j] * mod_pow(2, (N-i)*j, MOD);
    res %= MOD;
    // cout << "ways2(" << j << ")" << res << endl;
  }

  ll mm = 1;
  REP(p, N-i) mm = (mm * 2) % (MOD - 1);
  res *= mod_pow(2, mm, MOD);
  res %= MOD;

  // cout << "ways(" << N << "," << i << ")=" << res << endl;
  return res;
}


int main2() {
  int N; cin >> N;
  cin >> MOD;

  inv[1] = 1;
  for (int i = 2; i < SZ; i++) inv[i] = inv[(int) (MOD % i)] * (MOD - MOD / i) % MOD;
  fact[0] = 1;
  for (int i = 1; i < SZ; i++) fact[i] = fact[i-1] * i % MOD;
  fact_inv[0] = 1;
  for (int i = 1; i < SZ; i++) fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;

  CLR(dp, 0);

  for (int i = 0; i <= N; i++) dp[i][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = ((j+1) * dp[i-1][j] + dp[i-1][j-1]) % MOD;
    }
  }

  ll ans = 0;
  for (int i = 0; i <= N; i++) {
    ll sub_i = choose(N, i) * ways(N, i);
    ans += (i % 2 == 0 ? +1 : -1) * sub_i;
    ans = (ans % MOD + MOD) % MOD;
  }
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
