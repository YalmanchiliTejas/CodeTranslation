#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H,W; cin >> H >> W;
    vector<string> grid(H);
    rep(i,H) cin >> grid[i];

    int cnt = 0;
    rep(i,H)rep(j,W) {
        if (grid[i][j] == '#') ++cnt;
    }
    cout << (cnt == H + W - 1 ? "Possible" : "Impossible") << '\n';
    return 0;
}