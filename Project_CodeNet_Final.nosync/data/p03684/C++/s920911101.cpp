#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

#define MAX_N 100005

int parent[MAX_N];
int ran[MAX_N];

void init(int n){
    int i;
    rep(i,n){
        parent[i]=i;
        ran[i]=0;
    }
}

int find(int x){
    if(parent[x]==x)return x;
    else return parent[x]=find(parent[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;

    if(ran[x]<ran[y])
        parent[x]=y;
    else{
        parent[y]=x;
        if(ran[x]==ran[y])ran[x]++;
    }
}

struct edge{ int u,v,cost;};

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

edge es[2*MAX_N];
int v,e=0;

int kruskal(){
    sort(es,es+e,comp);
    init(v);
    int res=0,i;
    rep(i,e){
        edge e=es[i];
        if(find(e.u) != find(e.v)){
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}

int main(void) {
    int i,j;
    int n;
    cin>>n;
    v=n;

    vector<pair<pii,int> > p(n);
    rep(i,n)cin>>p[i].first.first>>p[i].first.second,p[i].second=i;

    sort(all(p));
    rep(i,n-1){
        es[e].u=p[i].second;
        es[e].v=p[i+1].second;
        es[e].cost=min(abs(p[i].first.first-p[i+1].first.first), abs(p[i].first.second-p[i+1].first.second));
        e++;
    }
    rep(i,n)swap(p[i].first.first,p[i].first.second);
    sort(all(p));
    rep(i,n-1){                 
         es[e].u=p[i].second;              
         es[e].v=p[i+1].second;
         es[e].cost=min(abs(p[i].first.first-p[i+1].first.first), abs(p[i].first.second-p[i+1].first.second));
         e++;
    }

    cout<<kruskal()<<endl;
}

