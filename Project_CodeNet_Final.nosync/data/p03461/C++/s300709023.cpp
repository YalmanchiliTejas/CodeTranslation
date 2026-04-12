#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define each(i,a) for (auto&& i : a)
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define chmin(x,v) x = min(x, v)
#define chmax(x,v) x = max(x, v)

const ll linf = 1e18;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    each(x,vec) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    rep(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector< vector<T> >& vec) {
    rep(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}
ll mx(const vector<vector<ll>>& v) {
    ll res = 0;
    each(vv, v) {
        chmax(res, *max_element(all(vv)));
    }
    return res;
}
class Graph {
    struct Edge {
        ll from, to;
        string label;
    };
    ll n;
    set<P> s;
    vector<Edge> edges;
public:
    Graph(ll n) : n(n) {}
    void add(ll from, ll to, string label) {
        if (s.count({from, to}) > 0) return;
        s.insert({from, to});
        edges.pb({from, to, label});
    }
    void addX(ll from, ll to) {
        add(from, to, "X");
    }
    void addY(ll from, ll to) {
        add(from, to, "Y");
    }
    void add(ll from, ll to, ll cost) {
        add(from, to, to_string(cost));
    }
    void output(ll s, ll t) {
        assert(n <= 300);
        if (n <= 300) {
            cout << "Possible" << endl;
            cout << n << " " << edges.size() << endl;
            each(e, edges) {
                cout << e.from+1 << " " << e.to+1 << " " << e.label << endl;
            }
            cout << s+1 << " " << t+1 << endl;
        }
        else {
            cout << "Impossible" << endl;
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll A, B; cin >> A >> B;
    vector<vector<ll>> d(A, vector<ll>(B)); cin >> d;
    vector<vector<ll>> X(A, vector<ll>(B, -1));
    vector<vector<ll>> Y(A, vector<ll>(B, -1));
    vector<vector<ll>> Z(A, vector<ll>(B, -1));
    rep(a, A) rep(b, B) {
        bool is_find = false;
        rep(x, 101) {
            if (x * a > d[a][b]) break;
            rep(y, 101) {
                ll z = d[a][b] - (x * (a+1) + y * (b+1));
                if (z < 0) break;
                if (z > 100) continue;
                bool f = true;
                rep(aa, A) rep(bb, B) {
                    if ((aa+1) * x + (bb+1) * y + z < d[aa][bb]) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    X[a][b] = x;
                    Y[a][b] = y;
                    Z[a][b] = z;
                    is_find = true;
                    break;
                }
            }
            if (is_find) break;
        }
        if (!is_find) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    // assert(false);
    // ll w = mx(X)+1;
    // ll h = mx(Y)+1;
    // if (w * h > 300) {
    //     cout << "Impossible" << endl;
    //     return 0;
    // }
    ll V = 0;
    vector<ll> xid(101), yid(101);
    rep(i, 101) xid[i] = V++;
    rep(i, 101) yid[i] = V++;
    ll s = V++, t = V++;
    Graph G(V);
    G.add(s, xid[0], 0);
    rep(i, 100) G.addX(xid[i], xid[i+1]);
    rep(i, 100) G.addY(yid[i+1], yid[i]);
    G.add(yid[0], t, 0);
    rep(a, A) rep(b, B) {
        G.add(xid[X[a][b]], yid[Y[a][b]], Z[a][b]);
    }
    G.output(s, t);
}
