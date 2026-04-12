#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<double,ll,ll>T;
#define PI 3.14159265358979
const int MAX = 510000;
const int MOD = 1000000007;
//この設定だとn<10^7が限界。maxの０を一個増やせば100msかかるが一桁増やせる。
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll ans=0ll;
void solve(ll n,ll x){
  if(n==1ll){
  	if(x<=4){::ans+=(x-1ll);return;}
    else{::ans+=3ll;return;}
  }
  if(x==1ll){return;}
  if(x<=((ll)pow(2ll,n+1ll)-2ll)){
  	solve(n-1,x-1ll);return;
  }
  if(x==((ll)pow(2ll,n+1ll)-1ll)){
  	::ans+=((ll)pow(2ll,n)-1ll);
    ans++;
    return;
  }
  if(x==((ll)pow(2ll,n+2ll)-3ll)){
  	::ans+=2ll*((ll)pow(2ll,n)-1ll);
    ans++;//まんなかのぶん
    return;
  }
  	::ans+=((ll)pow(2ll,n)-1ll);
  	ans++;
  	x-=((ll)pow(2ll,n+1ll)-1ll);
  	solve(n-1,x);return;
}

int main(){
  ll N,X;
  cin>>N>>X;
  solve(N,X);
  cout<<::ans;
} 
