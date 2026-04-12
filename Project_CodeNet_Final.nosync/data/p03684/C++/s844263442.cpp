#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;
const int DIV = 1e9+7;

int n;
struct inp{int x, y, id;};
struct edge{int u, v, cost;};
vector<inp> inputs;
vector<edge> edges;
bool xsort(const inp& left, const inp& right){
    return left.x == right.x ? left.y < right.y : left.x < right.x;
}
bool ysort(const inp& left, const inp& right){
    return left.y == right.y ? left.x < right.x : left.y < right.y;
}
bool costs(const edge& left, const edge& right){
    return left.cost == right.cost ? left.u < right.u : left.cost < right.cost;
}

int par[101010];
int ranki[101010];

void init(int n){
    rep(i, n){
        par[i] = i;
        ranki[i] = 0;
    }
}
int find(int x){
    if(par[x] == x){
        return x;
    }
    else{
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(ranki[x] < ranki[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
        if(ranki[x] == ranki[y]) ranki[x]++;
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

int kruskal(){
    init(n);
    int res = 0;
    rep(i, edges.size()){
        edge e = edges[i];
        if(!same(e.u, e.v)){
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main(){
    cin >> n;
    inp in;
    int a, b;
    rep(i, n){
        cin >> a >> b;
        in.id = i;
        in.x = a;
        in.y = b;
        inputs.pb(in);
    }
    /*
    rep(i,n){
        cout << inputs[i].x << " " << inputs[i].y << " " << inputs[i].id << endl;
        }*/
    sort(inputs.begin(), inputs.end(), xsort);
    edge inedge;
    rep(i, n){
        if(i == n-1){
            continue;
        }
        else{
            inedge.u = inputs[i].id;
            inedge.v = inputs[i+1].id;
            inedge.cost = inputs[i+1].x - inputs[i].x;
            edges.pb(inedge);
        }
    }
    sort(inputs.begin(), inputs.end(), ysort);
    rep(i, n){
        if(i == n-1){
            continue;
        }
        else{
            inedge.u = inputs[i].id;
            inedge.v = inputs[i+1].id;
            inedge.cost = inputs[i+1].y - inputs[i].y;
            edges.pb(inedge);
        }
    }
    sort(edges.begin(),edges.end(),costs);
    cout << kruskal() << endl;
    return 0;
}
