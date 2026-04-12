#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rnd;
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define go_precise cout << fixed << setprecision(18);

const int maxn = 3e3 + 10;
ll dp[maxn][maxn];
ll pref[maxn];
ll a[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) pref[i] = pref[i-1] + a[i];

    for (int i=1; i<=n; i++) dp[i][i] = a[i];
    for (int len=2; len<=n; len++) {
        for (int l=1; l+len-1<=n; l++) {
            int r = l+len-1;
            dp[l][r] = max(a[l] + pref[r] - pref[l] - dp[l+1][r], a[r] + pref[r-1] - pref[l-1] - dp[l][r-1]);
        }
    }
    cout << 2 * dp[1][n] - pref[n];

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL
    return 0;
}
