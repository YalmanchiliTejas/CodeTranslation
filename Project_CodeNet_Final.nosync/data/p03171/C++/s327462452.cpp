#include <bits/stdc++.h>

#define filein freopen ("in.txt", "r", stdin)
#define fileout freopen ("out.txt", "w", stdout)
#define dbg(x) cerr << #x << ": " << x << endl

using namespace std;
typedef long long ll;

const int maxn = 3003;

ll a[maxn];
ll dp[maxn][maxn];
ll n;

ll go (ll L, ll R){
    if (L > R) return 0;
    ll &ret = dp[L][R];
    if (ret != -1) return ret;
    ret = max (a[L] - go (L + 1, R), a[R] - go (L, R - 1));
    return ret;
}

int main(){
    memset (dp, -1, sizeof dp);
    scanf ("%lld", &n);
    for (ll i = 0; i < n; i++)
        scanf ("%lld", &a[i]);
    cout << go (0, n - 1) << endl;
	return 0;
}
