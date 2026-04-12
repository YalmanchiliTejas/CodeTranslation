#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void solve() {
    ll N;
    cin >> N;
    Vl A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    ll ans = 0;

    Vl s(N);

    if (N & 1) {
        ll idx1 = 0, idx2 = N;
        for (ll i = 1; i < N - 1; i++) {
            if (i & 1) {
                s[i] = A[--idx2];
            }
            else {
                s[i] = A[idx1++];
            }
        }
        s[0] = A[idx1++];
        s[N - 1] = A[--idx2];
        ll t = 0;
        for (ll i = 1; i < N; i++) {
            t += abs(s[i] - s[i - 1]);
        }
        ans = max(ans, t);

        idx1 = 0, idx2 = N;
        for (ll i = 1; i < N - 1; i++) {
            if (!(i & 1)) {
                s[i] = A[--idx2];
            }
            else {
                s[i] = A[idx1++];
            }
        }
        s[0] = A[idx1++];
        s[N - 1] = A[--idx2];
        t = 0;
        for (ll i = 1; i < N; i++) {
            t += abs(s[i] - s[i - 1]);
        }
        ans = max(ans, t);
    }
    else {
        ll idx1 = 0, idx2 = N;
        for (ll i = 1; i < N - 1; i++) {
            if (i & 1) {
                s[i] = A[--idx2];
            }
            else {
                s[i] = A[idx1++];
            }
        }
        s[0] = A[idx1++];
        s[N - 1] = A[--idx2];
        ll t = 0;
        for (ll i = 1; i < N; i++) {
            t += abs(s[i] - s[i - 1]);
        }
        ans = max(ans, t);
    }

    cout << ans << "\n";
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    solve();
    cout << flush;
    return 0;
}