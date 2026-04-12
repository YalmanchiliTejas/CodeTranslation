#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll ans;

main()
{
    ll al, n, k;

    cin >> n >> k;

    al = n * n;

    for (ll i = 1; i <= n; i++)
    {
        ll cur = 0, l = i, r = n / i;

        cur += max(0ll, r * (i - k));

        if (n != i * r && (r * i) + k <= n){
            cur += (n - ((r * i) + k) + 1);
            if (k == 0)
                cur--;
        }


        ans += cur;
    }

    cout << ans;
}


