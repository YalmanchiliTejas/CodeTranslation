#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
 
int add(int x, int y) {
    int res = (x + y) % mod;
    res += mod;
    res %= mod;
    return res;
}
int mul(int x, int y) {
    return x * y % mod;
}
int pw(int a, int b) {
    int res = 1;
    while(b) {
    	if(b % 2)
    		res = (res * a) % mod;
    	a  = (a * a) % mod;
    	b /= 2;
	}
	return res;
}

int f[maxn];

int c(int n, int k) {
    int ret = f[n];
    ret = mul(ret, pw(f[k], mod - 2));
    ret = mul(ret, pw(f[n - k], mod - 2));
    return ret;
}
int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;
    f[0] = 1;
    for (int i = 1; i < maxn; ++i)
        f[i] = mul(f[i - 1], i);
    int mm = c(n * m - 2, k - 2);
    int sum = 0, tmp = 0, cc = 0;
    for (int i = 1; i <= n; i++) {
        int x = add(mul(cc, i), -tmp);
        cc++;
        tmp = add(tmp, i);
        x = mul(x, mul(m, m));
        sum = add(sum, x);
    }
    cc = 0, tmp = 0;
    for (int i = 1; i <= m; i++) {
        int x = add(mul(cc, i), -tmp);
        cc++;
        tmp = add(tmp, i);
        x = mul(x, mul(n, n));
        sum = add(sum, x);
    }
    sum = mul(sum, mm);
    cout << sum;
    return 0;
}