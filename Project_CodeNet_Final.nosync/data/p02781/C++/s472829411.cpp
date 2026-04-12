#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const double EPS = 1e-10;

int main() {
    string X;
    lint N, K;
    cin >> X >> K;
    N = X.size();

    vector<vector<vector<lint>>> cnt(
        N + 1, vector<vector<lint>>(2, vector<lint>(5, 0)));
    cnt[0][false][0] = 1;

    rep(i, N) rep(le, 2) rep(k, 5) {
        int a = int(X[i] - '0');
        for (int x = 0; x <= (le ? 9 : a); x++) {
            cnt[i + 1][le || (x < a)][min(4, k + (x != 0 ? 1 : 0))] +=
                cnt[i][le][k];
        }
    }

    cout << cnt[N][0][K] + cnt[N][1][K] << endl;
    return 0;
}