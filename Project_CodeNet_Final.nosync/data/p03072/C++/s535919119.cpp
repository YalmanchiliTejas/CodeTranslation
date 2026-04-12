#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define each(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(v) v.begin(), v.end()
#define mset(a, n) memset(a, n, sizeof(a))

typedef long long ll;

const int INF = 1000000000;
const int MOD = 1000000007;

int main(int argc, char *argv[]) {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0, max_h = 0;
    rep(i, n) {
        int h; cin >> h;
        if (max_h <= h) max_h = h, ans++;
    }
    cout << ans << endl;
    return 0;
}