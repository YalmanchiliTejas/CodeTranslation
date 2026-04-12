#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll a, p;

ll f(ll n, ll x) {
    if (n == 0) if (x <= 0) return 0; else return 1;
    else if (x <= 1) return 0;
    else if (x <= a[n-1] + 1) return f(n-1, x-1);
    else if (x == a[n-1] + 2) return p[n-1] + 1;
    else if (x <= 2 + 2 * a[n-1]) return p[n-1] + 1 + f(n-1, x-a[n-1]-2);
    else return 2 * p[n-1] + 1;
}

int main()
{
    ll N, X; cin >> N >> X;
    a.push_back(1);
    p.push_back(1);
    rep(i, N) {
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1);
    }
    //for (auto elem : a) cout << elem << " "; cout << endl;
    //for (auto elem : p) cout << elem << " "; cout << endl;

    cout << f(N, X) << endl;
    return 0;
}