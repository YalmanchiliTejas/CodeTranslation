#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<P> &s, P a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long>> PQ_ASK;


void print_line(vector<string> &line) {
    if (line.size() == 0ll) {
        cout << endl;
        return;
    }
    for (ll i = 0; i < line.size(); i++) {
        cout << line[i];
        if (i == line.size() - 1) cout << endl;
        else cout << ' ';
    }
}

typedef int Weight;

struct Edge {
    int src, dst;
    Weight weight;

    Edge(int src, int dst, Weight weight) :
            src(src), dst(dst), weight(weight) {}
};

bool operator<(const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
           e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

Weight visit(const Graph &g, Graph &T, int i, int j) {
    if (T[i][j].weight >= 0) return T[i][j].weight;
    T[i][j].weight = g[i][j].weight;
    int u = T[i][j].dst;
    rep(k, T[u].size()) {
        if (T[u][k].dst == i) continue;
        T[i][j].weight = max(T[i][j].weight, visit(g, T, u, k) + g[i][j].weight);
    }
    return T[i][j].weight;
}

vector<Weight> height(const Graph &g) {
    const int n = g.size();
    Graph T(g); // memoise on tree
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < T[i].size(); ++j)
            T[i][j].weight = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < T[i].size(); ++j)
            if (T[i][j].weight < 0)
                T[i][j].weight = visit(g, T, i, j);

    vector<Weight> ht(n); // gather results
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < T[i].size(); ++j)
            ht[i] = max(ht[i], T[i][j].weight);
    return ht;
}

int main() {
    int n;
    cin >> n;

    Graph g(n);

    rep(i, n - 1) {
        int s, t, w;
        cin >> s >> t >> w;
        Edge edge1(s, t, w);
        Edge edge2(t, s, w);
        g[s].push_back(edge1);
        g[t].push_back(edge2);
    }

    vector<Weight> ans = height(g);

    for(Weight w : ans) cout << w << endl;

}

