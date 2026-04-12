#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;

ll a[3005], dp[3005][3005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r; l + len - 1 <= n; l++) {
            r = l + len - 1;
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    cout << dp[1][n] << endl;
	return 0;
}
