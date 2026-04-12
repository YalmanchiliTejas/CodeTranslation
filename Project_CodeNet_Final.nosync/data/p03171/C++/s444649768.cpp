#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pll;

#define pb push_back
#define mp make_pair
#define all(_c) _c.begin(), _c.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector <ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector <vector <vector <ll> > > dp(
        n, vector <vector <ll> > (
            n, vector <ll> (
                2
            )
        )
    );

    for (int len = 1; len <= n; len++)
        for (int l = 0, r = len - 1; r < n; l++, r++)
            for (int t = 0; t < 2; t++) {
                ll s = (t ? -1 : 1);
                if (l == r)
                    dp[l][r][t] = a[l]*s;
                else {
                    ll v1 = dp[l][r - 1][!t] + s*a[r];
                    ll v2 = dp[l + 1][r][!t] + s*a[l];
                    dp[l][r][t] = s*max(s*v1, s*v2);
                }
            }
    
    cout << dp[0][n - 1][0] << '\n';
    return 0;
}
