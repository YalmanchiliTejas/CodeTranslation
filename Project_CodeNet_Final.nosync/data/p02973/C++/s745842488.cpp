#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define forn(i, n) for(ll i = 0; i < (n); i++)
#define fori(i, b, e) for(ll i = (b); i < (e); i++)
#define forr(i, b, e) for(ll i = (b); i >= (e); i--)
#define allele(v) v.begin(), v.end()
#define fi first
#define se second
#define Mat vector<vector<ll>>
#define Arr vector<ll>
#define Matd vector<vector<ld>>
#define Arrd vector<ld>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    Arr a(n);
    forn(i, n) cin >> a[i];
    multiset<ll> lasts;
    forn(i, n)
    {
        if(lasts.empty() || *lasts.begin() >= a[i])
            lasts.insert(a[i]);
        else
        {
            auto it = lasts.lower_bound(a[i]);
            it--;
            ll val = *it;
            ll cnt = lasts.count(val);
            lasts.erase(val);
            forn(i, cnt - 1) lasts.insert(val);
            lasts.insert(a[i]);
        }
    }
    cout << lasts.size() << endl;
    return 0;
}