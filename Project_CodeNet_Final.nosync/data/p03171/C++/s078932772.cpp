#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e15 + 10;
const ll MAX = 1e14 + 10;
const ld EPS = 1e-9;
const int N = 3e3 + 10;
const int M = 1e5 + 10;

ll a[N];
ll d[N][N];

void solve() {
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n) {
        if (n % 2)
            d[i][i] = a[i];
        else
            d[i][i] = -a[i];
    }

    frab(len, 2, n + 1)
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (n % 2 == len % 2) {
                d[l][r] = max(d[l][r - 1] + a[r], d[l + 1][r] + a[l]);
            } else {
                d[l][r] = min(d[l][r - 1] - a[r], d[l + 1][r] - a[l]);
            }
        }
    cout << d[0][n - 1];
}



int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    solve();
}
