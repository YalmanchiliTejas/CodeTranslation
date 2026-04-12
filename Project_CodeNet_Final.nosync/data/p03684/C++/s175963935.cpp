#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

class Edge{
public:
    ll w;
    int f;
    int s;

    Edge(ll a=0, int b=0, int c=0) : w(a), f(b), s(c) {}

    bool operator < (const Edge& e2){
        return w < e2.w;
    }
};

#define MAX_N 100100
int par[MAX_N];
int rank_u[MAX_N];

vector<P> x;
vector<P> y;

void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        rank_u[i] = 0;
    }
}

//木の根を求める
int find(int x){
    if(par[x] == x){
        return x;
    }
    else{
        return par[x] = find(par[x]);
    }
}

// xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)  return;

    if(rank_u[x] < rank_u[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
        if(rank_u[x] == rank_u[y])  rank_u[x]++;
    }
}

//xとyが同じ集合に属するかどうか
bool same(int x, int y){
    return find(x) == find(y);
}

vector<Edge> x_edge;
vector<Edge> y_edge;


int main(){
    int N;  cin >> N;
    for(int i = 0; i < N; i++){
        ll xx, yy;    cin >> xx >> yy;
        x.emplace_back(P(xx, i));
        y.emplace_back(P(yy, i));
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for(int i = 0; i < N-1; i++) {
        Edge ex(x[i+1].first - x[i].first, x[i].second, x[i+1].second);
        x_edge.push_back(ex);

        Edge ey(y[i+1].first - y[i].first, y[i].second, y[i+1].second);
        y_edge.push_back(ey);
    }

    sort(x_edge.begin(), x_edge.end());
    sort(y_edge.begin(), y_edge.end());

    int xi = 0, yi = 0;
    ll res = 0;
    init(N);
    while(xi < x_edge.size() && yi < y_edge.size()){
        Edge e;
        if(x_edge[xi] < y_edge[yi]){
            e = x_edge[xi];
            xi++;
        }
        else{
            e = y_edge[yi];
            yi++;
        }

        if(same(e.f, e.s))  continue;
        else{
            unite(e.f, e.s);
            res += e.w;
        }
    }

    cout << res << endl;



    return 0;
}