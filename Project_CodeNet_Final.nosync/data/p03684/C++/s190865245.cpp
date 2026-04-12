#include<bits/stdc++.h>
//#define int long long
#define loop(i, a, b) for(int i = a; i < b; i++)
#define rep(i, a) loop(i, 0, a)
#define all(a) (a).begin(),(a).end()
using namespace std;
const int MOD = 1e9 + 7, INF = 1e9;
using vi = vector <int>;
using vvi = vector <vi>;
//g++ -std==c++14

struct edge{int u, v, cost;};

bool comp(const edge& e1, const edge& e2){return e1.cost < e2.cost;}

int tree[100010];
int root(int x){return tree[x] == x ? x : tree[x] = root(tree[x]);}
void unite(int a , int b){tree[root(a)] = root(b);}

edge es[1000100];
int V, E;

int kruskal(){
    sort(es, es + E, comp);
    rep(i, V)tree[i] = i;
    int res = 0;
    rep(i, E){
        edge e = es[i];
        if(root(e.u) != root(e.v)){
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

struct point{int x, y, index;};
bool sort_x(const point& point1, const point& point2){return point1.x < point2.x;}
bool sort_y(const point& point1, const point& point2){return point1.y < point2.y;}

signed main(){
    cin >> V;
    point x_y[V];
    rep(i, V){
        cin >> x_y[i].x >> x_y[i].y;
        x_y[i].index = i;
    }
    int koko = 0;

    sort(x_y, x_y + V, sort_x);
    rep(i, V - 1){
        es[koko].u = x_y[i].index;
        es[koko].v = x_y[i + 1].index;
        es[koko].cost = min(abs(x_y[i].x - x_y[i + 1].x),abs(x_y[i].y - x_y[i + 1].y));
        koko++;
    }

    sort(x_y, x_y + V, sort_y);
    rep(i, V - 1){
        es[koko].u = x_y[i].index;
        es[koko].v = x_y[i + 1].index;
        es[koko].cost = min(abs(x_y[i].x - x_y[i + 1].x),abs(x_y[i].y - x_y[i + 1].y));
        koko++;
    }

    E = koko;

    cout << kruskal() << endl;

}
