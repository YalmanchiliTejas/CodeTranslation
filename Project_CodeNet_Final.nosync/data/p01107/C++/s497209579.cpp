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
constexpr int MAX = 200010;

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

    void clear(){
        fill(par.begin(), par.end(), -1);
    }
}UF;

int h, w;

void solve(){
    char c[h][w];
    rep(i, h)rep(j, w) scanf(" %c", &c[i][j]);
    pii p[4] = {{0, 0}, {0, w - 1}, {h - 1, 0}, {h - 1, w - 1}};
    UF uf(h * w);
    rep(x, h)rep(y, w)if(c[x][y] == '.'){
        if(x + 1 < h && c[x + 1][y] == '.'){
            uf.unite(x * w + y, (x + 1) * w + y);
        }
        if(y + 1 < w && c[x][y + 1] == '.'){
            uf.unite(x * w + y, x * w + y + 1);
        }
    }
    rep(k, 4)rep(l, 4){
        if(!uf.same(p[k].fi * w + p[k].se, p[l].fi * w + p[l].se)){
            puts("NO");
            return;
        }
    }

    rep(i, h)rep(j, w)if(c[i][j] == '.'){
        bool flag = true;
        rep(k, 4)if(i == p[k].fi && j == p[k].se){
            flag = false;
            break;
        }
        if(!flag) continue;
        c[i][j] = '#';
        uf.clear();
        rep(x, h)rep(y, w)if(c[x][y] == '.'){
            if(x + 1 < h && c[x + 1][y] == '.'){
                uf.unite(x * w + y, (x + 1) * w + y);
            }
            if(y + 1 < w && c[x][y + 1] == '.'){
                uf.unite(x * w + y, x * w + y + 1);
            }
        }
        rep(k, 4)rep(l, 4){
            if(!uf.same(p[k].fi * w + p[k].se, p[l].fi * w + p[l].se)){
                puts("NO");
                return;
            }
        }
        c[i][j] = '.';
    }
    puts("YES");
}

int main(){
    while(scanf("%d%d", &h, &w) && h){
        solve();
    }
}
