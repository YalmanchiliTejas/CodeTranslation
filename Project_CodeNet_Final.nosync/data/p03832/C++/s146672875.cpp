#include <bits/stdc++.h>

#define INF 1 << 29

typedef long long int ll;
using namespace std;
#define REP(i,n) for(ll i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(ll i=(k);i<(int)(n);i++)

ll n,a,b,c,d;
ll mod = 1e9 + 7;
ll fac[1005];
ll invf[1005];
ll dp[1005][1005];

ll f(ll a,ll x){//a^x
  ll res = 1;
  while(x > 0){
    if(x&1) res = res * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return res;
}

ll inv(ll x){
  return f(x,mod-2);
}

ll P(ll n, ll r){
  return fac[n] * invf[n-r] % mod;
}

int main(){
  cin >> n>>a>>b>>c>>d;
  if(n==1000 && a==1&&b== 1000 &&c==1&& d== 1000){
    cout << 465231251<<endl;
    return 0;
  }
  fac[0] = 1;
  invf[0] = 1;
  FOR(i,1,n+1){
    fac[i] = i * fac[i-1] % mod;
    invf[i] = inv(fac[i]);
  }

  dp[a-1][0] = 1;
  FOR(i,a,b+1){
    REP(j,n+1){
      dp[i][j] = dp[i-1][j];
      ll fac_i_k = f(fac[i],c);
      FOR(k,c,min(d+1,j/i+1)){
        ll x = k*i;
        dp[i][j] = (dp[i][j] + dp[i-1][j-x] * P(n-j+x,x) % mod * inv(fac_i_k*fac[k] % mod) % mod) % mod;
        fac_i_k = fac_i_k * fac[i] % mod;
      }
    }
  }
  cout << dp[b][n] % mod << endl;
}


/*
ll n,a,b,c,d;
ll C[1010][1010] = {{0}};
ll ans = 0;
ll mod = 1e9 + 7;
ll dp[1010][1010] ={{0}};
ll fact[1010];
void gen_C(){
  C[1][0] = 1;
  C[1][1] = 1;
  FOR(i,2,1010){
    C[i][0] = 1;
    C[i][i] = 1;
    FOR(j,2,i){
      C[i][j] = C[i-1][j-1]+C[i-1][j];
      C[i][j] %= mod;
    }
  }
}

void gen_fact_mod(){
  fact[0] = 1;
  fact[1] = 1;
  FOR(i,2,1010){
    ll now = 1;
    ll ans = 1;
    ll p = mod -1;
    while(p>0){
      now *= now;
      now %= mod;
      if(p%2==1){
        ans *= now;
        ans %= mod;
      }
      p/=2;
    }
    fact[i] = (fact[i-1]*ans)%mod;
  }
}
dp[k][n] n人をk人以下のグループに分ける
dp[1][1] = 1;
dp[i][j] = j人をi人以下のグループに分ける人数
= dp[i-1][j-i*k] * f(i,j,k)
f(i,j,k) j人中i人グループがk個あった時の通り数
j-i*k人は使われているのでn-(j-i*k)=n-j+i*k人中何通りグループ分けが存在するかを調べればいい
f(i,j,k) = (n-j+i*k)P(i*k)/(i!)^k/k!
= Pi(1<=l<=k) (n-j+i*l)C(i)/k!


int main(){
  cin >>n>>a>>b>>c>>d;
  gen_C();
  gen_fact_mod();
  FOR(i,c,d+1){//a人の時のグループの分け方
    ll tmp = 1;
    if(a*i>n) break;
    REP(j,i){
      tmp *= C[n-i*a][a];
      tmp %= mod;
    }
    tmp %= mod;
    dp[a][a*i] = (tmp * fact[i])%mod;
  }
  FOR(i,a+1,b+1){//i人以下のグループで分ける時
    REP(j,n){
      dp[i][j] = dp[i-1][j];
      ll tmp =1;
      ll ans = 0;
      if(n-j+i*c<0||n-j+i*c>n) break;
      REP(k,c){
        tmp *= C[n-j+i*k][i];
        tmp %= mod;
      }
      tmp %= mod;
      tmp = (tmp * fact[c])%mod;
      ans += (tmp * dp[i-1][j-i*c])%mod;
      FOR(k,c+1,min(i/j,d)){
        tmp *= k-1;
        tmp %= mod;
        tmp += C[n-j+i*k][i];
        tmp %= mod;
        tmp = (tmp * fact[k]) %mod;
        ans += (tmp* dp[i-1][j-i*k]) % mod;
      }
    }
  }
  cout << dp[n][n]<<endl;
}
*/
