#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep3(i, l, n) for (int i = l; i < n; ++i)
#define chmax(a, b) a = (a >= b ? a : b)
#define chmin(a, b) a = (a <= b ? a : b)
#define out(a) cout << a << endl
#define outa(a, n) rep(_, n) cout << a[_] << " "; cout << endl
#define SZ(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
#define FIX(a) fixed << setprecision(a)

int main() {
    int n, m;
    cin >> n >> m;
    int table[8][8] = {0};
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        table[a][b] = 1;
        table[b][a] = 1;
    }
    vector<int> v;
    rep(i, n) v.eb(i);
    int c = 0;
    do {
        if (v[0] != 0) break;
        rep3(i, 1, n) {
            if (table[v[i]][v[i - 1]] == 0) break;
            if (i == n - 1) c++;
        }
    } while (next_permutation(all(v)));
    out(c);
}
