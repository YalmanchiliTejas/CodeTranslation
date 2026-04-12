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
    lint N, X, M;
    cin >> N >> X >> M;

    vector<lint> A(1000000);
    A[1] = X;

    map<lint, lint> mp;
    mp[A[1]] = 1;

    int start = -1, end = -1;
    int len;
    for (int i = 2; i < 1000000; i++) {
        A[i] = ((A[i - 1] % M) * (A[i - 1] % M)) % M;
        if (mp.count(A[i]) == 0) {
            mp[A[i]] = i;
        } else {
            start = mp[A[i]];
            end   = i;
        }
    }
    len = end - start;

    lint cycle_sum = 0;
    for (int i = start; i < end; i++) {
        cycle_sum += A[i];
    }

    N++;
    lint ans = 0;
    if (N < start) {
        for (int i = 0; i <= N; i++) {
            ans += A[i];
        }
    } else {
        for (int i = 0; i < start; i++) {
            ans += A[i];
        }
        N -= start;

        lint k = N / (end - start);
        lint r = N % (end - start);

        ans += cycle_sum * k;

        for (int i = start; i < start + r; i++) {
            ans += A[i];
        }
    }

    cout << ans << endl;

    return 0;
}