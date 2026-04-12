#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
#define vv(a,b,c,d) vector<vector<a> >(b,vector<a>(c,d))
#define vvv(a,b,c,d,e) vector<vector<vector<a> > >(b,vv(a,c,d,e))
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

typedef long long Weight;
struct Edge {
    int from, to;
    Weight wei;
    Edge(int from_, int to_, Weight wei_) :from(from_), to(to_), wei(wei_) {}
};
typedef vector<Edge> Edges;
const Weight INFW = numeric_limits<Weight>::max();

struct Graph : public vector<Edges> {
    Graph() { }
    Graph(int V) : vector<Edges>(V) { }
    /*
    有向辺を追加する
    */
    void addEdge(int from, int to, Weight wei = 1) {
        (*this)[from].push_back(Edge(from, to, wei));
    }
    /*
    無向辺を追加する
    */
    void addUEdge(int u, int v, Weight wei = 1) {
        (*this)[u].push_back(Edge(u, v, wei));
        (*this)[v].push_back(Edge(v, u, wei));
    }
};

vector<Weight> dijkstra(const Graph &G, int src) {
    typedef pair<Weight, int> pwi;
    priority_queue<pwi, vector<pwi>, greater<pwi>> pq;
    pq.push(mp(0, src));
    int V = (int)G.size();
    vector<Weight> res(V, -1);
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        Weight d = p.first;
        int v = p.second;
        if (res[v] > -1)continue;
        res[v] = d;
        for (const auto &edge : G[v]) {
            int to = edge.to;
            Weight wei = edge.wei;
            pq.push(make_pair(d + wei, to));
        }
    }
    return res;
}

template<int MOD>
class ModInt {
public:
    ModInt() :value(0) {}
    ModInt(long long val) :value((int)(val<0 ? MOD + val%MOD : val%MOD)) { }

    ModInt& operator+=(ModInt that) {
        value = value + that.value;
        if (value >= MOD)value -= MOD;
        return *this;
    }
    ModInt& operator-=(ModInt that) {
        value -= that.value;
        if (value<0)value += MOD;
        return *this;
    }
    ModInt& operator*=(ModInt that) {
        value = (int)((long long)value * that.value % MOD);
        return *this;
    }
    ModInt &operator/=(ModInt that) {
        return *this *= that.inverse();
    }
    ModInt operator+(ModInt that) const {
        return ModInt(*this) += that;
    }
    ModInt operator-(ModInt that) const {
        return ModInt(*this) -= that;
    }
    ModInt operator*(ModInt that) const {
        return ModInt(*this) *= that;
    }
    ModInt operator/(ModInt that) const {
        return ModInt(*this) /= that;
    }
    ModInt pow(long long k) const {
        if (value == 0)return 0;
        ModInt n = *this, res = 1;
        while (k) {
            if (k & 1)res *= n;
            n *= n;
            k >>= 1;
        }
        return res;
    }
    ModInt inverse() const {
        long long a = value, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return ModInt(u);
    }
    int toi() const { return value; }

private:
    int value;
};
typedef ModInt<1000000007> mint;
ostream& operator<<(ostream& os, const mint& x) {
    os << x.toi();
    return os;
}

void f(Graph &G, vector<mint> &ways, vll &dis, int s, int t) {
    int N = sz(G);
    ways = vector<mint>(N);
    dis = dijkstra(G, s);

    vector<pair<ll, int>> vp(N);
    rep(i, N)vp[i] = mp(dis[i], i);
    sort(all(vp), greater<pair<ll,int> >());
    ways[t] = 1;
    each(p, vp) {
        int u = p.second;
        each(e, G[u]) {
            int v = e.to;
            Weight d = e.wei;
            if (dis[v] == dis[u] - d) {
                ways[v] += ways[u];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int N, M;
    cin >> N >> M;
    Graph G(N);
    int S, T;
    cin >> S >> T;
    --S;
    --T;
    rep(i, M) {
        int u, v, d;
        cin >> u >> v >> d;
        --u; --v;
        G.addUEdge(u, v, 2ll*d);
    }

    vll ds2t, dt2s;
    vector<mint> ws2t, wt2s;
    f(G, wt2s, ds2t, S, T);
    f(G, ws2t, dt2s, T, S);

    mint tot = ws2t[T];
    mint ans = tot * tot;
    ll D = ds2t[T];
    assert(D % 2 == 0);

    rep(i, N) {
        // 頂点iで出会う
        if (ds2t[i] == D / 2 && dt2s[i] == D / 2) {
            ans -= (ws2t[i] * wt2s[i])*(ws2t[i] * wt2s[i]);
        }

        // 辺eで出会う
        // l, r)
        each(e, G[i]) {
            int j = e.to;
            ll l = ds2t[i];
            ll d = e.wei;
            assert(l + d + dt2s[j] >= D);
            if (l < D / 2 && D / 2 < l + d && l + d + dt2s[j] == D) {
                mint ways = ws2t[i] * wt2s[j];
                ans -= ways*ways;
            }
        }
    }

    cout << ans << endl;
}