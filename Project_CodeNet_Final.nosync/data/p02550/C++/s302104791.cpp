#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
ll n;
ll sol;
int x;
int mod;
bool vis[N];
vector<int> ord;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> mod;
    while (vis[x] == 0)
    {
        ord.push_back(x);
        vis[x] = 1;
        x = (ll) x * x % mod;
    }
    int where = 0;
    while (ord[where] != x)
    {
        where++;
    }
    vector<int> pref;
    vector<int> cycle;
    for (int i = 0; i < where; i++)
    {
        pref.push_back(ord[i]);
    }
    for (int i = where; i < (int) ord.size(); i++)
    {
        cycle.push_back(ord[i]);
    }
    if (n <= (int) pref.size())
    {
        for (int i = 0; i < n; i++)
        {
            sol += pref[i];
        }
        cout << sol << "\n";
        return 0;
    }
    for (int i = 0; i < (int) pref.size(); i++)
    {
        sol += pref[i];
    }
    n -= (int) pref.size();
    ll full = n / (int) cycle.size();
    ll semi = n % (int) cycle.size();
    for (int i = 0; i < (int) cycle.size(); i++)
    {
        sol += full * cycle[i];
        if (i < semi)
        {
            sol += cycle[i];
        }
    }
    cout << sol << "\n";
}
