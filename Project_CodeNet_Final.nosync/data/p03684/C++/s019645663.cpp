#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using VI = vector<int>;
using VL = vector<ll>;
using loop = int;
template<class T> using PQ = priority_queue<T, vector<T>, greater<T>>;
#define FOR(i,a,n) for(loop (i)=(a);(i)<(n);++(i))
#define eFOR(i,a,n) for(loop (i)=(a);(i)<=(n);++(i))
#define rFOR(i,a,n) for(loop (i)=(n)-1;(i)>=(a);--(i))
#define erFOR(i,a,n) for(loop (i)=(n);(i)>=(a);--(i))
#define each(i, a) for(auto &i : a)
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i,a) sort((i).begin(),(i).end(),(a))
#define all(i) (i).begin(),(i).end()
#define out(y,x) ((y) < 0 || h <= (y) || (x) < 0 || w <= (x))
#define line cout << "------------------------\n" 
#define ENDL(i,n) ((i) == (n) - 1 ? "\n" : " ")
#define stop system("pause") //comment out this on AOJ.
constexpr ll INF = 1000000000;
constexpr ll LLINF = 1LL << 60;
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
constexpr ld eps = 1e-10;
constexpr ld pi = 3.1415926535897932;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
inline void init() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }
template<class T>inline istream& operator>>(istream& is, vector<T>& v) { for (auto& elemnt : v)is >> elemnt; return is; }
template<class T, class U>inline istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template<class T>inline vector<T> vec(size_t a) { return vector<T>(a); }
template<class T>inline vector<T> defvec(T def, size_t a) { return vector<T>(a, def); }
template<class T, class... Ts>inline auto vec(size_t a, Ts... ts) { return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...)); }
template<class T, class... Ts>inline auto defvec(T def, size_t a, Ts... ts) { return vector<decltype(defvec<T>(def, ts...))>(a, defvec<T>(def, ts...)); }

class unionfind {
    VI par, rank;
    int forest_num;
public:
    unionfind(int n) : par(n), rank(n, 1), forest_num(n) {
        FOR(i, 0, n)par[i] = i;
    }
    int root(int x) {
        if (par[x] == x)return x;
        return par[x] = root(par[x]);
    }
    int size(int x) {
        if (par[x] == x)return rank[x];
        return size(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry)return;
        if (rank[rx] < rank[ry]) {
            par[rx] = ry;
            rank[ry] += rank[rx];
        }
        else {
            par[ry] = rx;
            rank[rx] += rank[ry];
        }
        --forest_num;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int fnum() { return forest_num; }
};

int main() {
    init();

    int n; cin >> n;
    vector<tuple<ll, ll, int>> xy;
    FOR(i, 0, n) {
        ll x, y; cin >> x >> y;
        xy.emplace_back(x, y, i);
    }

    vector<tuple<ll, int, int>> edge;
    SORT(xy);
    FOR(i, 1, n) {
        ll ax, ay; int a; tie(ax, ay, a) = xy[i - 1];
        ll bx, by; int b; tie(bx, by, b) = xy[i];
        edge.emplace_back(min(abs(ax - bx), abs(ay - by)), a, b);
    }
    each(i, xy)swap(get<0>(i), get<1>(i));
    SORT(xy);
    FOR(i, 1, n) {
        ll ax, ay; int a; tie(ax, ay, a) = xy[i - 1];
        ll bx, by; int b; tie(bx, by, b) = xy[i];
        edge.emplace_back(min(abs(ax - bx), abs(ay - by)), a, b);
    }

    ll ans = 0;
    unionfind uf(n);
    SORT(edge);
    each(i, edge) {
        ll cost; int a, b; tie(cost, a, b) = i;
        if (uf.same(a, b))continue;
        uf.unite(a, b);
        ans += cost;
    }

    cout << ans << "\n";
}
