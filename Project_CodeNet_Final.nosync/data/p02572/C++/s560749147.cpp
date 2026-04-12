//Ace
#include <bits/stdc++.h>
using namespace std;
using in = long long;
using str = string;
using pi = pair<in, in>;
using vi = vector<in>;
#define F first
#define S second
#define pb push_back
#define rep(i, k, n) for (in i = k; i < n; ++i)
#define repr(i, k, n) for (in i = k; i >= n; --i)
#define sz(x) (in) x.size()
#define all(x) begin(x), end(x)
const in MOD = 1e9 + 7;
const in N = 1e5 + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    in n;
    cin >> n;
    in a[n];
    in sum = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        sum = (sum + a[i]) % MOD;
    }

    in ans = 0;
    rep(i, 0, n)
    {
        sum = (sum - a[i] + MOD) % MOD;
        ans = (ans + (a[i] * (sum)) % MOD) % MOD;
    }
    cout << ans;

    return 0;
}