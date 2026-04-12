#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define each(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(v) v.begin(), v.end()
#define mset(a, n) memset(a, n, sizeof(a))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const int MOD = 1000000007;
const double eps = 1e-9;

int main(int argc, char *argv[]) {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) cout << a[0];
    else if (n % 2) {
        for (int i = n - 1; i >= 0; i -= 2) cout << a[i] << ' ';
        for (int i = 1; i < n; i += 2) {
            if (i == n - 2) cout << a[i];
            else cout << a[i] << ' ';
        }
    } else {
        for (int i = n - 1; i >= 0; i -= 2) cout << a[i] << ' ';
        for (int i = 0; i < n; i += 2) {
            if (i == n - 2) cout << a[i];
            else cout << a[i] << ' ';
        }
    }

    cout << endl;
    return 0;
}