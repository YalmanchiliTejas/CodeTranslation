#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, k, n) for (int i = k; i < n; ++i)
#define fore(i,a) for (auto &i : a)
#define repr(i, n) for (int i = n; i >= 0; --i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int mod = 1000000000 + 7;
const static int inf = INT_MAX / 2;
const static llong INF = LLONG_MAX / 2;
const static double eps = 1e-10;
const static int dx[] = {1, 0, -1, 0};
const static int dy[] = {0, 1, 0, -1};

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> H(n);
    rep(i, n) cin >> H[i];

    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        bool ok = true;
        for (int j = i - 1; j >= 0; --j) {
            if (H[i] < H[j]) {
                ok = false;
                break;
            }
        }
        if (ok) ++ans;
    }

    cout << ans << endl;

    return 0;
}