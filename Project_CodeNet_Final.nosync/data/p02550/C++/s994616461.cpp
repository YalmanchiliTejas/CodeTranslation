#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, x, MOD;
    cin >> n >> x >> MOD;
    vector<ll> a;
    a.push_back(x);
    vector<int> gdzie(MOD, -1);
    while (gdzie[a.back()] == -1)
    {
        gdzie[a.back()] = a.size() - 1;
        ll ost = a.back();
        a.push_back(ost * ost % MOD);
    }
    ll powt = gdzie[a.back()];
    a.pop_back();
    vector<ll> cykl;
    while (a.size() >= powt + 1)
    {
        cykl.push_back(a.back());
        a.pop_back();
    }
    reverse(cykl.begin(), cykl.end());
    ll odp = 0;
    if (n <= a.size())
    {
        for (int i = 0; i < n; ++i)
            odp += a[i];
    }
    else
    {
        for (int i = 0; i < a.size(); ++i)
            odp += a[i];
        n -= a.size();
        ll cale = n / cykl.size();
        ll reszta = n - cale * cykl.size();
        ll sCykl = 0;
        for (int i = 0; i < cykl.size(); ++i)
            sCykl += cykl[i];
        odp += sCykl * cale;
        for (int i = 0; i < reszta; ++i)
            odp += cykl[i];
    }
    cout << odp;
    return 0;
}
