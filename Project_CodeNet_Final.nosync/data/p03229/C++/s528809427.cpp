#include <bits/stdc++.h>
using namespace std;

typedef vector<int> veci;
typedef pair<int, int> pii;
typedef vector<pii> vecii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vecl;
typedef vector<pll> vecll;
#define EPS (1e-9)
#define MOD (1e9 + 7)
#define fi first
#define se second
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll ans1 = 0;
    int p = 1;
    ll prev = v[n/2];
    int l = 0, r = n - 1;
    while (p < n) {
        if (p % 2) {
            ans1 += abs(prev - v[l]);
            prev = v[l];
            l += 1;
        } else {
            ans1 += abs(prev - v[r]);
            prev = v[r];
            r -= 1;
        }
        p += 1;
    }

    ll ans2 = 0;
    p = 1;
    if (n%2==0) {
        prev = v[(n-1)/2];
    } else {
        prev = v[n/2];
    }
    l = 0, r = n - 1;
    while (p < n) {
        if (p % 2 == 0) {
            ans2 += abs(prev - v[l]);
            prev = v[l];
            l += 1;
        } else {
            ans2 += abs(prev - v[r]);
            prev = v[r];
            r -= 1;
        }
        p += 1;
    }

    cout << max(ans1,ans2) << endl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL_TEST
    (void)argc;
    const string strpath = string(argv[0]) + string("-test.in");
    freopen(strpath.c_str(), "r", stdin);
    int tcs;
    cin >> tcs;
    while (tcs-- > 0)
#endif
    solve();
}
