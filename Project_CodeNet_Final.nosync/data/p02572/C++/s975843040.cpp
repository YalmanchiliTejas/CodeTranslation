//#pragma GCC optimize ("O3","unroll-loops")
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cassert>

#include<cmath>
#include<functional>
#include<algorithm>
#include<numeric>

#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<tuple>

#define TEST {IS_TEST=true;}
#define fi first
#define se second
#define pb(x) emplace_back(x)
#define pf(x) emplace_front(x)
#define emp(x) emplace(x)
#define mp(x,y) make_pair(x,y)

using namespace std;
using ll = int_fast64_t;
using v_b = vector <bool>; using v_ll = vector <ll>; using str = string; using v_str = vector <string>; using p_ll = pair < ll,ll >;
using vv_b = vector < v_b >; using vv_ll = vector < v_ll >; using vp_ll = vector < p_ll >;
using vvv_ll = vector < vv_ll >; using vvp_ll = vector < vp_ll >;
using ld = long double; using v_ld = vector <ld>; using vv_ld = vector<v_ld>;

bool IS_TEST=false;
ll ll_min64=1LL<<63;
ll ll_max64=~ll_min64;
ll ll_min32=1LL<<31;
ll ll_max32=~ll_min32;

ll MOD = 1000000007;

/*displaying functions for debug*/
template<class T> void show2(const T &x){cerr << x;}
template<class T1,class T2> void show2(const pair<T1,T2> &x){
  cerr << "{" << show2(x.first) << "," << show2(x.second) << "}";
}
template<class T> void show(const T &x){
  if (!IS_TEST) return; show2(x); cerr << "\n";
}
template<class T> void v_show(const T &v, ll n=-1){
  if (!IS_TEST) return; auto itr=v.begin(); ll m=n;
  while(itr!=v.end() && m!=0 ){ show2(*itr); cerr << " "; itr++; m--;}
  cerr << "\n";
}
template<class T> void vv_show(const T &v, ll n=-1){
  if (!IS_TEST) return;
  cerr << "--------------------------------\n";
  auto itr=v.begin(); ll m=n;
  while(itr!=v.end() && m!=0 ){ v_show(*itr,n); itr++; m--;}
  cerr << "--------------------------------\n";
}
/*--------------------------------*/

/*loading integers*/
void load(ll& x1){ cin >> x1; }
void load(ll& x1,ll& x2){ cin >> x1 >> x2; }
void load(ll& x1,ll& x2,ll& x3){ cin >> x1 >> x2 >> x3; }
void load(ll& x1,ll& x2,ll& x3,ll& x4){ cin >> x1 >> x2 >> x3 >> x4; }
void v_load(ll n, v_ll& v1, ll head=0, ll tail=0, ll init=0){
    ll m=n+head+tail; v1.assign(m,init);
    for (ll i=0;i<n;i++){ scanf("%lld",&v1[i+head]); }
}
void v_load(ll n, v_ll& v1 ,v_ll& v2, ll head=0, ll tail=0, ll init=0){
    ll m=n+head+tail; v1.assign(m,init); v2.assign(m,init);
    for (ll i=0;i<n;i++){ scanf("%lld%lld",&v1[i+head],&v2[i+head]); }
}
void v_load(ll n, v_ll& v1 ,v_ll& v2, v_ll& v3, ll head=0, ll tail=0, ll init=0){
    ll m=n+head+tail; v1.assign(m,init); v2.assign(m,init); v3.assign(m,init);
    for (ll i=0;i<n;i++){ scanf("%lld%lld%lld",&v1[i+head],&v2[i+head],&v3[i+head]); }
}
void v_load(ll n, v_ll& v1 ,v_ll& v2, v_ll& v3, v_ll& v4, ll head=0, ll tail=0, ll init=0){
    ll m=n+head+tail; v1.assign(m,init); v2.assign(m,init); v3.assign(m,init); v4.assign(m,init);
    for (ll i=0;i<n;i++){ scanf("%lld%lld%lld%lld",&v1[i+head],&v2[i+head],&v3[i+head],&v4[i+head]); }
}
/*--------------------------------*/

