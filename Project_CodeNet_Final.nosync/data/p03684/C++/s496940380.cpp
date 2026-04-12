#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll)(x).size())
typedef long long ll;
typedef vector<ll> VI;
typedef pair<ll,ll> PII;

void initialize(int* id,int MAX){
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x,int* id){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y,int* id){
    int p = root(x,id);
    int q = root(y,id);
    id[p] = id[q];
}

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    pair<int,int> x[n],y[n];
    rep(i,0,n){
        cin>>x[i].F>>y[i].F;
        x[i].S=y[i].S=i;
    }
    sort(x,x+n);
    sort(y,y+n);
    pair<int,pair<int,int> > edges[2*n-2];
    rep(i,0,n-1){
        edges[i] = mp(x[i+1].F-x[i].F,mp(x[i].S,x[i+1].S));
        edges[n-1+i] = mp(y[i+1].F-y[i].F,mp(y[i].S,y[i+1].S));
    }
    sort(edges,edges+(2*n-2));
    ll ans=0;
    int *id;
    id = new int[n];
    initialize(id,n);
    rep(i,0,2*n-2){
        if(root(edges[i].S.F,id)!=root(edges[i].S.S,id)){
            ans+=edges[i].F;
            union1(edges[i].S.F,edges[i].S.S,id);
        }
    }
    cout<<ans<<endl;
}