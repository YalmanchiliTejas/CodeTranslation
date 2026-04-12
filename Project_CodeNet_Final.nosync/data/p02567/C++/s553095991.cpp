

#include <bits/stdc++.h>
//#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;

/*
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
void Add(ll &pos,ll val){pos=mod(pos+val);}
void mod_print(ll k){
    ll P=50000;
    rep(y,1,P){
        ll x=mod(y*k);
        
        if(abs(x)<=P||x+P>=i_7){
            if(x+P>=i_7){
                x-=i_7;
            }
            cout<<x<<"/"<<y<<endl;
            //cout<<setprecision(5)<<(dd)x/(dd)y;
            return;
        }
    }
    cout<<"nun"<<endl;
}
*/

#include "boost/multiprecision/cpp_int.hpp"
#include "boost/multiprecision/cpp_dec_float.hpp"
namespace mp = boost::multiprecision;
typedef mp::cpp_int LL;
typedef mp::number<mp::cpp_dec_float<1024>> DD;// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)

typedef long double dd;
typedef pair<ll,ll> l_l;
typedef pair<dd,dd> d_d;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define rrep(i,r,l) for(ll i=r;i>=l;i--)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
dd EPS=1E-12;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second

#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T,class S>
inline bool chmax(T &a, S b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T,class S>
inline bool chmin(T &a, S b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
#define endl "\n"  //インタラクティブで消す！！！！！！！！！！！！！！！！！！！！！
#define all(c) c.begin(),c.end()
typedef vector<ll> vl;


//using mint = modint998244353;
using mint = modint1000000007;
//////////////////////////


ll OP(ll a,ll b){return max(a,b);}
ll E(){return -inf;}
ll target;
bool F(ll x){
    if(target>x)return true;
    return false;
}

int main(){fastio
    ll n,q;cin>>n>>q;
    vl a(n+1);rep(i,1,n)cin>>a[i];
    segtree<ll,OP,E>seg(a);
    while(q--){
        ll t,x,y;cin>>t>>x>>y;
        if(t==1){
            seg.set(x,y);
        }else if(t==2){
            cout<<seg.prod(x,y+1)<<endl;
        }else{
            target=y;
            cout<<seg.max_right<F>(x)<<endl;
        }
    }
    
    
    return 0;
}
