#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct Edge {
    int src, dest, cost;
    Edge(int dest, int cost) : src(-1), dest(dest), cost(cost) {}
    Edge(int src, int dest, int cost) : src(src), dest(dest), cost(cost) {}
};

int prim(vector<vector<Edge>> g){
    int ans = 0;
    vb used(g.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if (used[p.second]) continue;
        used[p.second] = true;
        ans += p.first;
        for (Edge &e : g[p.second]) {
            pq.emplace(e.cost, e.dest);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, x, y;
    cin >> n;

    vector<pair<pair<int, int>, int>> srtx, srty;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        srtx.emplace_back(make_pair(x, y), i);
        srty.emplace_back(make_pair(y, x), i);
    }
    sort(all(srtx));
    sort(all(srty));

    int a, b, c, d, p1, p2, cost;
    vector<vector<Edge>> g(n);
    for (int i = 0; i < n - 1; i++){
        a = srtx[i].first.first;
        b = srtx[i].first.second;
        c = srtx[i + 1].first.first;
        d = srtx[i + 1].first.second;
        p1 = srtx[i].second;
        p2 = srtx[i + 1].second;
        cost = min(abs(a - c), abs(b - d));
        g[p1].emplace_back(p2, cost);
        g[p2].emplace_back(p1, cost);

        a = srty[i].first.first;
        b = srty[i].first.second;
        c = srty[i + 1].first.first;
        d = srty[i + 1].first.second;
        p1 = srty[i].second;
        p2 = srty[i + 1].second;
        cost = min(abs(a - c), abs(b - d));
        g[p1].emplace_back(p2, cost);
        g[p2].emplace_back(p1, cost);
    }

    cout << prim(g) << endl;

    return 0;
}
