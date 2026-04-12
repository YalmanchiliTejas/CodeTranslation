#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define TEST(...)                                                              \
    { printf("! "), printf(__VA_ARGS__); }
#else
#define TEST(...)
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
  public:
    i64 d[maxn], a[maxn], c[maxn][2];
    void solve() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = n - 1; i >= 1; i -= 2) {
            c[i][0] = max(c[i + 2][0], c[i + 2][1]) + a[i];
            c[i][1] = c[i + 2][1] + a[i + 1];
        }
        if (n % 2 == 0) {
            cout << max(c[1][0], c[1][1]) << '\n';
            return;
        }
        d[n - 2] = max(a[n - 2], max(a[n - 1], a[n]));
        for (int i = n - 4; i >= 1; i -= 2) {
            d[i] = d[i + 2] + a[i];
            d[i] = max(d[i], c[i + 1][1]);
            d[i] = max(d[i], c[i + 1][0]);
        }
        cout << d[1] << '\n';
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}