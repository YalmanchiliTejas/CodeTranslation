#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

class UnionFind {
    int n;
    vector<int> uni;
public:
    explicit UnionFind(int n) : uni(static_cast<u32>(n), -1) , n(n){};

    int root(int a){
        if (uni[a] < 0) return a;
        else return (uni[a] = root(uni[a]));
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        uni[a] += uni[b];
        uni[b] = a;
        return true;
    }

    int size(int i){ return -uni[root(i)]; }
    bool same(int a, int b) { return root(a) == root(b); }
};

int main() {
    int n;
    while(cin >> n, n){
        vector<int> zx = {-MOD, MOD}, zy = {-MOD, MOD};
        vector<vector<int>> v;
        for (int i = 0; i < n; ++i) {
            int a, b, c, d;
            cin >> a >> d >> c >> b;
            zx.emplace_back(a); zx.emplace_back(c-1); zx.emplace_back(c);
            zy.emplace_back(b); zy.emplace_back(d-1); zy.emplace_back(d);
            v.emplace_back(vector<int>{b, a, d, c});
        }
        sort(zx.begin(), zx.end());
        zx.erase(unique(zx.begin(), zx.end()), zx.end());
        sort(zy.begin(), zy.end());
        zy.erase(unique(zy.begin(), zy.end()), zy.end());
        int h = zy.size(), w = zx.size();
        vector<vector<ll>> grid(h+2, vector<ll>(w+2, 0));
        auto fy = [&zy](int y){ return lower_bound(zy.begin(),zy.end(), y)-zy.begin(); };
        auto fx = [&zx](int x){ return lower_bound(zx.begin(),zx.end(), x) - zx.begin(); };
        for (int i = 0; i < n; ++i) {
            int y1 = fy(v[i][0])+1, x1 = fx(v[i][1])+1, y2 = fy(v[i][2])+1, x2 = fx(v[i][3])+1;
            grid[y1][x1] += 1LL<<i; grid[y1][x2] -= 1LL<<i; grid[y2][x1] -= 1LL<<i; grid[y2][x2] += 1LL<<i;
        }
        for (int i = 1; i < h+2; ++i) {
            for (int j = 0; j < w+2; ++j) {
                grid[i][j] += grid[i-1][j];
            }
        }
        for (int i = 0; i < h + 2; ++i) {
            for (int j = 1; j < w+2; ++j) {
                grid[i][j] += grid[i][j-1];
            }
        }


        int Y = grid.size(), X = grid[0].size();
        UnionFind uf(X*Y);
        for (int i = 0; i < Y; ++i) {
            for (int j = 0; j < X; ++j) {
                if(i && grid[i][j] == grid[i-1][j]) uf.unite(i*X+j, (i-1)*X+j);
                if(j && grid[i][j] == grid[i][j-1]) uf.unite(i*X+j, i*X+j-1);
            }
        }
        vector<int> ans;
        for (int i = 0; i < Y; ++i) {
            for (int j = 0; j < X; ++j) {
                ans.emplace_back(uf.root(i*X+j));
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        cout << ans.size() << "\n";
    }
    return 0;
}
