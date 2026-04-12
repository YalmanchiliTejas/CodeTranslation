#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n,m;
const int MAX_N=1<<17;
const ll INF=(1ll<<31)-1;
class Lz_segtree{
public:
    int n;
    ll e=0;
    ll init=0;
    vector<ll> dat,lz;
    Lz_segtree(int n_):n(n_){
        n=1;
        while(n<n_) n*=2;
        dat.resize(n*2,e);
        lz.resize(n*2,init);
    }
    void update_f(ll& d,ll x){
        d+=x;
    }
    ll dat_propergate(ll l,ll r){
        return max(l,r);
    }
    void lz_propergate(ll& l,ll& r,ll x){
        l+=x,r+=x;
    }
    void eval(int len,int k){
        if(lz[k]!=init) update_f(dat[k],lz[k]);
        if(len>1){//flag check!
            if(lz[k]!=init)lz_propergate(lz[k*2+1],lz[k*2+2],lz[k]);
        }
        lz[k]=init;
    }
    //range [a,b)
    void update(int a,int b,int k,int l,int r,ll x){
        eval(r-l,k);
        if(r<=a||b<=l) return;
        if(a<=l&&r<=b){
            update_f(lz[k],x);
            eval(r-l,k);
        }
        else{
            update(a,b,k*2+1,l,(l+r)/2,x);
            update(a,b,k*2+2,(l+r)/2,r,x);
            dat[k]=dat_propergate(dat[2*k+1],dat[2*k+2]);
        }
    }
    //range [a,b)
    ll query(int a,int b,int k,int l,int r){
        eval(r-l,k);
        if(r<=a||b<=l) return e;
        if(a<=l&&r<=b) return dat[k];
        else{
            ll vl=query(a,b,k*2+1,l,(l+r)/2);
            ll vr=query(a,b,k*2+2,(l+r)/2,r);
            return dat_propergate(vl,vr);
        }
    }
    void update(int a,int b,ll x){
        return update(a,b,0,0,n,x);
    }
    ll query(int a,int b){
        return query(a,b,0,0,n);
    }
};

vector<ll> l[200001],a[200001];
int main(){
    cin>>n>>m;
    int li,ri,ai;
    rep(i,m){
        cin>>li>>ri>>ai;
        --li,--ri;
        l[ri].pb(li);
        a[ri].pb(ai);
    }
    Lz_segtree seg(n+1);
    rep(i,n){
        ll nx=seg.query(0,i);
        seg.update(i,i+1,nx);
        int sz=l[i].size();
        rep(j,sz){
            seg.update(l[i][j],i+1,a[i][j]);
        }
    }
    cout<<seg.query(0,n)<<endl;
    return 0;
}
