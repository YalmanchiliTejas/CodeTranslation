#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
const ll mod=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename Monoid,typename OperatorMonoid>
struct LazySegmentTree{
    private:
    typedef function<Monoid(Monoid,Monoid)> F;
    typedef function<Monoid(Monoid,OperatorMonoid)> G;
    typedef function<OperatorMonoid(OperatorMonoid,OperatorMonoid)> H;
    typedef function<OperatorMonoid(OperatorMonoid,int)> P;
    int n;
    F f;
    G g;
    H h;
    P p;
    Monoid id1;
    OperatorMonoid id0;
    vector<Monoid> dat;
    vector<OperatorMonoid> laz;
    public:
    LazySegmentTree(int n_,F f,G g,H h,Monoid id1,OperatorMonoid id0,
                    P p=[](OperatorMonoid a,int b){return a;}):
        f(f),g(g),h(h),id1(id1),id0(id0),p(p){init(n_);};
    void init(int n_){
        n=1;
        while(n<n_) n*=2;
        dat.resize(2*n-1,id1);
        laz.resize(2*n-1,id0);
    }
    void build(vector<Monoid> v){
        int n_=v.size();
        rep(i,n_) dat[i+n-1]=v[i];
        for (int i=n-2;i>=0;i--) dat[i]=f(dat[2*i+1],dat[2*i+2]);
    }
    inline void propagate(int len,int k){
        if (laz[k]==id0) return;
        if (2*k+1<2*n-1){
            laz[2*k+1]=h(laz[2*k+1],laz[k]);
            laz[2*k+2]=h(laz[2*k+2],laz[k]);
        }
        dat[k]=g(dat[k],p(laz[k],len));
        laz[k]=id0;
    }
    Monoid update(int a,int b,OperatorMonoid x,int k,int l,int r){
        propagate(r-l,k);
        if (r<=a||b<=l) return dat[k];
        if (a<=l&&r<=b){
            laz[k]=h(laz[k],x);
            return g(dat[k],p(laz[k],r-l));
        }
        return dat[k]=f(update(a,b,x,2*k+1,l,(l+r)/2),
                        update(a,b,x,2*k+2,(l+r)/2,r));
    }
    Monoid update(int a,int b,OperatorMonoid x){
        return update(a,b,x,0,0,n);
    }
    Monoid query(int a,int b,int k,int l,int r){
        propagate(r-l,k);
        if (r<=a||b<=l) return id1;
        if (a<=l&&r<=b) return dat[k];
        Monoid vl=query(a,b,2*k+1,l,(l+r)/2);
        Monoid vr=query(a,b,2*k+2,(l+r)/2,r);
        return f(vl,vr);
    }
    Monoid query(int a,int b){
        return query(a,b,0,0,n);
    }
    Monoid operator[](int i){
        return query(i,i+1);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    auto f=[](ll a,ll b){return max(a,b);};
    auto g=[](ll a,ll b){return a+b;};
    LazySegmentTree<ll,ll> seg(N,f,g,g,-IINF,0);
    vector<ll> v(N,0);
    seg.build(v);
    vector<pair<Pii,ll>> intervals(M);
    rep(i,M){
        int l,r; ll a; cin >> l >> r >> a;
        intervals[i]=make_pair(Pii(--r,--l),a);
    }
    sort(all(intervals));
    int now=0;
    rep(i,N){
        seg.update(i,i+1,max(0LL,seg.query(0,i)));
        while (now<M&&intervals[now].first.first<=i){
            Pii p=intervals[now].first;
            seg.update(p.second,p.first+1,intervals[now++].second);
        }
    }
    cout << max(0LL,seg.query(0,N)) << endl;
}