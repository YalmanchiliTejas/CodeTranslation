#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef pair<l_l,ll> lll;
typedef vector<string> vs;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
ll n,m;
vector<l_l> g[220000];
struct Seg{
    vector<ll> sum;
    vector<ll> mx;
    Seg(){
        sum.resize(500000,0);
        mx.resize(500000,0);
    }
    void add_val(ll l,ll r,ll val,ll bottom=0,ll top=250000,ll pos=1){
        if(l<=bottom&&top<=r){
            sum[pos]+=val;
            return;
        }
        if(r<=bottom||top<=l){
            return;
        }
        ll mid=(bottom+top)/2;
        add_val(l,r,val,bottom,mid,pos*2);
        add_val(l,r,val,mid,top,pos*2+1);
        mx[pos]=max(mx[pos*2]+sum[pos*2],mx[pos*2+1]+sum[pos*2+1]);
    }
    ll max_val(ll l,ll r,ll bottom=0,ll top=250000,ll pos=1){
        if(l<=bottom&&top<=r){
            return sum[pos]+mx[pos];
        }
        if(r<=bottom||top<=l){
            return -LINF;
        }
        ll mid=(bottom+top)/2;
        return max(max_val(l,r,bottom,mid,pos*2),max_val(l,r,mid,top,pos*2+1))+sum[pos];
    }
};
int main(){
    cin>>n>>m;
    rep(i,m){
        ll l,r,a;cin>>l>>r>>a;
        g[r].pb({l,a});
    }
    Seg seg;
    for(int i=1;i<=n;i++){
        ll mx=seg.max_val(0,i);
        seg.add_val(i,i+1,mx);
        for(auto p: g[i]){
            ll l=p.fi;
            ll a=p.se;
            seg.add_val(l,i+1,a);
        }
    }
    cout<<seg.max_val(0,n+1)<<endl;
    return 0;
}