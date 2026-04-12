#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define double long double
#define pii pair<int, int>
#define FOR(i, a, b) for(int i = a; i < (int)(b); ++i)
#define all(x) x.begin(), x.end()
#define deb(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) {
        cin >> a[i];
    }
    int d[n][n + 1];
    FOR(i, 0, n) {
        d[i][i + 1] = a[i];
    }
    FOR(len, 2, n + 1) {
        FOR(i, 0, n - len + 1) {
            d[i][i + len] = max(a[i] - d[i + 1][i + len], a[i + len - 1] - d[i][i + len - 1]);
        }
    }
    cout << d[0][n];
    return 0;
}