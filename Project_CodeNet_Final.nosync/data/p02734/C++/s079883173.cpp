#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define debug(...)                                                             \
    { cerr << "# " << __VA_ARGS__ << "\n"; }
#else
#define debug(...)
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
  public:
    i64 S[3333];
    void solve() {
        int n, s;
        cin >> n >> s;
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            if (s - t >= 0) {
                (ans += 1ll * (n - i) * S[s - t] % MOD) %= MOD;
                if (t == s)
                    (ans += 1ll * (n - i) * (i + 1) % MOD) % MOD;
                for (int j = s; j - t >= 0; --j) {
                    S[j] = (S[j] + S[j - t]) % MOD;
                }
                S[t] = (S[t] + i + 1) % MOD;
            }
        }
        cout << ans << '\n';
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}