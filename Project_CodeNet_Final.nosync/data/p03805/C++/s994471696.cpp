#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 8;
bool e[N][N];
int n, m, f, t, ans;
int a[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> f >> t;
        e[f - 1][t - 1] = true;
        e[t - 1][f - 1] = true;
    }
    iota(a, a + n, 0);
    do {
        bool ok = true;
        for (int i = 0; i < n - 1; ++i) {
            if (!e[a[i]][a[i + 1]]) {
                ok = false;
                break;
            }
        }
        if (ok)
            ++ans;
    } while (next_permutation(a + 1, a + n));

    cout << ans << endl;
    return 0;
}
