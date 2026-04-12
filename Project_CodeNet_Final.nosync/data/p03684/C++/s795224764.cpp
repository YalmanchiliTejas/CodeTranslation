#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<typename U, typename V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}
 
const int MAXN = 1e5 + 10;
int N;
struct Point {
    int x, y, idx;
} P[MAXN];

struct Edge {
    int u, v, d;
    bool operator<(const Edge &rhs) const {
        return make_tuple(d, u, v) < make_tuple(rhs.d, rhs.u, rhs.v);
    }
};
vector<Edge> edges;

struct DisjointSet {
    int N;
    vector<int> p;
    DisjointSet(int n) : N(n) {
        p.resize(N, -1);
    }
    
    int find(int a) {
        if(p[a] < 0) return a;
        return p[a] = find(p[a]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(p[a] > p[b]) swap(a, b);
        p[a] += p[b];
        p[b] = a;
    }
};

int main() {
    FAST_IO();
    cin >> N;
    rep(i, N) {
        cin >> P[i].x >> P[i].y;
        P[i].idx = i;
    }
    
    // sort by x
    sort(P, P + N, [] (const auto &lhs, const auto &rhs) {
       return make_pair(lhs.x, lhs.y) < make_pair(rhs.x, rhs.y); 
    });
    rep(i, N - 1) {
        edges.push_back({P[i].idx, P[i + 1].idx, P[i+1].x - P[i].x});
    }
    
    // sort by y
    sort(P, P + N, [] (const auto &lhs, const auto &rhs) {
       return make_pair(lhs.y, lhs.x) < make_pair(rhs.y, rhs.x); 
    });
    rep(i, N - 1) {
        edges.push_back({P[i].idx, P[i+1].idx, P[i+1].y - P[i].y});
    }
    sort(all(edges));
   
    DisjointSet djs(N);
    ll ans = 0;
    for(auto &e : edges) {
        if(djs.find(e.u) == djs.find(e.v)) continue;
        ans += e.d;
        djs.merge(e.u, e.v);
    }
    
    cout << ans << "\n";
}