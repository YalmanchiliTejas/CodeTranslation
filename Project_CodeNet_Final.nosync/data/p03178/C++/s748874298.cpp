#ifdef loc
    #include "loc_debug.h"
#else
    #include <bits/stdc++.h>
    #define pr(...)
    #define pra(a,n)
    #define praa(a,n,m)
    #define prl()
#endif
using namespace std;

typedef long long ll;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define sz(a) int(a.size())
const int N = 10005, mod = 1e9 + 7;

char a[N];
int d;

int f[N][105][2];

int go(int pos, int rem, bool small) {
    int& res = f[pos][rem][small];
    if(res == -1) {
        res = 0;
        if(a[pos] == 0) {
            res = (rem == 0);
        } else {
            rep(dig, '0', int('9' + 1)) {
                if(dig > a[pos] && small == 0) {
                    break;
                }
                res += go(pos + 1, (rem + dig - '0') % d, small || (dig < a[pos]));
                if(res >= mod) {
                    res -= mod;
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    cin >> d;
    memset(f, -1, sizeof(f));
    int res = go(0, 0, 0);
    res--;
    if(res < 0) {
        res += mod;
    }
    cout << res << endl;
}