#include <iostream>
#include <cstdio>
#include <map>
#define S second

using namespace std;

typedef long long ll;

ll n;
ll a[100005];
map<ll, ll> ma;

bool f(ll p)
{
    ma.clear();
    ma[-1] = p;
    for(ll i = 0; i < n; i++)
    {
        auto t = ma.lower_bound(a[i]);
        if(t == ma.begin())
        {
            return false;
        }
        t--;
        (t->S)--;
        if((t->S) == 0) ma.erase(t);
        ma[a[i]]++;
    }
    return true;
}

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    ll lt = 1, rt = n, mid, ans;
    while(lt <= rt)
    {
        mid = (lt + rt) / 2;
        if(f(mid)) ans = mid, rt = mid - 1;
        else lt = mid + 1;
    }
    cout<<ans<<endl;
    return 0;
}
