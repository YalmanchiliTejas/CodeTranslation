#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using pii=pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(c) begin(c),end(c)
#define rall(c) rbegin(c),rend(c)
#define fore(x,c) for(auto &&x:c)
#define rep(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define rrep(i, a, n) for(int i=(int)(n-1);i>=a;--i)
#define sz(c) ((int)c.size())
#define contains(c,x) (c.find(x)!=end(c))
#define inseg(l,x,r) ((l)<=(x)&&(x)<(r))
#define dump(...)
#define pb push_back
#define _ 0
const signed INF_=1001001001; const long long INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    for (auto i = begin(v); i != end(v); i++) os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    for (auto i = begin(v); i != end(v); i++) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T, class U> bool chmax(T &a,const U &b){return a<b?a=b,1:0;}
template<class T, class U> bool chmin(T &a,const U &b){return a>b?a=b,1:0;}
template <class T> void psum(T& c) {partial_sum(begin(c), end(c), begin(c));}
template<class T> using heap=priority_queue<T,vector<T>,greater<T>>;
struct before_main_function {
    before_main_function() {
        cin.tie(0); ios::sync_with_stdio(0);
        cout << setprecision(15) << fixed;
        // #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

struct UnionFind {
    vector<int> data;
    int comp;
    UnionFind(int size) : data(size, -1), comp(size) {}
    void unite(int x, int y) {
        x = root(x); y = root(y);
        if(x != y) {
            if(data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
            comp--;
        }
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : (data[x] = root(data[x]));
    }
    int size(int x) {
        return -data[root(x)];
    }
    int components() { return comp; }
};

signed main() {
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> edge(M);
    rep(i, 0, M) {
        int vs, vt, cost;
        cin >> vs >> vt >> cost;
        vs--, vt--;
        edge[i] = make_tuple(cost, vs, vt);
    }
    sort(all(edge));
    
    vector<vector<pii>> T(N);
    UnionFind uf(N);
    int MST_cost = 0;
    rep(i, 0, M) {
        int cost, vs, vt;
        tie(cost, vs, vt) = edge[i];
        if (!uf.same(vs, vt)) {
            uf.unite(vs, vt);
            T[vs].pb({vt, cost});
            T[vt].pb({vs, cost});
            MST_cost += cost;
        }
    }
    vector<vector<int>> max_edge(N, vector<int>(N, 0));
    int start = 0;
    auto dfs = [&](auto f, int ver, int par, int mx) -> void {
        max_edge[start][ver] = mx;
        for (pii ed : T[ver]) {
            int w, cost;
            tie(w, cost) = ed;
            if (w == par) continue;
            f(f, w, ver, max(mx, cost));
        }
    };
    rep(s, 0, N) {
        start = s;
        dfs(dfs, s, -1, 0);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int S, T;
        cin >> S >> T;
        S--, T--;
        dump(max_edge[S][T]);
        cout << MST_cost - max_edge[S][T] << endl;
    }
    return (0^_^0);
}

