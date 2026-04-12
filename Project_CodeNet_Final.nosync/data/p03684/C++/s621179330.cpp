#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#define ll long long int
#define MOD 1000000007LL
using namespace std;
typedef pair<ll,ll> P;
struct edge{ll u,v,cost;};
ll par[1000000];//親
ll fukasa[1000000];//深さ
//初期化
void init(ll n){
    for(int i=0;i<n;i++){
        par[i]=i;
        fukasa[i]=0;
    }
}
//木の根を求める
ll find(int x){
    if(par[x]==x){
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}
//xとyの集合を併合
void unite(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x==y){
        return;
    }
    if(fukasa[x]<fukasa[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(fukasa[x]==fukasa[y]){
            fukasa[x]++;
        }
    }
}
bool same(ll x,ll y){
    return find(x)==find(y);
}
bool comp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}
edge es[364364];
ll kruskal(ll V,ll E){
    sort(es,es+E,comp);
    init(V);
    ll res=0;
    for(int i=0;i<E;i++){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}
struct P2{ll num,x,y;};
bool cx(const P2 &l,const P2 &r){
    return l.x<r.x;
}
bool cy(const P2 &l,const P2 &r){
    return l.y<r.y;
}
int main() {
    ll n;
    cin>>n;
    P2 s[n];
    for(int i=0;i<n;i++){
        cin>>s[i].x>>s[i].y;
        s[i].num=i;
    }
    sort(s,s+n,cx);
    for(int i=0;i<n-1;i++){
        es[i]=edge{s[i].num,s[i+1].num,min(abs(s[i].x-s[i+1].x),abs(s[i].y-s[i+1].y))};
    }
    sort(s,s+n,cy);
    for(int i=0;i<n-1;i++){
        es[n+i-1]=edge{s[i].num,s[i+1].num,min(abs(s[i].x-s[i+1].x),abs(s[i].y-s[i+1].y))};
        
    }
    int e=2*(n-1);
    cout<<kruskal(n,e)<<endl;
}