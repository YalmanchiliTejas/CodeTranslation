#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll A, B;
    cin >> A >> B;
    vector<vector<ll>> d(A + 1, vector<ll>(B + 1));
    for (ll i = 1; i <= A; i++) {
        for (ll j = 1; j <= B; j++) {
            cin >> d[i][j];
        }
    }

    constexpr ll MAX = 100;
    vector<vector<ll>> f(MAX + 1, vector<ll>(MAX + 1, 0));
    for (ll a = 0; a <= MAX; a++) {
        for (ll b = 0; b <= MAX; b++) {
            for (ll x = 1; x <= A; x++) {
                for (ll y = 1; y <= B; y++) {
                    f[a][b] = max(f[a][b], d[x][y] - x * a - y * b);
                }
            }
        }
    }

    for (ll x = 1; x <= A; x++) {
        for (ll y = 1; y <= B; y++) {
            ll D = LLONG_MAX;
            for (ll a = 0; a <= MAX; a++) {
                for (ll b = 0; b <= MAX; b++) {
                    D = min(D, x * a + y * b + f[a][b]);
                }
            }
            if (D != d[x][y]) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;
    const ll N = (MAX + 1) * 2;
    const ll M = MAX * (MAX + 2) + 2 * MAX + 1;
    cout << N << " " << M << endl;
    for (ll i = 1; i <= MAX; i++) {
        cout << i << ' ' << i + 1 << " X" << endl;
    }
    for (ll i = 1; i <= MAX; i++) {
        cout << i + MAX + 1 << ' ' << i + MAX + 2 << " Y" << endl;
    }

    for (ll a = 0; a <= MAX; a++) {
        for (ll b = 0; b <= MAX; b++) {
            cout << a + 1 << ' ' << b + 102 << ' ' << f[a][MAX - b] << endl;
        }
    }

    cout << "1 202" << endl;
}