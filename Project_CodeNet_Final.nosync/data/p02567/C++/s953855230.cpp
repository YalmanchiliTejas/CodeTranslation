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

template<typename Monoid>
struct SegmentTree{
    using F=function<Monoid(Monoid,Monoid)>;
    int sz;
    vector<Monoid> seg;
    const F f;
    const Monoid gen;
    SegmentTree(int n,const F f,const Monoid &gen):f(f),gen(gen){
        sz=1;
        while(sz<n)sz<<=1;
        seg.assign(2*sz,gen);
    }
    void set(int k,const Monoid &x){
        seg[k+sz]=x;
    }
    void build(){
        for(int k=sz-1;k>0;k--) seg[k]=f(seg[2*k],seg[2*k+1]);
    }
    void update(int k,const Monoid &x){
        k+=sz;
        seg[k]=x;
        while(k>>=1) seg[k]=f(seg[2*k],seg[2*k+1]);
    }
   // [a,b)
    Monoid query(int a,int b){
        Monoid L=gen,R=gen;
        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1){
            if(a&1) L=f(L,seg[a++]);
            if(b&1) R=f(seg[--b],R);
        }
        return f(L,R);
    }
    Monoid operator[](const int &k)const {
       return seg[k+sz];
    }

    template<typename C>
    int find_subtree(int a,const C &check,Monoid &M,bool type){
        while(a<sz){
            Monoid nxt=type?f(seg[2*a+type],M):f(M,seg[2*a+type]);
            if(check(nxt))  a=2*a+type;
            else            a=2*a+1-type;
        }
        return a-sz;
    }
    // [a,x)がcheckを満たす最初の要素位置xを返す
    template<typename C>
    int find_first(int a,const C &check){
        Monoid L=gen;
        if(a<=0){
            if(check(f(L,seg[1])))  return find_subtree(1,check,L,false);
            else                    return -1;
        }
        int b=sz;
        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1){
            if(a&1){
                Monoid nxt=f(L,seg[a]);
                if(check(nxt)) return find_subtree(a,check,L,false);
                L=nxt;
                ++a;
            }
        }
        return -1;
    }
};
ll f(ll a,ll b){
    return a>b?a:b;
}

signed main(){
    int n,q;cin>>n>>q;
    SegmentTree<ll> seg(n,f,-LINF);
    rep(i,n){
        ll a;cin>>a;
        seg.set(i,a);
    }
    seg.build();
    while(q--){
        int t;cin>>t;
        if(t==1){
            int x;ll v;cin>>x>>v;x--;
            seg.update(x,v);
        }else if(t==2){
            int l,r;cin>>l>>r;l--;
            cout<<seg.query(l,r)<<endl;
        }else{
            int l;ll v;cin>>l>>v;l--;
            int res=seg.find_first(l,[&](ll m){return m>=v;});
            if(res==-1) cout<<n+1<<endl;
            else cout<<res+1<<endl;
        }
    }

    return 0;
}