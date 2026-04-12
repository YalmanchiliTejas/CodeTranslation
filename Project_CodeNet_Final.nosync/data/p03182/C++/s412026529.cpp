#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end

template<typename M,typename N=M>
struct LazySegmentTree{
    using F=function<M(M,M)>; using G=function<M(M,N)>; using H=function<N(N,N)>;
    int sz,height; vector<M> data; vector<N> lazy;
    const F f;const G g; const H h; const M m1; const N n1;
    LazySegmentTree(int n,const F f,const G g,const H h,const M &m1,const N n1):f(f),g(g),h(h),m1(m1),n1(n1){
        sz=1,height=0; while(sz<n)sz<<=1,height++;
        data.assign(2*sz,m1); lazy.assign(2*sz,n1);
    }
    inline void build(vector<M> v){
        rep(i,0,v.size())data[i+sz]=v[i];
        rrep(k,sz-1,0)data[k]=f(data[2*k],data[2*k+1]);
    }
    inline M ref(int k){return lazy[k]==n1?data[k]:g(data[k],lazy[k]);}
    inline void recalc(int k){while(k>>=1)data[k]=f(ref(2*k),ref(2*k+1));}
    inline void thrust(int k){rrep(i,height,0)eval(k>>i);}
    inline void eval(int k){
        if(lazy[k]!=n1){
            lazy[2*k]=h(lazy[2*k],lazy[k]); lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);
            data[k]=ref(k); lazy[k]=n1;
        }
    }
    inline void update(int a,int b,N x){
        thrust(a+=sz); thrust(b+=sz-1);
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1)lazy[l]=h(lazy[l],x),++l;
            if(r&1)--r,lazy[r]=h(lazy[r],x);
        }
        recalc(a); recalc(b);
    }
    inline M query(int a,int b){
        thrust(a+=sz); thrust(b+=sz-1);
        M L=m1,R=m1;
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1)L=f(L,ref(l++)); if(r&1)R=f(ref(--r),R);
        } return f(L,R);
    }
};

vector<pair<int,int>> rng[200010];

int main(){
    int n,m; scanf("%d%d",&n,&m);
    rep(rot,0,m){
        int l,r,a; scanf("%d%d%d",&l,&r,&a);
        l--; r--;
        rng[r].push_back({l,a});
    }
    LazySegmentTree<ll> seg(n,
    [](ll a,ll b){return max(a,b);},
    [](ll a,ll b){return a+b;},
    [](ll a,ll b){return a+b;},0,0);
    rep(i,0,n){
        ll val=seg.query(0,i);
        seg.update(i,i+1,val);
        for(auto p:rng[i])seg.update(p.first,i+1,p.second);
    }
    printf("%lld\n",seg.query(0,n));
    return 0;
}
