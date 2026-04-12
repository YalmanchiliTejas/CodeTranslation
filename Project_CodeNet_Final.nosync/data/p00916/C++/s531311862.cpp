#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 110;

typedef struct UnionFindTree{
    vector<int> par;

    UnionFindTree(int n){
        par.resize(n, -1);
    }

    bool is_root(int x){
        return par[x]<0;
    }

    int find(int x){
        if(is_root(x)) return x;
        return par[x] = find(par[x]);
    }

    int size(int x){
        return -par[find(x)];
    }

    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(size(x) < size(y)) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
}UF;

int n;
int l[55], t[55], r[55], b[55];
vector<int> vx, vy;

int x_id(int x){
    return lower_bound(vx.begin(), vx.end(), x) - vx.begin();
}

int y_id(int y){
    return lower_bound(vy.begin(), vy.end(), y) - vy.begin();
}

void solve(){
    vx.clear();
    vy.clear();

    rep(i, n){
        scanf("%d%d%d%d", &l[i], &t[i], &r[i], &b[i]);
        vx.push_back(l[i]); vx.push_back(r[i]);
        vy.push_back(t[i]); vy.push_back(b[i]);
    }
    vx.push_back(-1); vx.push_back(mod);
    vy.push_back(-1); vy.push_back(mod);
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());

    int h = vx.size(), w = vy.size();
    lint color[h][w];
    rep(i, h)rep(j, w) color[i][j] = 0;
    rep(i, n){
        color[x_id(l[i])][y_id(b[i])] ^= (1LL << i);
        color[x_id(l[i])][y_id(t[i])] ^= (1LL << i);
        color[x_id(r[i])][y_id(b[i])] ^= (1LL << i);
        color[x_id(r[i])][y_id(t[i])] ^= (1LL << i);
    }
    rep(i, h)rep(j, w - 1) color[i][j + 1] ^= color[i][j];
    rep(j, w)rep(i, h - 1) color[i + 1][j] ^= color[i][j];

    UF uf(h * w);
    int ans = h * w;
    rep(x, h)rep(y, w){
        if(x + 1 < h && color[x][y] == color[x + 1][y]){
            ans -= uf.unite(x * w + y, (x + 1) * w + y);
        }
        if(y + 1 < w && color[x][y] == color[x][y + 1]){
            ans -= uf.unite(x * w + y, x * w + y + 1);
        }
    }
    printf("%d\n", ans);
}

int main(){
    while(scanf("%d", &n) && n){
        solve();
    }
}
