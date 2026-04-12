#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cassert>

#include<cmath>
#include<functional>
#include<algorithm>

#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<bitset>
#include<tuple>

#define TEST {IS_TEST=true;}

using namespace std;
using ll = int_fast64_t;
using v_bool = vector <bool>;
using v_ll = vector <ll>;
using v_std = vector <string>;
using p_ll = pair <ll,ll>;
using vv_ll = vector <vector <ll> >;
using vp_ll = vector < p_ll >;

using ld = long double;
using v_ld = vector <ld>;
using vv_ld = vector<v_ld>;

bool IS_TEST=false;
ll ll_min=1LL<<63;
ll ll_max=~ll_min;
ll int_min=1LL<<31;
ll int_max=~ll_max;
ll MOD = 1000000007;

template<class T>
void show(const T &x){
  if (!IS_TEST) return;
  cout << x << endl;
}
template<class T1,class T2>
void show(const pair<T1,T2> &x){
  if (!IS_TEST) return;
  cout << "{" << x.first << "," << x.second << "}" << endl;
}

template<class T>
void show_sub(const T &x){if (!IS_TEST) return; cout << x;}
void show_sub(const string &x){if (!IS_TEST) return; cout << x << endl;}
template<class T1,class T2>
void show_sub(const pair<T1,T2> &x){
  if (!IS_TEST) return;
  cout << "{" << show_sub(x.first) << "," << show_sub(x.second) << "}";
}
template<class T>
void v_show(const T &v){
  if (!IS_TEST) return;
  auto itr=v.begin();
  while(itr!=v.end()){ show_sub(*itr); itr++;}
  cout << endl;
}

template<class T>
void vv_show(const T &v){
  if (!IS_TEST) return;
  cout << "--------------------------------\n";
  auto itr=v.begin();
  while(itr!=v.end()){ v_show(*itr); itr++;}
  cout << "--------------------------------" << endl;
}



ll max(ll x,ll y){return x>y?x:y;}
ll max(ll x,ll y, ll z){return max(max(x,y),z);}
ll max(v_ll::iterator b,v_ll::iterator e){
    ll ans=*b;
    while (b<e) {ans=max(ans,*b);b++;}
    return ans;
}
ll min(ll x,ll y){return x<y?x:y;}
ll min(ll x,ll y, ll z){return min(min(x,y),z);}
ll min(v_ll::iterator b,v_ll::iterator e){
    ll ans=*b;
    while (b<e) {ans=min(ans,*b);b++;}
    return ans;
}
ll mid(ll x,ll y,ll z){
    if (y>=x && x>=z) return x;
    if (z>=x && x>=y) return x;
    if (x>=y && y>=z) return y;
    if (z>=y && y>=x) return y;
    if (x>=z && z>=y) return z;
    if (y>=z && z>=x) return z;
    return x;
}
ll gcd(ll x,ll y){
    if(x<0)x=-x; if(y<0)y=-y;
    while(y>0){ x%=y; swap(x,y); }
    return y;
}
ll gcd(ll x,ll y, ll z){return gcd(gcd(x,y),z);}
ll gcd(v_ll::iterator b,v_ll::iterator e){
    ll ans=0;
    while (b<e) ans=gcd(ans,*b);
    return ans;
}
ll lcm(ll x,ll y){
    ll z=x*y; if(x<0)x=-x; if(y<0)y=-y;
    while(y>0){ x%=y; swap(x,y); }
    return z/y;
}
ll lcm(ll x,ll y, ll z){return lcm(lcm(x,y),z);}
ll lcm(v_ll::iterator b,v_ll::iterator e){
    ll ans=1;
    while (b<e) ans=lcm(ans,*b);
    return ans;
}

v_ll arange(ll n){
    v_ll v(n+1,0);
    for(ll i=0;i<=n;i++)v[i]=i;
    return v;
}

ll vec_sum(const v_ll& v,ll b,ll e){
    ll ans=0;
    for(ll i=b;i<e;i++)ans+=v[i];
    return ans;
}
ll v_sum(v_ll::iterator b,v_ll::iterator e){
    ll ans=*b;
    while (b<e) { ans+=*b; b++;}
    return ans;
}
ll v_xor(v_ll::iterator b,v_ll::iterator e){
    ll ans=*b;
    while (b<e) { ans^=*b; b++;}
    return ans;
}
ll v_eq(v_ll::iterator b,v_ll::iterator e){
    ll ans=*b;
    while (b<e) { ans^=~*b; b++;}
    return ans;
}


