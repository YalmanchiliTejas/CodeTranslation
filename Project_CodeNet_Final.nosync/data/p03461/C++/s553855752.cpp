#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cassert>
#include <tuple>
#include <list>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <complex>
#include <memory>

using namespace std;

typedef long long ll;
typedef long double ld;

template<class htpe, class cmp>
using heap = priority_queue<htpe, vector<htpe>, cmp>;

template<class htpe>
using min_heap = heap<htpe, greater<htpe> >;

template<class htpe>
using max_heap = heap<htpe, less<htpe> >;

#define mp make_pair
#define pb push_back
#define mt make_tuple
#define ff first
#define ss second

#define forn(i, n) for (int i = 0; i < ((int)(n)); ++i)
#define forrn(i, s, n) for (int i = (int)(s); i < ((int)(n)); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define PYMOD(a, m) ((((a) % (m)) + (m)) % (m))

const int INF = 1791791791;
const ll INFLL = 1791791791791791791ll;

struct edge {
    int u, v;
    edge(int _u, int _v) {
        u = _u, v = _v;
    }
    int from() { return u; }
    int to() { return v; }
    virtual int get_cost() = 0;
    virtual void print() = 0;
};

struct cost_edge : public edge {
    int w;
    cost_edge(int u, int v, int _w) : edge(u, v) {
        w = _w;
    }
    virtual int get_cost() { return w; }
    virtual void print() { cout << from() + 1 << " " << to() + 1 << " " << w << endl; }
};

int x, y;

struct x_edge : public edge {
    x_edge(int u, int v) : edge(u, v) { }
    virtual int get_cost() { return x; }
    virtual void print() { cout << from() + 1 << " " << to() + 1 << " X" << endl; }
};

struct y_edge : public edge {
    y_edge(int u, int v) : edge(u, v) { }
    virtual int get_cost() { return y; }
    virtual void print() { cout << from() + 1 << " " << to() + 1 << " Y" << endl; }
};

void impossible() {
    cout << "Impossible" << endl;
    exit(0);
}

int d[10][10];

const int n = 203;
vector<shared_ptr<edge> > graph[n];

int dijkstra(int s, int t) {
    min_heap<pair<int, int> > pq;
    vector<int> dist(n, INF);
    vector<bool> vis(n, false);
    dist[s] = 0;
    pq.push(mp(0, s));
    while (!pq.empty()) {
        auto pp = pq.top();
        pq.pop();
        //cout << pp.ss << " " << pp.ff << endl;
        if (vis[pp.ss])
            continue;
        vis[pp.ss] = true;
        for (auto e : graph[pp.ss]) {
            if (!vis[e->to()]) {
                if (dist[e->to()] > dist[e->from()] + e->get_cost()) {
                    dist[e->to()] = dist[e->from()] + e->get_cost();
                    pq.push(mp(dist[e->to()], e->to()));
                }
            }
        }
    }
    //cout << x << " " << y << " " << dist[0] << " " << dist[1] << " " << dist[201] << " " << dist[202] << endl;
    return dist[t];
}

int main() {
    // Code here:

    int a, b;
    cin >> a >> b;
    forn(i, a)
        forn(j, b)
            cin >> d[i][j];

    forn(i, 100) {
        graph[i].pb(make_shared<x_edge>(i, i + 1));
        graph[102 + i].pb(make_shared<y_edge>(102 + i, 102 + i + 1));
    }
    int s = 0, t = 202;
    forn(i, 101) {
        forn(j, 101) {
            int w = 0;
            forn(x, a) {
                forn(y, b) {
                    w = max(w, d[x][y] - (x + 1) * i - (y + 1) * j);
                }
            }
            graph[i].pb(make_shared<cost_edge>(i, 202 - j, w));
        }
    }

    forn(i, a) {
        forn(j, b) {
            x = i + 1, y = j + 1;
            if (dijkstra(s, t) != d[i][j]) {
                //cerr << x << " " << y << " " << dijkstra(s, t) << " " << d[i][j] << endl;
                impossible();
            }
        }
    }

    cout << "Possible" << endl;
    cout << n << " " << 100 + 100 + 101 * 101 << endl;
    forn(i, n) {
        for (auto e : graph[i]) {
            e->print();
        }
    }
    cout << s + 1 << " " << t + 1 << endl;

    return 0;
}