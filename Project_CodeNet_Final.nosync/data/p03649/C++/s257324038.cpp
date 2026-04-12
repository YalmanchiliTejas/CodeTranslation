#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n;
ll a[55];
ll ans2 = 4e18;

ll f(ll p)
{
    ll cnt = 0;
    for(ll i = 0; i < n; i++)
    {
        cnt += (a[i] + p - (n - 1) + n) / (n + 1);
    }
    return cnt <= p;
}

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for(ll i = 0; i < n; i++)
    {
        ll lt = 0, rt = 4e18, mid, ans;
        while(lt <= rt)
        {
            mid = (lt + rt) / 2;
            if(f(mid / n * n + i)) ans = mid / n * n + i, rt = mid - 1;
            else lt = mid + 1;
        }
        ans2 = min(ans2, ans);
    }
    cout<<ans2<<endl;
    return 0;
}
