#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 1000000007
using ll=long long;
const int INF=1000000000;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
 
struct IOSetup{
    IOSetup(){
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout<<fixed<<setprecision(12);
    }
} iosetup;
 
template<typename T1,typename T2>
ostream &operator<<(ostream &os,const pair<T1,T2>&p){
    os<<p.first<<" "<<p.second;
    return os;
}
 
template<typename T>
ostream &operator<<(ostream &os,const vector<T>&v){
    for(int i=0;i<(int)v.size();i++) os<<v[i]<<(i+1==(int)v.size()?"":" ");
    return os;
}

template<typename T1,typename T2>
istream &operator>>(istream &is,pair<T1,T2>&p){
    is>>p.first>>p.second;
    return is;
}

template<typename T>
istream &operator>>(istream &is,vector<T>&v){
    for(T &x:v)is>>x;
    return is;
}

template<typename Monoid, typename OperatorMonoid=Monoid>
struct LazySegmentTree{
    // Monoid: 要素  OperatorMonoid: 作用素
    // 各マージ関数
    using F=function<Monoid(Monoid,Monoid)>;
    using G=function<Monoid(Monoid,OperatorMonoid)>;
    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;
 
    int sz,height;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    // 単位元
    const Monoid M1;
    const OperatorMonoid OM0;
 
    LazySegmentTree(int n,const F f,const G g,const H h,const Monoid &M1,const OperatorMonoid OM0)
    : f(f),g(g),h(h),M1(M1),OM0(OM0) {
        sz=1;height=0;
        while(sz<n) sz<<=1,height++;
        data.assign(2*sz,M1);lazy.assign(2*sz,OM0);
    }
 
    void set(int k,const Monoid &x){
        data[k+sz]=x;
    }
 
    //セグ木のbuild
    void build(){
        for(int k=sz-1;k>0;k--) data[k]=f(data[2*k+0],data[2*k+1]);
    }
 
    //伝播させる
    inline void propagate(int k){
        if(lazy[k]!=OM0){
            //子に伝えた後にkの場所のデータのほうの更新
            lazy[2*k+0]=h(lazy[2*k+0],lazy[k]);
            lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);
            data[k]=reflect(k);
            lazy[k]=OM0;
        }
    }
 
    inline Monoid reflect(int k){
        return lazy[k]==OM0?data[k]:g(data[k],lazy[k]);
    }
    inline void recalc(int k){
        //下から上にdataの値を計算しなおす
        while(k>>=1)data[k]=f(reflect(2*k+0),reflect(2*k+1));
    }
    inline void thrust(int k){
        for(int i=height;i>0;i--) propagate(k>>i);
    }
 
    void update(int a,int b,const OperatorMonoid &x){
        if(a>=b) return ;
        thrust(a+=sz);
        thrust(b+=sz-1);
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1) lazy[l]=h(lazy[l],x),l++;
            if(r&1) --r,lazy[r]=h(lazy[r],x);
        }
        //recalcすればpが要らない
        recalc(a);
        recalc(b);
    }
 
    Monoid query(int a,int b){
        thrust(a+=sz);
        thrust(b+=sz-1);
        Monoid L=M1,R=M1;
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1) L=f(L,reflect(l++));
            if(r&1) R=f(reflect(--r),R);
        }
        return f(L,R);
    }
    
    Monoid operator[](const int &k){
        return query(k,k+1);
    }
}; 
ll segf(ll a,ll b){return a>b?a:b;}
ll segg(ll a,ll b){return a+b;}
ll segh(ll a,ll b){return a+b;}

vector<vector<pair<int,ll>>> event(200010);// l, a

signed main(){
    int n,m;cin>>n>>m;
    rep(i,m){
        int l,r;ll a;cin>>l>>r>>a;
        event[r+1].push_back({l,a});
    }

    // dp[i] : iをonにした時のmax
    // iをみているとき考えるのはやりづらい．
    // 区間の終端を迎えたときにdp[l~r]にaを加えてもよい．
    // iをonにしたとき，としているのだから．
    // これはとてもやりやすい．
    // i番目を観たとき，dp[0~i)の中からmaxを持ってくる．
    // そのmaxはもう区間の終端を迎え，処理し終えたものからなるmax．
    // そんでiをonにしたときの追加分はあとから遅延セグ木で足しこむ．
    // この部分は不変量なので後からやっちゃっていい．
    // ポイント:dp[i]=max(dp[j]|j<i)+(iをなんかしたときのスコア)
    //          の時に，(iをなんかしたときのスコア)を後からうまくやって最適なことに変わりない場合が

    LazySegmentTree<ll,ll> seg(200010,segf,segg,segh,-LINF,0);
    rep(i,200010)seg.set(i,0);
    seg.build();

    for(int i=1;i<200010;i++){
        for(auto [l,a]:event[i])seg.update(l,i,a);
        ll res=seg.query(0,i);
        seg.update(i,i+1,res);
    }
    cout<<seg.query(0,200010)<<endl;
    return 0;
}
