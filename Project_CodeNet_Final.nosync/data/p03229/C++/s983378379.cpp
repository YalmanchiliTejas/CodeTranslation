#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
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
const lint MOD   = 1e9 + 7;
const double EPS = 1e-10;

int main() {
    int N;
    cin >> N;
    vector<lint> A(N, 0);
    rep(i, N) cin >> A[i];
    sort(A.rbegin(), A.rend());
    vector<pair<int, int>> x;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        if (i == 0)
            C[i] = pow(-1, (i + 1));
        else if (i == N - 1)
            C[i] = pow(-1, (i + 1));
        else
            C[i] = pow(-1, (i + 1)) * 2;
        x.push_back({C[i], i});
    }
    sort(x.rbegin(), x.rend());
    lint ans = 0;
    for (int i = 0; i < N; i++) {
        ans += x[i].first * A[i];
    }

    x.clear();
    for (int i = 0; i < N; i++) {
        if (i == 0)
            C[i] = pow(-1, (i));
        else if (i == N - 1)
            C[i] = pow(-1, (i));
        else
            C[i] = pow(-1, (i)) * 2;
        x.push_back({C[i], i});
    }
    sort(x.rbegin(), x.rend());

    lint ans2 = 0;
    for (int i = 0; i < N; i++) {
        ans2 += x[i].first * A[i];
    }
    cout << max(ans, ans2) << endl;
    return 0;
}