#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const int INFTY = (1 << 21);

class Edge{
public:
    int from, to, cost;
    Edge(int from = 0, int to = 0, int cost = 0) :
            from(from), to(to), cost(cost){}

    bool operator < (const Edge &e) const{
        return cost < e.cost;
    }
    bool operator >(const Edge &e) const{
        return cost > e.cost;
    }

};

class Node{
public:
    vector<Edge> edges;
    int dist;
    Node(){
        dist = INFTY;
    }
};

class Graph{
public:
    vector<Node> nodes;
    Graph(int n) {
        rep(i, n) { Node n;  nodes.push_back(n); }
    }
    Node& operator[](int i){
        return nodes[i];
    }
};

class Data{

public:
    int dist;
    Edge *edge;
    Data(int dist, Edge *edge) {
        this->dist = dist;
        this->edge = edge;
    }

    bool operator < (const Data &d) const{
        return dist < d.dist;
    }
    bool operator >(const Data &d) const{
        return dist > d.dist;
    }
};

Graph G(0);

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;

class City{
public:
    int i;
    ll x, y;
};

int N;
City cs[100000];

int main() {

    cin >> N;
    rep(i, N){
        cs[i].i = i;
        cin >> cs[i].x >> cs[i].y;
    }

    G = Graph(N);

    sort(&cs[0], &cs[N],  [](const City &a, const City &b) -> bool {return a.x < b.x; });
    // rep(i, N){ fprintf(stderr, "%d %d %d %d\n", i, cs[i].i, cs[i].x, cs[i].y); };
    rep(i, N-1){
        City c1 = cs[i]; City c2 = cs[i + 1];
        G[c1.i].edges.push_back(Edge(c1.i, c2.i, c2.x - c1.x));
        G[c2.i].edges.push_back(Edge(c2.i, c1.i, c2.x - c1.x));
    }
    sort(&cs[0], &cs[N],  [](const City &a, const City &b) -> bool {return a.y < b.y; });
    // rep(i, N){ fprintf(stderr, "%d %d %d %d\n", i, cs[i].i, cs[i].x, cs[i].y); };
    rep(i, N-1){
        City c1 = cs[i]; City c2 = cs[i + 1];
        G[c1.i].edges.push_back(Edge(c1.i, c2.i, c2.y - c1.y));
        G[c2.i].edges.push_back(Edge(c2.i, c1.i, c2.y - c1.y));
    }

    // prim
    priority_queue<Data, vector<Data>, greater<Data> > pq;
    Edge e0(-1, 0, 0);
    pq.push(Data(0, &e0));

    ll cost = 0;

    while (!pq.empty()){
        Data d = pq.top(); pq.pop();
        Edge& e = *d.edge;
        Node& n = G[e.to];
        if (n.dist != INFTY){ continue; }
        n.dist = 0;
        cost += e.cost;

        for (auto &ee : n.edges){
            Data d(ee.cost, &ee);
            pq.push(d);
        }
    }

    cout << cost << endl;

}