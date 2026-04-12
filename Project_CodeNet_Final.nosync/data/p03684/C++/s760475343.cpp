#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define SORTR(v,n) sort(v, v+n, greater<int>());
// #define int long long    // %d=>%lld
#define pb push_back
#define INF (1e9+7)
#define llINF 1e17
#define EPS 1e-9
#define pi acos(-1)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> piii;
typedef pair<ll, pll> plll;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

void UnionFindInit(UnionFind uf,int a){
    for(int i=0;i<a;i++){
        uf.data.pb(i);
    }
}

struct edge{
    int u,v,cost;
    bool operator < ( const edge& right ) const {
        return cost < right.cost;
    }
};



const int MAX_V = pow(10,5);
UnionFind uf(MAX_V);
const int MAX_E = pow(10,5)*5;
int V,E;
int s,t,c;
edge G[MAX_E];


int kruskal(){
    SORT(G,E);
    UnionFindInit(uf,V);
    int res= 0;
    for(int i = 0;i < E;i++){
        if(!uf.findSet(G[i].u,G[i].v)){
            uf.unionSet(G[i].u,G[i].v);
            res += G[i].cost;
        }
    }
    return res;
}



signed main(){

    cin >> V;

    pii px[MAX_V];
    pii py[MAX_V];

    for(int i = 0;i < V;i++){
        cin >> px[i].first;
        cin >> py[i].first;
        px[i].second=i;
        py[i].second=i;

    }

    SORT(px,V);
    SORT(py,V);

    for(int i = 0;i < V-1;i++){
        G[i] = (edge){px[i].second,px[i+1].second,px[i+1].first-px[i].first};
        E++;
    }

    for(int i = 0;i < V-1;i++){
        G[i+V-1] = (edge){py[i].second,py[i+1].second,py[i+1].first-py[i].first};
        E++;
    }

    int ans = kruskal();
    cout <<  ans << endl;

    return 0;
}

