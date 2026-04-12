#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second

using namespace std;
const int N = 51 , mod = 1e9 + 7;

ll tot[N] , p[N];

ll ans(int n , ll x)
{
    if (n == 0)
        return 1;
    if (x == 1)
        return 0;
    if (x <= tot[n]/2)
        return ans(n-1 , x-1);
    if (x == tot[n]/2 + 1)
        return 1 + ans(n-1 , x-2);
    return p[n-1] + 1 + ans(n-1 , x - tot[n-1] - 2);
}

int main()
{
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n , x; cin >> n >> x;
    p[0] = 1 , tot[0] = 1;
    for (int i=1; i<N; i++)
        tot[i] = 2 * tot[i-1] + 3 , p[i] = 2 * p[i-1] + 1;
    cout << ans(n , x);
}
