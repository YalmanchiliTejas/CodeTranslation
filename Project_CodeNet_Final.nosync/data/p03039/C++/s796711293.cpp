#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int mod = 1e9 + 7;

int sm(int a) {
    if(a%2 == 0) {
        return a/2*(a+1)%mod;
    } else {
        return (a+1)/2*a%mod;
    }
}

int pow(int a, int b) {
    if(b == 0) return 1;
    if(b%2) return a*pow(a, b-1)%mod;
    return pow(a*a%mod, b/2)%mod;
}

int ncr(int a, int b) {
    int ret = 1;
    for(int i = 0; i < b; ++i) {
        int num = a-i;
        ret = (ret*num)%mod;
    }
    int denom = 1;
    for(int i = 1; i <= b; ++i) {
        denom = (denom*i)%mod;
    }
    ret *= pow(denom, mod-2);

    return ret;
}

int32_t main() {

    int n, m, k; cin >> n >> m >> k;

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int left = sm(j);
            int right = sm(m-j-1);
            int rows_below = n-i-1;
            int below = (left+right)*rows_below + m*sm(rows_below);
            ans += right + below;
            ans %= mod;
        }
    }

    int picks = ncr(n*m-2, k-2)%mod;
    ans = (ans*picks)%mod;

    cout << ans << endl;
    
    return 0;
}
