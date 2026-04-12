#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;
ll a;
vector<ll> ve;

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a);
        ll t = upper_bound(ve.begin(), ve.end(), a, greater<ll>()) - ve.begin();
        if(ve.size() <= t) ve.push_back(a);
        else ve[t] = a;
    }
    cout<<ve.size()<<endl;
    return 0;
}
