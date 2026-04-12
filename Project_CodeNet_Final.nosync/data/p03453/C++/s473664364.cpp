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

int mod=1e9+7;
struct Mint {
    int val;
    Mint inv() const{
        int tmp,a=val,b=mod,x=1,y=0;
        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
        return Mint(x);
    }
public:
    Mint():val(0){}
    Mint(ll x){if((val=x%mod)<0)val+=mod;}
    Mint pow(ll t){Mint res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return res;}
    Mint& operator+=(const Mint& x){if((val+=x.val)>=mod)val-=mod;return *this;}
    Mint& operator-=(const Mint& x){if((val+=mod-x.val)>=mod)val-=mod; return *this;}
    Mint& operator*=(const Mint& x){val=(ll)val*x.val%mod; return *this;}
    Mint& operator/=(const Mint& x){return *this*=x.inv();}
    Mint operator+(const Mint& x) const{return Mint(*this)+=x;}
    Mint operator-(const Mint& x) const{return Mint(*this)-=x;}
    Mint operator*(const Mint& x) const{return Mint(*this)*=x;}
    Mint operator/(const Mint& x) const{return Mint(*this)/=x;}
};
struct factorial {
    vector<Mint> Fact, Finv;
public:
    factorial(int maxx){
        Fact.resize(maxx+1),Finv.resize(maxx+1); Fact[0]=Mint(1); rep(i,0,maxx)Fact[i+1]=Fact[i]*(i+1);
        Finv[maxx]=Mint(1)/Fact[maxx]; rrep(i,maxx,0)Finv[i-1]=Finv[i]*i;
    }
    Mint fact(int n,bool inv=0){if(inv)return Finv[n];else return Fact[n];}
    Mint nPr(int n,int r){if(n<0||n<r||r<0)return Mint(0);else return Fact[n]*Finv[n-r];}
    Mint nCr(int n,int r){if(n<0||n<r||r<0)return Mint(0);else return Fact[n]*Finv[r]*Finv[n-r];}
};

typedef pair<ll,ll> P;
vector<P> g[100010]; vector<pair<P,int>> es; ll dist[100010];
Mint pat[2][100010];

int main(){
    int n,m; scanf("%d%d",&n,&m);
    int s,t; scanf("%d%d",&s,&t); s--; t--;
    rep(i,0,m){
        int u,v,w; scanf("%d%d%d",&u,&v,&w); u--; v--;
        es.push_back({{u,v},w}); g[u].push_back({v,w}); g[v].push_back({u,w});
    }
    rep(i,0,n)dist[i]=INF; dist[s]=0;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,s});
    while(pq.size()){
        auto p=pq.top(); pq.pop();
        int v=p.second; ll d=p.first;
        if(dist[v]<d)continue;
        for(auto to:g[v]){
            if(chmin(dist[to.first],d+to.second))pq.push({dist[to.first],to.first});
        }
    }
    vector<int> ord(n); iota(ALL(ord),0);
    sort(ALL(ord),[&](int i,int j){return dist[i]<dist[j];});
    pat[0][s]=pat[1][t]=1;
    for(int i:ord)for(auto to:g[i])if(dist[i]+to.second==dist[to.first])pat[0][to.first]+=pat[0][i];
    reverse(ALL(ord));
    for(int i:ord)for(auto to:g[i])if(to.second+dist[to.first]==dist[i])pat[1][to.first]+=pat[1][i];
    Mint ans=pat[0][t]*pat[1][s];
    rep(i,0,n)if(dist[i]*2==dist[t])ans-=pat[0][i]*pat[1][i]*pat[0][i]*pat[1][i];
    rep(i,0,m){
        int u=es[i].first.first,v=es[i].first.second;
        if(dist[u]>dist[v])swap(u,v);
        if(dist[u]+es[i].second!=dist[v])continue;
        if(dist[u]*2<dist[t]&&dist[v]*2>dist[t])ans-=pat[0][u]*pat[1][v]*pat[0][u]*pat[1][v];
    }
    printf("%d\n",ans.val);
    return 0;
}