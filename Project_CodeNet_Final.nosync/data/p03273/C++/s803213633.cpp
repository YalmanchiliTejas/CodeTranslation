#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    vector<bool> tate(w, false), yoko(h, false);

    rep(i, w) {
        bool f = true;

        rep(j, h) if (a[j][i] == '#') f = false;

        tate[i] = f;
    }

    rep(i, h) {
        bool f = true;

        rep(j, w) if (a[i][j] == '#') f = false;

        yoko[i] = f;
    }

    vector<string> res;

    rep(i, h) {
        if (yoko[i]) continue;
        string p = "";
        rep(j, w) {
            if (tate[j]) continue;
            p += a[i][j];
        }
        res.push_back(p);
    }
    
    rep(i, res.size()) cout << res[i] << endl;
    return 0;
}