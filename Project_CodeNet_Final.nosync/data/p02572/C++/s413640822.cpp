#include <bits/stdc++.h>
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll sum = 0, t;
    int n;
    cin >> n;
    vector<ll> a;
    for (int i = 0; i < n; i++) {
        cin >> t;
        sum += t;
        a.push_back(t);
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        sum = sum - a[i];
        res += a[i] * (sum % (ll)(1000000007));
        res = res % (ll)(1000000007);
    }
    cout << res << endl;
}