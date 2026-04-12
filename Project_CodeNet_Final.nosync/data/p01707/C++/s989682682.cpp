#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;
ll dp[2][2020];

ll extgcd(ll a, ll b, ll &x, ll &y){
  ll d = a;
  if(b){
    d = extgcd(b,a%b,y,x);
    y -= (a/b)*x;
  }else{
    x = 1; y = 0;
  }
  return d;
}

ll mod_inv(ll a){
  ll x,y;
  extgcd(a,mod,x,y);
  return (mod+x%mod)%mod;
}

ll mod_comb(ll n, ll k){
  if(k<0 || n<k)return 0;
  ll res = 1;
  rep(i,k){
    (res *= (n-i)%mod) %= mod;
    (res *= mod_inv(i+1)) %= mod;
  }
  return res;
}

int main(){
  ll n,d,x;
  while(cin >> n >> d >> x, n){
    x--;
    if(x*d<n){ cout << 0 << endl; continue; }
    rep(i,n+1)dp[0][i] = 0; dp[0][0] = 1;

    ll ans = 0;
    rep(i,n){
      int cur = i&1, nxt = 1-cur, sum = 0;
      rep(j,n+1)dp[nxt][j] = 0;

      rep(j,n){
	(sum += dp[cur][j]) %= mod;
	if(j>=x)(sum += mod-dp[cur][j-x]) %= mod;
	dp[nxt][j+1] = sum;
      }
      if(i<d){
	(ans += dp[nxt][n] * mod_comb(d,i+1)) %= mod;
      }
    }
    cout << ans << endl;
  }
}