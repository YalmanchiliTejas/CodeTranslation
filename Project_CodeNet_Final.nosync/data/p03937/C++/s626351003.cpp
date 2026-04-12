#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
ll mod = 1000000007;

int main() {
source:
    ll h, w;
    cin >> h >> w;
    string a[h];
    rep(i, h) { cin >> a[i]; }

    ll left[h], right[h];
    rep(i, h) {
        rep(j, w) {
            if (a[i][j] == '#') {
                left[i] = j;
                break;
            }
        }
    }
    rep(i, h) {
        repb(j, w) {
            if (a[i][j] == '#') {
                right[i] = j;
                break;
            }
        }
    }

    bool result = true;
    repd(i, 1, h) {
        if (left[i] != right[i - 1]) {
            result = false;
            break;
        }
    }
    if (result) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}

