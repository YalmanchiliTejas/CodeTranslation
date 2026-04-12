#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <queue>
#include <utility>
#include <map>
#include <tuple>
#include <set>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int ll;
typedef pair<ll, int> P;

template<typename T>
vector<T> make_v(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

const ll inf = 1LL << 60;
const ll mod = 1000000007;

ll Dijkstra(int s, int t, vector<vector<P>> &G) {
    vector<ll> Cost(G.size(), inf);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, s);
    while (pq.size()) {
        ll dist = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        if (Cost[vertex] < dist) continue;
        Cost[vertex] = dist;
        for (auto &edge : G[vertex]) {
            ll ndist = edge.first;
            int nvertex = edge.second;
            if (Cost[nvertex] > dist + ndist) {
                Cost[nvertex] = dist + ndist;
                pq.emplace(Cost[nvertex], nvertex);
            }
        }
    }
    return Cost[t];
}

map<P, pair<ll, ll>> halfGraph(int s, vector<vector<P>> &G, ll halfDist) {
    vector<ll> Cost(G.size(), inf);
    vector<ll> Comb(G.size(), 0);
    vector<bool> used(G.size(), false);
    using Tp = tuple<ll, int, int, bool>;
    priority_queue<Tp, vector<Tp>, greater<Tp>> pq;
    pq.emplace(0, -1, s, false);
    Comb[s] = 1;
    map<P, pair<ll, ll>> m;
    while (pq.size()) {
        ll dist;
        int vertex, prev;
        bool ishalf;
        tie(dist, prev, vertex, ishalf) = pq.top();
        pq.pop();

        if (Cost[vertex] < dist) continue;
        Cost[vertex] = dist;

        if (ishalf) {
            m[{min(prev, vertex), max(prev, vertex)}] = {Comb[prev], Cost[min(prev, vertex)]};
        }

        if (used[vertex]) continue;
        used[vertex] = true;

        for (auto &edge : G[vertex]) {
            ll ndist = edge.first;
            int nvertex = edge.second;
            if (Cost[nvertex] == dist + ndist) {
                Comb[nvertex] = (Comb[nvertex] + Comb[vertex]) % mod;
                bool flg = (Cost[vertex] < halfDist && halfDist <= Cost[nvertex]);
                if (halfDist == Cost[nvertex]) {
                    pq.emplace(Cost[nvertex], nvertex, nvertex, flg);
                } else {
                    pq.emplace(Cost[nvertex], vertex, nvertex, flg);
                }
            } else if (Cost[nvertex] > dist + ndist) {
                Cost[nvertex] = dist + ndist;
                Comb[nvertex] = Comb[vertex];
                bool flg = (Cost[vertex] < halfDist && halfDist <= Cost[nvertex]);
                if (halfDist == Cost[nvertex]) {
                    pq.emplace(Cost[nvertex], nvertex, nvertex, flg);
                } else {
                    pq.emplace(Cost[nvertex], vertex, nvertex, flg);
                }
            }
        }
    }
    return m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    S--;
    T--;
    vector<vector<P>> G(N);

    REP(i, 0, M) {
        int U, V;
        ll D;
        cin >> U >> V >> D;
        U--;
        V--;
        G[U].push_back({2 * D, V});
        G[V].push_back({2 * D, U});
    }

    ll spath = Dijkstra(S, T, G) / 2;
    auto m1 = halfGraph(S, G, spath);
    auto m2 = halfGraph(T, G, spath);

    set<P> s;
    for (auto &elem : m1) {
        if (m2.count(elem.first)) {
            s.insert(elem.first);
        }
    }

    /*
    for (auto &elem : m1) {
        cout << "(" << elem.first.first + 1 << ", " << elem.first.second + 1 << ")" << endl;
    }

    cout << endl;

    for (auto &elem : m2) {
        cout << "(" << elem.first.first + 1 << ", " << elem.first.second + 1 << ")" << endl;
    }
    //*/

    ll sum1 = 0, sm = 0;
    for (auto &elem : s) {
        if (m1[elem].second + m2[elem].second != spath * 2) continue;
        ll a = (m1[elem].first * m2[elem].first) % mod;
        sum1 = (sum1 + a * a % mod) % mod;
        // sum2 = (sum2 + m2[elem].first) % mod;
        sm = (sm + a) % mod;
    }

    //dump(spath);

    cout << (sm * sm % mod - sum1 + mod) % mod << endl;

    return 0;
}
