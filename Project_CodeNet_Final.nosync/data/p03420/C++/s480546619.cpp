#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define pb push_back
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forrn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define PYMOD(a, m) ((((a) % (m)) + (m)) % (m))
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ff first
#define ss second

const int mod = 1e9 + 7;

int main() {
    // Code here:

    int n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << 1ll * n * n << endl;
        return 0;
    }
    
    ll ans = 0;
    for (int b = k + 1; b <= n; b++) {
        for (int nga = b; nga < n + b; nga += b) {
            if (nga <= n) {
                ans += b - k;
                //cout << b << " " << nga << " " << b - k << endl;
            } else if (nga - b + k <= n) {
                ans += n - (nga - b + k) + 1;
                //cout << b << " " << nga << " " << n - (nga - b + k) + 1 << endl;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
