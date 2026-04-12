#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> d(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    // reverse(ALL(d));
    vector<ll> imos(n + 1, 0);
    imos[0] = 1;
    imos[1] = -1;
    for (ll i = 0; i < n; i++)
    {
        if (d[i] / 10 == 0)
        {
            continue;
        }
        ll end = min(i + d[i] / 10 + 1, n);
        imos[i + 1]++;
        imos[end]--;
    }
    for (ll i = 1; i <= n; i++)
    {
        imos[i] += imos[i - 1];
    }
    for (ll i = 0; i < n; i++)
    {
        if (imos[i] == 0)
        {
            cout << "no" << endl;
            return 0;
        }
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << imos[i] << ' ';
    // }
    // cout << endl;
    reverse(ALL(d));
    vector<ll> imos2(n + 1, 0);
    imos2[0] = 1;
    imos2[1] = -1;
    for (ll i = 0; i < n; i++)
    {
        if (d[i] / 10 == 0)
        {
            continue;
        }
        ll end = min(i + d[i] / 10 + 1, n);
        imos2[i + 1]++;
        imos2[end]--;
    }
    for (ll i = 1; i <= n; i++)
    {
        imos2[i] += imos2[i - 1];
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << imos2[i] << ' ';
    // }
    // cout << endl;
    for (ll i = 0; i < n; i++)
    {
        if (imos2[i] == 0)
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}
