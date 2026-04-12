

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/

/////////////////////////////////

#define MAX_N 1000000//調節！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
int par[MAX_N],dep[MAX_N];//depはrankのこと
//n要素で初期化
void init(int n){
    for(int i=0;i<=n-1;i++){
        par[i]=i;
        dep[i]=0;
    }
}
//木の根を求める
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
//xとyの属する集合を併合
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(dep[x]<dep[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(dep[x]==dep[y])dep[x]++;
    }
}
//xとyが同じ集合に属するか否か
bool same(int x,int y){
    return find(x)==find(y);
}
//////////////////////////////////////
struct edge{int u,v,cost;};
bool comp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}
#define MAX_E 1000000//調節！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
edge es[MAX_E];
int v,e;//頂点数vと辺数e

int kruskal(){
    sort(es,es+e,comp);
    init(v);
    int res=0;
    for(int i=0;i<e;i++){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}
///////////////////////////////////////////

struct P{
    int num,x,y;
};

bool ascx(const P &l,const P &r){
    return l.x<r.x;
}
bool ascy(const P &l,const P &r){
    return l.y<r.y;
}


int main(){
    int n;cin>>n;
    P p[n];
    for(int i=0;i<=n-1;i++){
        cin>>p[i].x>>p[i].y;
        p[i].num=i;
    }
    sort(p,p+n,ascx);
    for(int i=1;i<=n-1;i++){
        es[i-1]=edge{p[i-1].num,p[i].num,abs(p[i].x-p[i-1].x)};
    }
    sort(p,p+n,ascy);
    for(int i=1;i<=n-1;i++){
        es[n+i-2]=edge{p[i-1].num,p[i].num,abs(p[i].y-p[i-1].y)};
    }
    init(n);
    v=n;e=2*n-2;
    cout<<kruskal()<<endl;
    return 0;
}
