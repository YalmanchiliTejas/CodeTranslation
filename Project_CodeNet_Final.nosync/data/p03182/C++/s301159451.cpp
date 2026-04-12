#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr int INF=1000000000000000000;
constexpr int mod=1000000007;
constexpr double eps=1e-8;
const double pi=acos(-1);
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int Random(int mi,int ma){
    random_device rnd;
    mt19937 mt(rnd());//32bit
    //[mi,ma]
    uniform_int_distribution<int>engine(mi,ma);
    return engine(mt);
}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b%2)return modpow(a,b-1)*a%mod;
    int memo=modpow(a,b/2);
    return memo*memo%mod;
}
vector<int>kaijo,invkaijo;
void init_fact(int n){
    kaijo.resize(n+1);
    invkaijo.resize(n+1);
    kaijo[0]=1;
    for(int i=1;i<=n;i++){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=mod;
    }
    rep(i,n+1)invkaijo[i]=modpow(kaijo[i],mod-2);
}
int comb(int a,int b){
    if(a<b)return 0;
    if(a<0||b<0)return 0;
    return kaijo[a]*invkaijo[a-b]%mod*invkaijo[b]%mod;
}
int inv(int x){
    x=modpow(x,mod-2);
    return x;
}
struct Segtree{
    int siz=1;
    vector<int>dat,laz;
    Segtree(int n){
        while(siz<n)siz*=2;
        dat.resize(siz*2-1,0);
        laz.resize(siz*2-1,0);
    }
    void eval(int k,int l,int r){
        if(laz[k]!=0){
            dat[k]+=laz[k];
            if(r-l>1){
                laz[2*k+1]+=laz[k];
                laz[2*k+2]+=laz[k];
            }
            laz[k]=0;
        }
    }
    void update(int a,int b,int x,int k=0,int l=0,int r=-1){
        if(r==-1)r=siz;
        eval(k,l,r);
        if(b<=l||r<=a)return;
        if(a<=l&&r<=b){
            laz[k]+=x;
            eval(k,l,r);
            return;
        }
        update(a,b,x,2*k+1,l,(l+r)/2);
        update(a,b,x,2*k+2,(l+r)/2,r);
        dat[k]=max(dat[2*k+1],dat[2*k+2]);
    }
    int query(int a,int b,int k=0,int l=0,int r=-1){
        if(r==-1)r=siz;
        if(b<=l||r<=a)return -INF;
        eval(k,l,r);
        if(a<=l&&r<=b)return dat[k];
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
};
int n,m;
vector<P>q[200010];
signed main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,m){
        int l,r,a;
        cin>>l>>r>>a;
        q[r].pb({l,a});
    }
    Segtree seg(n+1);
    for(int i=1;i<=n;i++){
        seg.update(i,i+1,seg.query(0,i));
        for(P p:q[i]){
            seg.update(p.fi,i+1,p.se);
        }
    }
    cout<<seg.query(0,n+1)<<endl;
    return 0;
}