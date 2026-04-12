#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll calc(vl sa[], vl sb[], int n, ll a, ll d) {
    if ((n - 1) % d == 0 && (n - 1 - a) / d * 2 * d >= n - 1) {
        return 0;
    }
    return sb[d][(n-1-a)/d] + sa[d][(n-1-a)/d];
}

int main() {
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vl sa[n];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j += i) {
            sa[i].push_back(j == 0 ? 0 : sa[i][j/i-1] + s[j]);
        }
    }

    vl sb[n];
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= 0; j -= i) {
            sb[i].push_back(j == n - 1 ? 0 : sb[i][(n-1-j)/i-1] + s[j]);
        }
    }

    ll ans = 0;
    for (int a = 1; a < n; a++) {
        for (int d = 1; d * d <= n - 1 - a; d++) {
            if ((n - 1 - a) % d == 0) {
                if (d < a) {
                    ans = max(ans, calc(sa, sb, n, a, d));
                }
                if ((n - 1 - a) / d < a) {
                    ans = max(ans, calc(sa, sb, n, a, (n - 1 - a) / d));
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
