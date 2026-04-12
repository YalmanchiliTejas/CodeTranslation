#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>

#include<queue>
using namespace std;
#define REP(i,k,n) for(int i=k;i<n;i++)
 
#define INF 1844674407370955161
typedef long long int ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define MOD 1000000007


class DisjointSet{
    public:
        vector<int> rank, p;

        DisjointSet(){
        }

        DisjointSet(int size){
            rank.resize(size, 0);
            p.resize(size, 0);
            for (int i = 0; i < size;i++)
                makeSet(i);
        }
        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }

        bool same(int x,int y){
            return findSet(x) == findSet(y);
        }
        void unite(int x,int y){
            link(findSet(x), findSet(y));
        }
        void link(int x,int y){
            if(rank[x]>rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x]==rank[y]){
                    rank[y]++;
                }
            }
        }
        int findSet(int x){
            if(x!=p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};

class Edge{
    public:
        int source, target;
        ll cost;
        Edge(int source = 0, int target = 0, ll cost = 0):
        source(source),target(target),cost(cost){}
        bool operator < (const Edge &e) const{
            return cost < e.cost;
        }
};

ll kruskal(int N,vector<Edge> edges){
    ll totalCost = 0;
    sort(edges.begin(), edges.end());
    DisjointSet dset = DisjointSet(N + 1);

    for (int i = 0; i < N;i++)
        dset.makeSet(i);

    int source, target;
    REP(i,0,edges.size()){
        Edge e = edges[i];
        if(!dset.same(e.source,e.target)){
            totalCost += e.cost;
            dset.unite(e.source, e.target);
        }
    }

    return totalCost;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<ll, int> > x;
    vector<pair<ll, int> > y;
    
    REP(i,0,N){
        ll xx, yy;
        cin >> xx >> yy;
        x.push_back(make_pair(xx, i));
        y.push_back(make_pair(yy, i));
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<Edge> edges;
    REP(i, 0, N - 1)
    {
        edges.push_back(Edge(x[i].second, x[i + 1].second, abs(x[i].first - x[i + 1].first)));
        edges.push_back(Edge(y[i].second, y[i + 1].second, abs(y[i].first - y[i + 1].first)));
    }
    cout << kruskal(N, edges) << endl;
}