#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<utility>
using namespace std;
using ll = long long;

const ll MOD=1e9+7;
const ll MAX=200010;
const ll MAX_P=200010;
ll fact[MAX_P];
void make_fact(){
  fact[0]=fact[1]=1;
  for(ll i=2;i<MAX_P;i++){
    fact[i]=(fact[i-1]*i)%MOD;
  }
}
ll Extgcd(ll a,ll b,ll &x,ll &y){
  ll d=a;
  if(b!=0){
    Extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }
  else{
    x=1;y=0;
  }
  return d;
}

ll mod_inv(ll a,ll p){//mod pでのaの逆元を求める
  ll x,y;
  Extgcd(a,p,x,y);
  return (x%p+p)%p;
}
//n!=a*p^e (a,p互いに素,p素数) とした時のeとa mod p を求める
ll mod_fact(ll n,ll p,ll& e){
  e=0;
  if(n==0) return 1;
  
  ll res=mod_fact(n/p,p,e);
  e+=n/p;

  if(n/p%2!=0) return res*(p-fact[n%p])%p;
  return res*fact[n%p]%p;
}

//nCk mod pを求める
ll mod_comb(ll n,ll k,ll p){
  if(n<0||k<0||n-k<0) return 0;
  ll e1,e2,e3;
  ll a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inv(a2*a3%p,p)%p;
}

int main(){
    make_fact();
    ll n,m,k;
    ll ans,temp=0;
    cin >> n >> m >> k;
    ll N = n*n;
    ll M = m*m;
    for(int i=0;i<=m-1;i++){
        temp+=i*(m-i)%MOD;
    }
    ans = temp%MOD*N%MOD;
    temp=0;
    for(int i=0;i<=n-1;i++){
        temp+=i*(n-i)%MOD;
    }
    ans += (temp%MOD*M%MOD);
    ans*=mod_comb(n*m-2,k-2,MOD);
    cout << ans%MOD;
    return 0;
}