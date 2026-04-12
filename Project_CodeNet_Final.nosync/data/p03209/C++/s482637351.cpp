#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K, X;
vector<int> u, v;

ll rec(ll n, ll x)
{
    if (n == 0)
        return (x <= 0 ? 0 : 1);
    ll p = (1LL << n) - 1;
    if (x <= 2 * p)
        return rec(n - 1, x - 1);
    return p + 1 + rec(n - 1, x - 2 * p - 1);
}

int main()
{
    cin >> N >> X;
    cout << rec(N, X) << endl;
}