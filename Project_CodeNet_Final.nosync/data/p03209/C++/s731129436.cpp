#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

vector<ll> a, p;

ll dfs(ll n, ll x) {
    if (n == 0)
        return x <= 0 ? 0 : 1;
    else if (x <= a[n - 1] + 1)
        return dfs(n - 1, x - 1);
    else
        return p[n - 1] + 1 + dfs(n - 1, x - 2 - a[n - 1]);
}

int main() {
    ll n, x;
    cin >> n >> x;

    a.push_back(1), p.push_back(1);
    rep(i, n) {
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1);
    }

    cout << dfs(n, x) << endl;
    return 0;
}
