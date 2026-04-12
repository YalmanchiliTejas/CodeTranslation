#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define fi first
#define se second
#define pb push_back
#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 2e5 + 100;
const int maxN = 1e16;
const int oo = 1e18;
const int mod  = 1e9 + 7;

int n;
int a[N], f[N][3];

void upd(int &x, int y) { x = max(x, y); }
signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("spm.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 0, n) FOR(j, 0, 2) f[i][j] = -oo;

    f[0][1] = 0;
    f[1][1] = 0;
    f[1][2] = a[1];
    FOR(i, 2, n) {
        if(i % 2 == 0)  {
            if(f[i - 2][0] > -oo) upd(f[i][0], f[i - 2][0] + a[i]);
            upd(f[i][0], f[i - 1][1]);
            // f[i][1]
            if(f[i - 2][1] > -oo) upd(f[i][1], f[i - 2][1] + a[i]);
            upd(f[i][1], f[i - 1][2]);
        } else {
            if(f[i - 2][1] > -oo) upd(f[i][1], f[i - 2][1] + a[i]);
            upd(f[i][1], f[i - 1][1]);
            // f[i][2]
            if(f[i - 2][2] > -oo) upd(f[i][2], f[i - 2][2] + a[i]);
        }
        //cout << i << ' ' << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << '\n';
    }
    cout << f[n][1];
}
