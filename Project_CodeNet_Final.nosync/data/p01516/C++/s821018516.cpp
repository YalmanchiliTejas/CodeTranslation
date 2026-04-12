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
#define output(_x) cout << _x << endl;

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<Pii> vp;
const int inf = 1e9;
const int mod = 1e9 + 7;

typedef complex<double> P;
typedef vector<P> G;
#define here(g, i) g[i]
#define next(g, i) g[(i + 1) % g.size()]
#define prev(g, i) g[(i - 1 + g.size()) % g.size()]
const double EPS = 1e-10;
const double INF = 1e12;
const double PI = acos(-1);

struct L {
    P a, b, v;
    L(){}
    L(P _a, P _b) : a(_a), b(_b), v(b - a) {}
    L(double _ax, double _ay, double _bx, double _by) : L(P(_ax, _ay), P(_bx, _by)) {}
};

double cross(P a, P b) {
    return imag(conj(a) * b);
}

double dot(P a, P b) {
    return real(conj(a) * b);
}

double deg2rad(double deg) {
    return deg * 2. * PI / 360;
}

// rot p around q by theta (counter-clockwise) 
P rotP(P p, P q, double theta) {
    p -= q;
    double x = p.real(), y = p.imag();
    p = P(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
    p += q;
    return p;
}

int ccw(P p0, P p1, P p2) {
    if (cross(p1 - p0, p2 - p0) > 0) return +1; // counter-clockwise
    if (cross(p1 - p0, p2 - p0) < 0) return -1; // clockwise
    if (dot(p1 - p0, p2 - p0) < 0) return +2;   // online_back
    if (dot(p0 - p1, p2 - p1) < 0) return -2;   // online_front
    return 0;                                   // on_segment
}

bool intersectSS(L l1, L l2) {
    return (ccw(l1.a, l1.b, l2.a) * ccw(l1.a, l1.b, l2.b) <= 0 &&
            ccw(l2.a, l2.b, l1.a) * ccw(l2.a, l2.b, l1.b) <= 0);
}

double distanceLP(L l, P p) {
    return abs(cross(l.v, p - l.a)) / abs(l.v);
}

double distanceSP(L l, P p) {
    if (dot(l.v, p - l.a) < 0) return abs(p - l.a);
    if (dot(-l.v, p - l.b) < 0) return abs(p - l.b);
    return distanceLP(l, p);
}

double distanceSS(L l1, L l2) {
    if (intersectSS(l1, l2)) return 0;
    double d = INF;
    d = min(d, distanceSP(l1, l2.a));
    d = min(d, distanceSP(l1, l2.b));
    d = min(d, distanceSP(l2, l1.a));
    d = min(d, distanceSP(l2, l1.b));
    return d;
}

struct Star {
    P c;
    double r;
    vector<P> p;
    vector<L> l;
    Star(){}
    Star(double x, double y, double deg, double _r) : c(x, y), r(_r) {
        rep(i, 5) {
            p.emplace_back(rotP(P(x, y + r), c, deg2rad(deg + 72 * i)));
        }
        rep(i, 5) {
            l.emplace_back(L(p[i], p[(i + 2) % 5]));
        }
    }
    double dist(const Star& o) {
        double ret = INF;
        rep(i, 5) {
            rep(j, 5) {
                ret = min(ret, distanceSS(l[i], o.l[j]));
            }
        }
        return ret;
    }
};

struct edge {
    int to;
    double cost;
    edge(){}
    edge(int _to, double _cost) : to(_to), cost(_cost) {}
};
typedef vector<vector<edge>> Graph;

// undirected
void addEdge(Graph& G, int x, int y, double c) {
    G[x].emplace_back(y, c);
    G[y].emplace_back(x, c);
}

double dijkstra(const Graph& G, int s, int g) {
    int n = G.size();
    using Pdi = pair<double, int>;
    priority_queue<Pdi, vector<Pdi>, greater<Pdi>> pq;   // cost, vertex
    vector<double> d(n, INF);
    d[s] = 0.;
    pq.push(make_pair(0., s));

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

    int n, s, g;
    while (cin >> n >> s >> g, n) {
        s--; g--;

        vector<Star> stars;
        rep(i, n) {
            int x, y, a, r;
            cin >> x >> y >> a >> r;
            stars.emplace_back(x, y, a, r);
        }

        Graph G(n);
        rep(i, n) {
            rep2(j, i + 1, n) {
                addEdge(G, i, j, stars[i].dist(stars[j]));
            }
        }

        cout << fixed << setprecision(20) << dijkstra(G, s, g) << endl;
    }
}