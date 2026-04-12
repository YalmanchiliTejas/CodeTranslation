#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n;
ll a[55];
ll cnt;

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    while(1)
    {
        ll mx = -1, mi = 0;
        for(ll i = 0; i < n; i++)
        {
            if(a[i] >= mx) mx = a[i], mi = i;
        }
        ll t = a[mi] / n;
        if(t == 0) break;
        a[mi] %= n;
        for(ll i = 0; i < n; i++)
        {
            if(i == mi) continue;
            a[i] += t;
        }
        cnt += t;
    }
    cout<<cnt<<endl;
    return 0;
}
