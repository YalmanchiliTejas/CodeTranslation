//#pragma GCC optimize ("O3","unroll-loops")
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
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<bitset>
#include<tuple>

#define TEST {IS_TEST=true;}
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define mpp(x,y,z) make_pair(make_pair(x,y),z)
#define uppb upper_bound
#define lowb lower_bound

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

/*output*/
template <class T>void put(T x){cout << x << "\n";}
template <class T1,class T2>void put(T1 x,T2 y){cout << x << " " << y << "\n";}
/*---*/

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

ll roundup(ll x,ll y){return (x-1)/y+1;}
ll rem(ll x,ll y){ ll z=x%y; return z>=0?z:z+y; }

//setprecision(digit)
//sort(##.begin(),##.end(),[&](auto &x, auto &y){if (x<y) return true;})

ll N,M,K,H,W,Q,ans=0;
v_ll A,B,C,P;
string S;
int main(){
    cin >> S;
    cin >> K;
    ll rema=K;
    for (ll i=0;i<S.size();i++){
        if (S[i]!='0') rema--;
        else continue;
        ll a=S.size()-1-i;
        
        if (rema==2){
            if (a>=3){
                ans+=a*(a-1)*(a-2)/6*9*9*9;
            }
            if (a>=2){
                ans+=(S[i]-'1')*a*(a-1)/2*9*9;
            }
        } else if (rema==1){
            if (a>=2){
                ans+=a*(a-1)/2*9*9;
            }
            if (a>=1){
                ans+=(S[i]-'1')*a*9;
            }
        }else if (rema==0){
            if (a>=1){
                ans+=a*9;
            }
            if (a>=0){
                ans+=(S[i]-'1');
            }
        }else if (rema==-1){
            ans++;
        }
    }
    if (rema==0) ans++;
    cout << ans << endl;
}


