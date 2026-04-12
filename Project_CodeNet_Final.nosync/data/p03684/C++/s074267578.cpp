#include "bits/stdc++.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

const int MAX_E=200010;
struct edge{int u,v; ll cost;};
edge es[MAX_E];

int V, E;
int par[100009];
int height[100009];

void init(int n){
    for(int i=0; i<n; i++){
        par[i]=i;
        height[i]=0;
    }
}

int find(int x){
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}

void unite(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(height[x]<height[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(height[x]==height[y]) height[x]++;
    }
}

bool same (int x, int y){
    return find(x) == find(y);
}

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

int cruscal(){
    sort(es, es+E, comp);
    init(V);
    int res=0;
    rep(i,E){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    V=N,E=2*N-2;
    vector<pii> X,Y;
    rep(i,N){
        int x,y;cin>>x>>y;
        X.push_back({x,i});
        Y.push_back({y,i});
    }
    
    sort(all(X));
    sort(all(Y));
    rep(i,N-1){
        es[i]={X[i].second,X[i+1].second,X[i+1].first-X[i].first};
        es[N-1+i]={Y[i].second,Y[i+1].second,Y[i+1].first-Y[i].first};
    }
    cout1(cruscal())
}