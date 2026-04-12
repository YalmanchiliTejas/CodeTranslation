# include <bits/stdc++.h>

# define pb push_back
# define fr first
# define sc second
# define mk make_pair

using namespace std;

const int inf = 1000000000 + 7;
const int N = 2e5 + 5;

typedef long long ll;

int n, mn1 = inf, mn2 = inf, mx1, mx2;
ll ans = 2e18;
pair <int, int> a[N];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i].fr >> a[i].sc;
        if(a[i].fr > a[i].sc) swap(a[i].fr, a[i].sc);
        mn1 = min(a[i].fr, mn1);
        mn2 = min(a[i].sc, mn2);
        mx1 = max(a[i].fr, mx1);
        mx2 = max(a[i].sc, mx2);
    }

    ans = mx1 - mn1;
    ans *= (mx2 - mn2);

    sort(a + 1, a + n + 1);

    mx1 = mx2, mn2 = a[2].fr;

    ll l = 1e9, r = a[n].fr;
    for(int i = 1; i <= n; i ++)
    {
        l = min(l, a[i].sc * 1ll);
        r = max(r, a[i].sc * 1ll);
        ans = min(ans, (mx1 - mn1) * 1ll * (r - min(l, a[i + 1].fr * 1ll)));
    }
    cout << ans << endl;
}
