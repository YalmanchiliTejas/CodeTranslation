#include <bits/stdc++.h>
using namespace std;

using lint = long long;
template <typename T> using V = vector<T>;
template <typename T> using VV = vector<vector<T>>;
template <typename T> using VVV = vector<vector<vector<T>>>;
#define rep(i, n) for(int i = 0; i < int(n); i++)
#define repu(i, a, b, s) for(int i = int(a); i < int(b); i += int(s))
#define repd(i, a, b, s) for(int i = int(a); i > int(b); i += int(s))
#define endl "\n"
constexpr lint INF = 2e18;
constexpr lint MOD = 1e9 + 7;

void solve() {
    int H, W;
    cin >> H >> W;

    V<string> grid(H);
    rep(i, H) {
        string t;
        cin >> t;
        grid[i] = t;
    }

    lint ah = H, aw = W;
    VV<bool> flag(H, V<bool>(W, false));
    rep(y, H) {

        bool f = true;
        rep(x, W) {
            if(grid[y][x] == '#') {
                f = false;
            }
        }
        if(f) {
            ah--;
            rep(x, W) { flag[y][x] = true; }
        }
    }

    rep(x, W) {

        bool f = true;
        rep(y, H) {
            if(grid[y][x] == '#') {
                f = false;
            }
        }
        if(f) {
            aw--;
            rep(y, H) { flag[y][x] = true; }
        }
    }

    V<string> ans(ah);

    lint i = 0;
    rep(y, H) {
        string t = "";
        rep(x, W) {
            if(not flag[y][x]) {
                t += grid[y][x];
            }
        }
        if(t != "") {
            ans[i] = t;
            i++;
        }
    }

    rep(y, ah) { cout << ans[y] << endl; }
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}