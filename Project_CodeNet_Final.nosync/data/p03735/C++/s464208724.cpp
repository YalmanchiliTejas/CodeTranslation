# include <bits/stdc++.h>

# define sc second
# define fr first

using namespace std;

long long n, rmax, bmax, bmin = 1e9, rmin = 1e9;;
long long ans = 1e18;
pair<long long, long long> ar[200001];

int main()
{
    cin >> n;
    for(long long i = 1; i <= n; i++)
    {
        cin >> ar[i].fr >> ar[i].sc;
        if(ar[i].fr > ar[i].sc) swap(ar[i].fr, ar[i].sc);
    }

    sort(ar + 1, ar + n + 1);

    for(long long i = 1; i <= n; i++)
        rmax = max(rmax, ar[i].fr), rmin = min(rmin, ar[i].fr), bmax = max(bmax, ar[i].sc), bmin = min(bmin, ar[i].sc);

    ans = (ar[n].fr - ar[1].fr) * (bmax - bmin);

    rmax = bmax, bmin = ar[2].fr;

    long long l = 1e9, r = ar[n].fr;

    for(long long i = 1; i < n; i++)
    {
        l = min(ar[i].sc, l);
        r = max(ar[i].sc, r);

        ans = min(ans, 1ll * (rmax - rmin) * (r - min(l, ar[i + 1].fr)));
    }

    cout << ans;
    return 0;
}


