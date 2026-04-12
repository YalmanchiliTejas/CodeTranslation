#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    ll mod = 1e9 + 7, res = 0, p;
    cin >> p;
    for(int i=1; i<n; i++) {
        ll num;
        cin >> num;
        res = (res + num * p) % mod;
        p = (p + num) % mod;
    }
    cout << res << endl;

    return 0;
}