#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//改造
typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e18
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
class Dijkstra {
public:
    using T = long long int;
    typedef pair<T, int> P; //firstは最短距離、secondは頂点の番号
    const T inf = (T) 5e18;
    struct edge {
        int to;
        T cost;
    };

    int V;                  //超点数
    vector<vector<edge>> G; //グラフ,G[i]はiから出る辺の集合,G[i][j]はiから出る辺のj番目の辺
    vector<T> d;           //最短距離
    vector<T> C;           // 組み合わせ

    //0origin
    Dijkstra(int N) {
        V = N;
        G = vector<vector<edge >>(N);
        d = vector<T>(N);
        C.resize(N, 0);

    };

    void dijkstra(int s) {
        priority_queue<P, vector<P>, greater<P>> que;
        fill(d.begin(), d.end(), inf);
        d[s] = 0;
        C[s] = 1;
        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (d[v] < p.first)
                continue;
            for (int i = 0; i < G[v].size(); i++) {
                edge e = G[v][i];
                if (d[e.to] > d[v] + e.cost && !(d[e.to] == inf && d[v] == inf)) {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                    C[e.to] = C[v];

                } else if (d[e.to] == d[v] + e.cost && !(d[e.to] == inf && d[v] == inf)) {
                    C[e.to] += C[v];
                    C[e.to] %= MOD;
                }
            }
        }
    }

    /* 頂点fromに頂点toに達するコストcostの辺を貼る */
    void addEdge(int from, int to, T cost) {
        edge e;
        e.to = to;
        e.cost = cost;
        G[from].push_back(e);
    }

    T getDist(int v) {
        return d[v];
    }

    T getComb(int v) {
        return C[v];
    }
};

class Solve {
public:
    Int N, M;
    Int S, T;
    struct edge {
        int from;
        int to;
        Int dist;
    };
    vector<edge> ve;

    Int modsub(Int a, Int b) {
        Int ret = a - b;
        ret %= MOD;
        if (ret < 0) ret += MOD;
        return ret;
    }


    void solve() {
        cin >> N >> M;
        cin >> S >> T;
        S--, T--;

        for (int i = 0; i < M; ++i) {
            int from, to;
            Int dist;
            cin >> from >> to >> dist;
            from--;
            to--;

            edge e1{from, to, dist};
            ve.push_back(e1);
        }
        if (ve.size() != M) {
            exit(-1);
        }

        Dijkstra dij1(N), dij2(N);
        for (auto e : ve) {
            dij1.addEdge(e.from, e.to, e.dist);
            dij1.addEdge(e.to, e.from, e.dist);
            dij2.addEdge(e.from, e.to, e.dist);
            dij2.addEdge(e.to, e.from, e.dist);
        }

        dij1.dijkstra(S);
        dij2.dijkstra(T);

        Int sdist = dij1.getDist(T);

        if (dij1.getDist(T) != dij2.getDist(S)) {
            exit(-1);
        }

//        Int mdist = sdist / 2; // 中間地点

        Int ans = dij1.getComb(T) * dij2.getComb(S) % MOD;

        for (int i = 0; i < N; ++i) {
            if (dij1.getDist(i) * 2ll == sdist) {
                Int tmp = dij1.getComb(i) * dij2.getComb(i) % MOD;
                tmp = (tmp * tmp) % MOD;
                ans = modsub(ans, tmp);
            }
        }

        for (auto e : ve) {
            int a = e.from;
            int b = e.to;
            if (sdist > 2ll * dij1.getDist(a) && sdist > 2ll * dij2.getDist(b)) {
                if (dij1.getDist(a) + dij2.getDist(b) + e.dist == sdist) {
                    Int tmp = dij1.getComb(a) * dij2.getComb(b) % MOD;
                    tmp = (tmp * tmp) % MOD;
                    ans = modsub(ans, tmp);
                }
            }

            if (sdist > 2ll * dij1.getDist(b) && sdist > 2ll * dij2.getDist(a)) {
                if (dij1.getDist(b) + dij2.getDist(a) + e.dist == sdist) {
                    Int tmp = dij1.getComb(b) * dij2.getComb(a) % MOD;
                    tmp = (tmp * tmp) % MOD;
                    ans = modsub(ans, tmp);
                }
            }

        }

        cout << ans << endl;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
