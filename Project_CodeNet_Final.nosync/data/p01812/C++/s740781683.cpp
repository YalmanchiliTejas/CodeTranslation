#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(_v) for(auto _x:_v){cout<<_x<<" ";}cout<<endl
#define printVS(vs) for(auto x : vs){cout << x << endl;}
#define printVV(_vv) for(auto _v:_vv){for(auto _x:_v){cout<<_x<<" ";}cout<<endl;}
#define printP(p) cout << p.first << " " << p.second << endl
#define printVP(vp) for(auto p : vp) printP(p);
#define readV(_v) rep(j, _v.size()) cin >> _v[j];
#define readVV(_vv) rep(i, _vv.size()) readV(_vv[i]);
#define print(_x) cout << _x << endl;

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<Pii> vp;
const int inf = 1e9;
const int mod = 1e9 + 7;

struct edge {
    int to, cost;
    edge(){}
    edge(int _to, int _cost) : to(_to), cost(_cost) {}
};
typedef vector<vector<edge>> Graph;
int dijkstra(const Graph& G, int s, int g) {
    int n = G.size();
    priority_queue<Pii, vector<Pii>, greater<Pii>> pq;   // cost, vertex
    vi d(n, inf);
    d[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int v = p.second;
        if (v == g) break;
        if (d[v] < p.first) continue;
        for (const auto& e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                pq.push(make_pair(d[e.to], e.to));
            }
        }
    }
    return d[g];
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vi D(M);
    rep(i, M) {
        cin >> D[i];
        D[i]--;
    }
    sort(all(D));
    vvi v(N, vi(K));
    rep(i, N) {
        rep(j, K) {
            cin >> v[i][j];
            v[i][j]--;
        }
    }

    map<int, int> mp;
    rep(i, M) {
        mp[D[i]] = i;
    }

    Graph G(1 << M);
    rrep(state, 1 << M) {
        rep(j, K) {
            int nstate = 0;
            rep(i, M) {
                if (!((state >> i) & 1)) continue;
                if (!mp.count(v[D[i]][j])) continue;
                nstate |= (1 << mp[v[D[i]][j]]);
            }
            if (nstate != state) {
                G[state].emplace_back(nstate, 1);
            }
        }
    }

    print(dijkstra(G, (1 << M) - 1, 0));
}