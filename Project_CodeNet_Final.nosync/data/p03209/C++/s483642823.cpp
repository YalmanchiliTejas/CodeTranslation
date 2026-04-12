#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define ALL(a) a.begin(), a.end()
ll dx[4] = { 0, 1, 0, -1 };
ll dy[4] = { 1, 0, -1, 0 };
const ll INF = 1e14;
const ll MOD = 1e9 + 7;
// level iバーガーの厚さ a[i] := 2*a[i-1] + 3, a[0] = 1
// level iバーガーのパティの総数 p[i] := 2*p[i-1] + 1, p[0] = 1
vector<ll> a = { 1 }, p = { 1 };


ll f(ll n, ll x)
{
    if (n == 0) {
        return x <= 0 ? 0 : 1;
    } else if (x <= 1 + a[n - 1]) {
        return f(n - 1, x - 1);
    } else {
        return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1);
    }
    cout << f(n, x) << endl;
    return 0;
}