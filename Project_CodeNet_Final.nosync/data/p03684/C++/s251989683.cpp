#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdint>
#include <climits>
#include <unordered_set>
#include <sstream>
#include <stack>

using namespace std;

#define ll long long int
#define pii std::pair<long long int, int>


namespace Workspace
{
    struct UnionFind {
        std::vector<int> data;
        
        UnionFind(int size) : data(size, -1) { }
        
        bool unionSet(int x, int y) {
            x = root(x); y = root(y);
            if (x != y)
            {
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
    
    typedef long long Weight;
    
    struct Edge
    {
        long long cost;
        int from;
        int to;
        
        Edge() : cost(0), from(0), to(0){}
        
        Edge(long long cost_, int from_, int to_) : cost(cost_), from(from_), to(to_)
        {
            
        }
        
        bool operator<(const Edge& rhs) const
        {
            return cost < rhs.cost;
        }

        bool operator>(const Edge& rhs) const
        {
            return cost > rhs.cost;
        }

        bool operator()(Edge& __x, Edge& __y)
        {
            return __x.cost > __y.cost;
        }
    };
    

    
    typedef std::vector<Edge> Edges;
    
    typedef std::vector<Edges> Graph;
    
    struct minimumSpanningForest
    {
        static std::pair<Weight, Edges> get(const Graph& g)
        {
            int n = (int)g.size();
            UnionFind u(n);
            std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> q;
            for(int i = 0;i < n;i++)
            {
                for(auto& e : g[i])
                {
                    if(i < e.to)
                    {
                        q.push(e);
                    }
                }
            }
            Weight total = 0;
            Edges f;
            while(f.size() < n-1 && !q.empty())
            {
                Edge e = q.top(); q.pop();
                if(u.unionSet(e.from, e.to))
                {
                    f.push_back(e);
                    total += e.cost;
                }
            }
            return std::make_pair(total, f);
        }
    };
}

using namespace Workspace;

int main()
{
    int n;
    cin >> n;
    vector<pii> x(n), y(n);
    for(int i = 0;i < n;i++)
    {
        ll xx, yy;
        cin >> xx >> yy;
        x[i] = make_pair(xx, i);
        y[i] = make_pair(yy, i);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    Workspace::Graph g(n);
    for(int i = 0;i < n-1;i++)
    {
        auto x1 = x[i];
        auto x2 = x[i + 1];
        auto dist = abs(x2.first - x1.first);
        g[x1.second].push_back(Edge(dist, x1.second, x2.second));
        g[x2.second].push_back(Edge(dist, x2.second, x1.second));
        auto y1 = y[i];
        auto y2 = y[i+1];
        dist = abs(y2.first - y1.first);
        g[y1.second].push_back(Edge(dist, y1.second, y2.second));
        g[y2.second].push_back(Edge(dist, y2.second, y1.second));
    }
    auto result = Workspace::minimumSpanningForest::get(g);
    cout << result.first << endl;
    return 0;
}