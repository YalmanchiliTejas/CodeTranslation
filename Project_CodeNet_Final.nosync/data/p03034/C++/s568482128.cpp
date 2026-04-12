#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    vi t(N, -1);

    ll ans = 0;
    for (int amb = 1; amb <= (N - 1); amb++) {
        ll cand = s[0] + s[N-1];
        for (int km1 = 1; km1 * amb < N - 1; km1++) {
            int A = N - 1 - km1 * amb;
            int B = A - amb;
            int K = km1 + 1;

            if (B <= 0) break;

            bool fail = false;
            for (int u : { km1 * amb, A }) {
                if (t[u] == amb) {
                    fail = true;
                    break;
                } else {
                    cand += s[u];
                    t[u] = amb;
                }
            }
            if (fail) break;

            ans = max(ans, cand);
        }
    }
    cout << ans << endl;

    return 0;
}

