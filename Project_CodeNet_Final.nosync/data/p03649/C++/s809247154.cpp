#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    while(true)
    {
        bool update = false;
        for(int i = 0; i < n; i++)
        {
            if(a[i] >= n)
            {
                update = true;
                ll x = a[i] / n;
                a[i] %= n;
                ans += x;
                for(int j = 0; j < n; j++)
                {
                    if(j == i) continue;
                    a[j] += x;
                }
            }
        }
        if(!update)
        {
            break;
        }
    }
    cout << ans << endl;
}
