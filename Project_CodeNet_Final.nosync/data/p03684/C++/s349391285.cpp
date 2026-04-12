// 基本テンプレート

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

int N;
vector<pii> vx, vy;

struct Elem {
    int u, v, cost;
};

bool operator<(const Elem &a, const Elem &b) {
    return a.cost > b.cost;
}

// Union-Find 木 (Verified: AtCoder Typical Contest 001 B)
struct UnionFind {
private:
    const int n;
    int __size;
    vector<int> uf;
public:
    // 初期化 UnionFind uni(n) のように宣言すれば良い
    UnionFind(int _n) : n(_n), __size(_n), uf(_n, -1) {}
    // find (木の根を求める)
    int find(int x) {return (uf[x] < 0) ? x : uf[x] = find(uf[x]);}
    // x と y が同じ集合に属するかどうか
    bool same(int x, int y) {return find(x) == find(y);}
    // x が属する集合の要素数
    int size(int x) {return -uf[find(x)];}
    // 集合はいくつあるか
    int size()      {return __size;}
    // x と y の属する集合を併合
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        __size--;
        if(uf[y] < uf[x]) swap(x, y);
        uf[x] += uf[y]; uf[y] = x;
    }
};

signed main() {
    cin >> N;
    rep(i,0,N) {
        int x, y; cin >> x >> y;
        vx.push_back(pii(x, i));
        vy.push_back(pii(y, i));
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    priority_queue<Elem> q;
    UnionFind uf(N);
    rep(i,0,N-1) {
        int u = vx[i].second, v = vx[i+1].second, c1 = abs(vx[i].first - vx[i+1].first);
        int z = vy[i].second, w = vy[i+1].second, c2 = abs(vy[i].first - vy[i+1].first);

        q.push(Elem{u, v, c1});
        q.push(Elem{z, w, c2});
    }

    int ans = 0;
    while(!q.empty()) {
        Elem t = q.top(); q.pop();
        if(uf.same(t.u, t.v)) continue;
        ans += t.cost;
        uf.unite(t.u, t.v);
    }
    cout << ans << endl;
    return 0;
}