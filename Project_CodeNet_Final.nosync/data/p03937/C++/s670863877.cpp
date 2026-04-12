#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep3(i, l, n) for (int i = l; i < n; ++i)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = (a >= b ? a : b)
#define chmin(a, b) a = (a <= b ? a : b)
#define out(a) cout << a << endl
#define outa(a, n) { rep(_, n) cout << a[_] << " "; cout << endl; }
#define outp(a, n) { cout << endl; rep(_, n) cout << a[_].F << " " << a[_].S << endl; }
#define SZ(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
#define FIX(a) fixed << setprecision(a)
#define LB(v, n) (int)(lower_bound(all(v), n) - v.begin())
#define UB(v, n) (int)(upper_bound(all(v), n) - v.begin())

// 全マスを踏んだか
// 最短経路ではないからbfsではないか
// dfsでいけそう

int main() {
    // 左下にあったらアウトでは？
    int h, w;
    cin >> h >> w;
    char c[h][w];
    rep(i, h) rep(j, w) cin >> c[i][j];
    rep(i, h - 1) rep3(j, 1, w) {
        if (c[i][j] == '#' && c[i + 1][j - 1] == '#') { out("Impossible"); return 0; }
    }
    out("Possible");
    
    // 下、右が可能
    // 下で上は意味ない
    // 下で左
    // 左下#発生
    // 右で上
    // 左下#発生
}
