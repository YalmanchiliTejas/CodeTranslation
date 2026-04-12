#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#define FI first
#define SE second
#define VE vector<int>
#define PB push_back
#define PA pair<int,int>
#define MA make_pair
#define LLI long long int
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define POS(i) cout<<(i?"POSSIBLE":"IMPOSSIBLE")<<endl
#define Pos(i) cout<<(i?"Possible":"Impossible")<<endl
#define co(i) cout<<i<<endl
using namespace std;
//
const int INF=1e9+7;
const int MOD=1e9+7;
//
const int MAX_N=300000;
int par[MAX_N];
int rnk[MAX_N];

void init(int n){
    FOR(i,0,n){
        par[i]=i;
        rnk[i]=0;
    }
}

int find(int x){
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(rnk[x]<rnk[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(rnk[x]==rnk[y]) rnk[x]++;
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

const int MAX_E=300000;
struct edge{int u,v,cost;};
bool comp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}
edge es[MAX_E];
int V,E;
int kruskal(){
    sort(es,es+E,comp);
    init(V);
    int res=0;
    FOR(i,0,E){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}

int main(){
    vector<PA> xv,yv;
    int n; cin>>n;
    FOR(i,0,n){
        int x,y; cin>>x>>y;
        xv.PB(PA(x,i));
        yv.PB(PA(y,i));
    }
    sort(xv.begin(),xv.end());
    sort(yv.begin(),yv.end());
    int k=0;
    FOR(i,0,n-1){
        es[k]={xv[i].SE,xv[i+1].SE,abs(xv[i].FI-xv[i+1].FI)};
        k++;
        es[k]={yv[i].SE,yv[i+1].SE,abs(yv[i].FI-yv[i+1].FI)};
        k++;
    }
    V=n; E=k;
    co(kruskal());
}
