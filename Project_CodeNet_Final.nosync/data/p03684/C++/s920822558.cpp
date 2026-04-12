#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define F first
#define S second

using namespace std;

typedef long long ll;

ll n, ans;
pair<ll, ll> a[100005], b[100005];
ll cp[100005];
vector<pair<ll, pair<ll, ll> > > ve;

ll fnd(ll p)
{
    if(cp[p] == p) return p;
    return cp[p] = fnd(cp[p]);
}

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld%lld", &a[i].F, &b[i].F);
        cp[i] = i;
        a[i].S = b[i].S = i;
    }
    sort(a, a + n);
    sort(b, b + n);
    for(ll i = 0; i < n - 1; i++)
    {
        ve.push_back(make_pair(a[i + 1].F - a[i].F, make_pair(a[i].S, a[i + 1].S)));
        ve.push_back(make_pair(b[i + 1].F - b[i].F, make_pair(b[i].S, b[i + 1].S)));
    }
    sort(ve.begin(), ve.end());
    for(ll i = 0; i < ve.size(); i++)
    {
        if(fnd(ve[i].S.F) != fnd(ve[i].S.S))
        {
            cp[fnd(ve[i].S.F)] = fnd(ve[i].S.S);
            ans += ve[i].F;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
