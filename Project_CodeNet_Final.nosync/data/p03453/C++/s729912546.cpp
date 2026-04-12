#define LOCAL

#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iomanip>

using namespace std;

// From Errichto's Youtube stream
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using int64 = long long;

/////////////////////
// Code starts here//
/////////////////////
const int MOD = 1000000007;
const int64 INF = (1LL<<60);

int N, M, S, T;
vector<vector<pair<int, int>>> g;

vector<int64> Sd, Td;
vector<int> Sways, Tways;

void add (int & a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int mul (int a, int b) {
    return (int64)a * b % MOD;
}

void Dijkstra(vector<int64>& d, vector<int>& ways, int from, int to) {
    d.assign(N, INF);
    ways.assign(N, 0);

    ways[from] = 1;
    d[from] = 0;

    set<pair<int64, int>> heap;

    heap.insert({0, from});

    while (!heap.empty()) {
        auto cur = *heap.begin();
        heap.erase(heap.begin());

        int el = cur.second;

        for (auto entry : g[el]) {
            auto v = entry.first;
            auto cost = entry.second;

            if (d[v] > d[el] + cost) {
                heap.erase({d[v], v});
                d[v] = d[el] + cost;
                heap.insert({d[v], v});
                ways[v] = ways[el];
            } else if (d[v] == d[el] + cost) {
                add(ways[v], ways[el]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    cin >> S >> T;
    S--, T--;

    g.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;

        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }

    Dijkstra(Sd, Sways, S, T);
    Dijkstra(Td, Tways, T, S);

    int64 min_dist = Sd[T];

    if (Sways[T] != Tways[S]) {
        debug() << "Wtf\n";
        return 0;
    }

    int result = mul(Sways[T], Sways[T]);

    debug() << "initial: " << result << " " << Sd[T];

    for (int i = 0; i < N; i++) {
        if (Sd[i] + Td[i] == min_dist) {
            if (Sd[i] == Td[i]) {
                int val = mul(Sways[i], Tways[i]);

                add(result, MOD - mul(val, val));

                //debug() << i;
            } else {
                for (auto entry : g[i]) {
                    auto v = entry.first;
                    auto cost = entry.second;

                    if (Sd[v] > Sd[i] && Sd[i] + cost + Td[v] == min_dist) {
                        if (Sd[i] < min_dist / 2 && Td[v] < min_dist / 2) {
                            int val = mul(Sways[i], Tways[v]);
                            //debug() << i + 1 << " " << v + 1 << " - " << mul(Sways[i], Tways[v]);
                            add(result, MOD - mul(val, val));
                        }
                    }
                }
            }
        }
    }

    cout << result << "\n";

    return 0;
}
