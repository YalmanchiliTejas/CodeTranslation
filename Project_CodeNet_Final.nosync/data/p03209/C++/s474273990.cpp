#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<ll> a{1}, p{1};

ll f(ll n, ll x)
{
    if (n == 0)
        return x <= 0 ? 0 : 1;
    else if (x <= 1 + a[n - 1])
        return f(n - 1, x - 1);
    else
        return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1);
    }
    cout << f(n, x) << endl;
}