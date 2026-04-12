#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

template< typename T >
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;

struct UnionFind {
    vector< int > data;

    UnionFind(int sz) {
        data.assign(sz, -1);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k) {
        if(data[k] < 0) return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k) {
        return (-data[find(k)]);
    }
};

template< typename T >
T kruskal(Edges< T > &edges, int V) {
    sort(begin(edges), end(edges), [](const edge< T > &a, const edge< T > &b) {
        return (a.cost < b.cost);
    });
    UnionFind tree(V);
    T ret = 0;
    for(auto &e : edges) {
        if(tree.unite(e.src, e.to)) ret += e.cost;
    }
    return (ret);
}

int64_t cost(tuple<int,int,int> a, tuple<int,int,int> b) {
    return min(abs(get<0>(a) - get<0>(b)), abs(get<1>(a) - get<1>(b)));
}

int main(void) {
    int N;
    cin >> N;
    vector< tuple<int,int,int> > points;
    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y, i);
    }

    Edges<int64_t> g;
    sort(points.begin(), points.end());
    for(int i=0; i<N-1; i++) {
        g.emplace_back(get<2>(points[i]), get<2>(points[i+1]), cost(points[i], points[i+1]));
    }

    sort(points.begin(), points.end(), [](auto &lhs, auto &rhs) {return get<1>(lhs) < get<1>(rhs);});
    for(int i=0; i<N-1; i++) {
        g.emplace_back(get<2>(points[i]), get<2>(points[i+1]), cost(points[i], points[i+1]));
    }

    cout << kruskal(g, N) << endl;
    return 0;
}
