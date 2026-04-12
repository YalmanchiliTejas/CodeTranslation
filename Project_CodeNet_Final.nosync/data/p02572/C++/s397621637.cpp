#include<bits/stdc++.h>
#define MSET(x,y) memset(x,y,sizeof(x))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 100005
#define ll long long
#define ld long double
#define INF 1e18
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;


int main()
{
    ll MOD = 1000000007;

    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n), sum(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (i != 0) sum[i] = sum[i - 1] + a[i];
        else sum[i] = a[i];
    }

    for (ll i = 0; i < n - 1; i++) {
        ans = (ans + ((sum[n - 1] - sum[i]) % MOD) * a[i] % MOD) % MOD;
    }

    cout << ans << endl;
    return 0;
}