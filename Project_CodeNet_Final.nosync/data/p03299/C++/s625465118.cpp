#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


#define MOD 1000000007
#define MAX_P 200005
Int fact[MAX_P],inv[MAX_P],finv[MAX_P];;
Int extgcd(Int a,Int b,Int& x,Int& y){
  Int d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
Int mod_inverse(Int a,Int mod){
  Int x,y;
  extgcd(a,mod,x,y);
  return (mod+x%mod)%mod;
}

Int mod_pow(Int x,Int n,Int mod){
  Int res=1;
  while(n){
    if(n&1) (res*=x)%=mod;
    (x*=x)%=mod;
    n>>=1;
  }
  return res;
}

Int mod_inverse2(Int a,Int mod){
  return mod_pow(a,mod-2,mod);
}

void init(Int mod){
  fact[0]=1;
  for(Int i=1;i<MAX_P;i++)
    fact[i]=(fact[i-1]*i)%mod;

  inv[1]=1;
  for(Int i=2;i<MAX_P;i++)
    inv[i]=inv[mod%i]*(mod-mod/i)%mod;
  
  finv[0]=1;
  for(Int i=1;i<MAX_P;i++)
    finv[i]=finv[i-1]*inv[i]%mod;
}

Int mod_fact(Int n,Int mod,Int& e){
  e=0;
  if(n==0) return 1;
  Int res=mod_fact(n/mod,mod,e);
  e+=n/mod;
  if(n/mod%2!=0)return res*(mod-fact[n%mod]) %mod;
  return res*fact[n%mod]%mod;
}

Int mod_comb(Int n,Int k,Int mod){
  if(n==k||k==0) return 1;
  Int e1,e2,e3;
  Int a1=mod_fact(n,mod,e1),a2=mod_fact(k,mod,e2),a3=mod_fact(n-k,mod,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inverse(a2*a3%mod,mod)%mod;
}

Int mod_comb2(Int n,Int k,Int mod){
  Int res=1;
  for(Int i=0;i<k;i++){
    res*=(n-i)%mod;
    res%=mod;
    res*=mod_inverse(i+1,mod);
    res%=mod;
  }
  return res;
}

//only for prime mod
Int mod_comb3(Int n,Int k,Int mod){
  if(k<0||k>n) return 0;
  return fact[n]*finv[k]%mod*finv[n-k]%mod;
}

Int montmort(Int n,Int mod){
  Int res=0,inv=1;
  for(Int k=2;k<=n;k++){
    (inv*=mod_inverse(k,mod))%=mod;
    if(k%2) (res+=mod-inv)%=mod;
    else (res+=inv)%=mod;
  }
  for(Int i=1;i<=n;i++)
    (res*=i)%=mod;
  return res;
}

// calculate P(t) from given points in [0,N]
Int LagrangePolynomial(vector<Int> &y,Int t,const Int mod){
  init(mod);
  Int n=y.size()-1;
  Int num=1;
  for(Int i=0;i<=n;i++)
    num=num*((t-i)%mod)%mod;
  Int res=0;
  for(Int i=0;i<=n;i++){
    Int tmp=(y[i]*num%mod)*mod_inverse((t-i)%mod,mod)%mod;
    tmp=tmp*finv[i]%mod;
    tmp=tmp*finv[n-i]%mod;
    if((n-i)&1) tmp=mod-tmp;
    res=(res+tmp)%mod;
  }
  return res;
}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> h(n);
  for(Int i=0;i<n;i++) cin>>h[i];
  
  using P = pair<Int, Int>;
  function<P(Int, Int, Int)> dfs=
    [&](Int l,Int r,Int d)->P{
      Int flg=1;
      for(Int i=l;i<r;i++)
	flg&=h[i]==h[l];
      if(flg){
	Int x=2;
	Int y=mod_pow(2,r-l,MOD)+MOD-2;
	x*=mod_pow(2,h[l]-d-1,MOD);
	x%=MOD;
	y%=MOD;
	//cout<<l<<" "<<r<<":"<<x<<" "<<y<<endl;
	return P(x,y);
      }
      Int t=h[l],u=0;
      for(Int i=l;i<r;i++) chmin(t,h[i]);
      vector<P> v;
      for(Int i=l;i<r;i++){
	if(h[i]==t) continue;
	Int j=i;
	while(j<r&&h[j]!=t) j++;
	v.emplace_back(dfs(i,j,t));
	u+=j-i;
	i=j-1;
      }
      Int w=(r-l)-u;
      Int x=2,y=1;
      for(auto p:v){
	x*=p.first;
	y*=(p.first*2+p.second)%MOD;
	x%=MOD;
	y%=MOD;
      }
      y*=mod_pow(2,w,MOD);
      y%=MOD;
      y+=MOD-x;
      y%=MOD;
      x*=mod_pow(2,t-d-1,MOD);
      x%=MOD;
      
      //cout<<l<<" "<<r<<" "<<w<<"*"<<x<<" "<<y<<endl;
      return P(x,y);
    };
  
  auto p=dfs(0,n,0);
  Int ans=(p.first+p.second)%MOD;
  cout<<ans<<endl;
  return 0;
}