v_ll local_sort(ll x1=ll_max64, ll x2=ll_max64, ll x3=ll_max64, ll x4=ll_max64){
    v_ll x{x1,x2,x3,x4};
    sort(x.begin(),x.end());
    return x;
}

ll max(ll x,ll y){return x>y?x:y;}
ll min(ll x,ll y){return x<y?x:y;}

ll max(v_ll::iterator b,v_ll::iterator e){
    ll ans=*b;
    while (b<e) {ans=max(ans,*b);b++;}
    return ans;
}
ll argmax(v_ll::iterator b,v_ll::iterator e){
    ll ans=0, cnt=0, val=*b;
    while (b<e) { if (val<*b) {ans=cnt; val=*b;} cnt++; b++;}
    return ans;
}
ll min(v_ll::iterator b,v_ll::iterator e){
    ll ans=*b;
    while (b<e) {ans=min(ans,*b);b++;}
    return ans;
}
ll argmin(v_ll::iterator b,v_ll::iterator e){
    ll ans=0, cnt=0, val=*b;
    while (b<e) { if (val>*b) {ans=cnt; val=*b;} cnt++; b++;}
    return ans;
}
ll sum(v_ll::iterator b,v_ll::iterator e){
    ll ans=0;
    while (b<e) {ans+=*b;b++;}
    return ans;
}

template<class T> bool chmax(T& x,const T& y){ if (x>=y) return false; x=y; return true;}
template<class T> bool chmin(T& x,const T& y){ if (x<=y) return false; x=y; return true;}

template<class T> void quit(T x){cout << x << endl; exit(0);}
void yesno(bool x){cout << (x?"Yes":"No") <<endl;}

ll rup(ll x,ll y){return (x-1)/y+1;}
ll rem(ll x,ll y){ ll z=x%y; return z>=0?z:z+y; }

template<typename T>
v_ll index_sort(const vector<T>& ref){
    v_ll idx(ref.size());
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](auto &x, auto &y){if (ref[x]<ref[y]) return true;});
}

//setprecision(digit)
//sort(##.begin(),##.end(),[&](auto &x, auto &y){if (x<y) return true;});
//ll ok=0,ng=0; while(abs(ok-ng)>1){ll mid=(ok+ng)/2; (true?ok:ng)=mid;}

struct dat{
    dat(){}
    bool operator < (const dat& rhs)const {return false; }
};

/*modint*/
struct ModInt{
  static ll modulus;
  ll val;
  ModInt(ll n=0){ val=n%modulus; if (val<0) val+=modulus;}
  ModInt operator +(const ModInt& rhs)const{ return val+rhs.val;}
  ModInt operator -(const ModInt& rhs)const{ return val-rhs.val;}
  ModInt operator *(const ModInt& rhs)const{ return val*rhs.val;}
  ModInt& operator +=(const ModInt& rhs){val+=rhs.val; if (val>=modulus)val-=modulus; return *this;}
  ModInt& operator -=(const ModInt& rhs){val-=rhs.val; if (val<0) val+=modulus; return *this;}
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
istream& operator >> (istream& istr, ModInt &rhs){ll x; istr >> x; rhs=x; return istr;};
ostream& operator << (ostream& ostr, const ModInt &rhs){ostr << (rhs.val); return ostr;};

vector<ModInt> mod_f(ll n){
  vector<ModInt> v(n+1,1);
  for (ll i=1;i<=n;i++) v[i]=v[i-1]*i;
  return v;
}
vector<ModInt> mod_f_i(ll n){
  vector<ModInt> v(n+1,1);
  for (ll i=1;i<=n;i++) v[n]=v[n]*i;
  v[n]=v[n].inv();
  for (ll i=n;i>0;i--) v[i-1]=v[i]*i;
  return v;
}

ll ModInt::modulus=1000000007;
//ll ModInt::modulus=998244353;

using mi = ModInt; 
using v_mi = vector<ModInt>;


int main(){
    ll N;
    v_ll A;
    cin >> N;
    v_load(N,A);
    mi s1=0,s2=0;
    for (ll i=0;i<N;i++){
        s1+=A[i];s2+=A[i]*A[i];
    }
    cout << ((s1*s1-s2)/2) << endl;
}


