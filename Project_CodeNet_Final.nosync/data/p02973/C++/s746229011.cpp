#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll a[100010], dp[100010];

int main(){
    int n;
    cin >> n;
    rrep(i, n) cin >> a[i];
    fill(dp, dp+n, LINF);

    rep(i, n){
        *upper_bound(dp, dp+n, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp+n, LINF) - dp << endl;

    return 0;
}
