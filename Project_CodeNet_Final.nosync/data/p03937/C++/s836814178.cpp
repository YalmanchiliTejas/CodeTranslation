#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100;
string a[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> m;
    int c = 0;
    forn (i, n) {
        cin >> a[i];
        forn (j, m)
            c += a[i][j] == '#';
    }
    int y = 0;
    int k = 0;
    forn (x, n) {
        if (a[x][y] != '#') {
            cout << "Impossible\n";
            return 0;
        }
        ++k;
        while (y + 1 < m && a[x][y + 1] == '#')
            ++y, ++k;
    }
    if (y == m - 1 && k == c) {
        cout << "Possible\n";
        return 0;
    }
    cout << "Impossible\n";
}
