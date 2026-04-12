#include <bits/stdc++.h>
#define DEBUG(x) cout << #x << " = " << x << endl
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;


const int MAXN = 200005;

pair <ll, ll> a[MAXN];

int main()
{
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    ll minr = 1e10;
    ll maxr = -1;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[i].ff = min(x, y);
        a[i].ss = max(x, y);
        maxr = max(a[i].ss, maxr);
        minr = min(a[i].ss, minr);
    }

    sort(a, a + n);

    ll ans = ( maxr - minr ) * ( a[n-1].ff - a[0].ff );

    ll r = a[n-1].ff;
    for (int i = 1; i < n; i++)
    {
        r = max(r, a[i-1].ss);
        ans = min(ans, ( maxr - a[0].ff ) * ( r - min(minr, a[i].ff) ));
        if (a[i].ff >= minr) break;
    }

    cout << ans;

    return 0;
}

