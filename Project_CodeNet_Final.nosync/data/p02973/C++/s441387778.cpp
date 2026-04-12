#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;
const ll MOD=1e9+7;
const ll MOD1=13;
ll n,a[MAXN];
multiset<ll,greater<ll> >s;
void solve()
{
    for(ll i=1;i<=n;i++)
    {
        auto it=s.upper_bound(a[i]);
        if(it!=s.end())
        {
            s.erase(it);
        }
        s.insert(a[i]);
    }
    printf("%d\n",s.size());
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    solve();
}
