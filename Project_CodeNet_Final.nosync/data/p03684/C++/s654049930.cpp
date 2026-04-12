#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll rep[100001] , sz[100001];
ll find(ll u)
{
    return rep[u] == u ? u : rep[u] = find(rep[u]);
}
bool join(ll a , ll b)
{
    a = find(rep[a]) , b = find(rep[b]);
    if (a == b)
        return false;
    if (sz[a] < sz[b])
        swap(a , b);
    sz[a] += sz[b];
    rep[b] = a;
    return true;
}
int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
        rep[i] = i ,sz[i] = 1 ;
    vector <pair <ll , ll>> vx , vy;
    map <ll , vector <pair<ll , ll>>> mop;
    for (int i = 0; i < n; i++)
    {
        ll  a , b;
        cin>> a >> b;
        vx.push_back({a , i});
        vy.push_back({b , i});
    }
    sort(vx.begin() , vx.end());
    sort(vy.begin() , vy.end());
    for (int i = 1; i < n; i++)
        mop[vx[i].first - vx[i-1].first].push_back({vx[i].second , vx[i-1].second});
    for (int i = 1; i < n; i++)
        mop[vy[i].first - vy[i-1].first].push_back({vy[i].second , vy[i-1].second});
    ll ans = 0;
    for (auto i : mop)
    {
        for (auto j : i.second)
            if (join(j.first , j.second))
                ans += i.first;
    }
    cout << ans;
    return 0;
}