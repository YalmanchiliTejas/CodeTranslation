#ifdef loc
    #include "../codes/loc_debug.h"
#else
    #include <bits/stdc++.h>
    #define pr(...)
    #define pra(a,n)
    #define praa(a,n,m)
    #define prl()
#endif
using namespace std;

typedef long long ll;
#define sz(a) int(a.size())
const int N = 100005;

int mod = 998244353;
int po(int x, int y) {
    int ret = 1;
    while(y > 0) {
        if(y & 1) {
            ret = (ret * (ll)x) % mod;
        }
        x  = (x * (ll)x) % mod;
        y /= 2;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int tot = 1;
    for(int i = 1; i <= n; i++) {
        tot = (tot * (ll)3) % mod;
    }
    int cur = 1;
    tot -= 2;
    for(int i = 1; i < n / 2; i++) {
        cur = (cur * (ll)2) % mod;
        cur = (cur * (ll)(n - i + 1)) % mod;
        cur = (cur * (ll)po(i, mod - 2)) % mod;
        tot -= cur;
        if(tot < 0) {
            tot += mod;
        }
        tot -= cur;
        if(tot < 0) {
            tot += mod;
        }
    }
    cout << tot << endl;
    return 0;
}