template<class T> void refl_max(T& x,const T& y){ if (x>=y) return; x=y; }
template<class T> void refl_min(T& x,const T& y){ if (x<=y) return; x=y; }

template<class T,class S> void refl_max(T& x,S& xx,const T& y,const S& yy){
  if (x>=y) return; x=y; xx=yy;
}
template<class T,class S> void refl_min(T& x,S& xx,const T& y,const S& yy){
  if (x<=y) return; x=y; xx=yy;
}

template<class T> void quit(T x){cout << x << endl; exit(0);}

/*O(logN)*/
ll sqrt_ll(ll n){
  assert(n>=0);
  ll ok = 0,ng = n+1;
  while(ok-ng>1||ng-ok>1){ ll m=(ok+ng)/2; if (m*m<=n) ok=m; else ng=m;}
  return ok;
}

class ModInt{
  public:
  static ll modulus;
  ll val;
  ModInt(ll n=0){ val=n%modulus; if (val<0) val+=modulus;}
  ModInt operator +(const ModInt& rhs)const{ return val+rhs.val;}
  ModInt operator -(const ModInt& rhs)const{ return val-rhs.val;}
  ModInt operator *(const ModInt& rhs)const{ return val*rhs.val;}
  ModInt& operator +=(const ModInt& rhs){val+=rhs.val; if (val>=modulus)val-=modulus; return *this;}
  ModInt& operator -=(const ModInt& rhs){val-=rhs.val; if (val<modulus)val+=modulus; return *this;}
  ModInt& operator *=(const ModInt& rhs){val*=rhs.val; val%=modulus; return *this;}
  ModInt pow(ll a)const{
    a%=(modulus-1); if (a<0)a+=(modulus-1);
    ModInt ret(1); ModInt vv(val);
    while (a!=0){ if (a&1) ret*=vv; a>>=1; vv*=vv;}
    return ret;
  }
  ModInt inv()const{return pow(-1);}
  ModInt operator /(const ModInt& rhs)const{ return *this*rhs.pow(-1);}
  ModInt& operator /=(const ModInt& rhs){ *this*=rhs.pow(-1); return *this;}
};
istream& operator >> (istream& istr, ModInt &rhs){istr >> (rhs.val); return istr;};
ostream& operator << (ostream& ostr, const ModInt &rhs){ostr << (rhs.val); return ostr;};
vector<ModInt> mod_nck(ll n){
  vector<ModInt> v(n+1,1);
  for (ll i=1;i<=n;i++) v[i]=v[i-1]*(n+1-i)/i;
  return v;
}
vector<ModInt> mod_pow(ModInt base, ll n){
  vector<ModInt> v(n+1,1);
  for (ll i=1;i<=n;i++) v[i]=v[i-1]*base;
  return v;
}
vector<ModInt> mod_npk(ll n){
  vector<ModInt> v(n+1,1);
  for (ll i=1;i<=n;i++) v[i]=v[i-1]*(n+1-i);
  return v;
}
vector<ModInt> mod_fact(ll n){
  vector<ModInt> v(n+1,1);
  for (ll i=1;i<=n;i++) v[i]=v[i-1]*i;
  return v;
}
vector<ModInt> mod_nck_2(ll n,ll k){
  vector<ModInt> v(n+1,1);
  for (ll i=k+1;i<=n;i++) v[i]=v[i-1]*i/(i-k);
  return v;
}
vector<ModInt> mod_calc(ll n){
  vector<ModInt> v(n+1,1);
  for (ll i=n-1;i>=0;i--) v[i]=v[i+1]*(i+1);
  return v;
}

ll ModInt::modulus=998244353;

ll N;

int main(){
  cin >> N;
  vector<ModInt> calc=mod_calc(N);
  vector<ModInt> pow2=mod_pow(2,N);
  ModInt exc=1;
  for(ll b=1;b<=N;b++){
    exc*=b;
  }
  ModInt ans=0;
  ModInt ans2=ModInt(3).pow(N);
  //ModInt p=ModInt(1);
  for(ll b=0;b<N/2;b++){
    ans+=calc[b]*calc[N-b]*pow2[b];
  }
  ans*=exc.inv();
  ans*=ModInt(2);

  cout << ans2-ans << endl;
}


