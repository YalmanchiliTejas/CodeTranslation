#include <bits/stdc++.h>
using namespace std;
#define rep2(i,m,n) for (int i = (m); i < (n); ++i)
#define rep(i,n) rep2(i,0,n)
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> P;
template<typename T> struct V : vector<T> { using vector<T>::vector; };
V() -> V<int>;
V(size_t) -> V<int>;
template<typename T> V(size_t, T) -> V<T>;
template<typename T> vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template<typename... Ts> auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << ' '; return os; }
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int INF = 1<<30;
const ll LINF = 1LL<<61;

int n, m;
vector<vector<int>> G;

int func(int cur, int used)
{
    if(used == (1 << n) - 1)
    {
        return 1;
    }
    int ret = 0;
    for(auto to:G[cur])
    {
        if((used & (1 << to))) continue;
        ret += func(to, used | (1 << to));
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    G.assign(n, vector<int>(0));
    rep(i,m)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    cout << func(0, 1) << endl;

    return 0;
}