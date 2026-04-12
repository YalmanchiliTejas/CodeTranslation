#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1e9+7, maxn = 2e5+5;
int mult(int a, int b) {
    return (1LL*a*b) % M;
}
void madd(int& a, int b) {
    a += b;
    if (a >= M) a -= M;
}
int modexp(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mult(res,a);
        a = mult(a,a);
        b >>= 1;
    }
    return res;
}
int inverse(int x) {
    return modexp(x,M-2);
}
int n, m, k; 
int fac[maxn], ifac[maxn];

int comb(int n, int r) {
    assert(0 <= r && r <= n);
    int res = fac[n];
    res = mult(res,ifac[r]);
    res = mult(res,ifac[n-r]);
    return res;
}

int main() 
{
    cin >> n >> m >> k; 
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = mult(fac[i-1],i);
        ifac[i] = inverse(fac[i]);
    }
    int ans = 0;
    for (int d = 1; d < m; d++) {
        int add = mult(d,mult(m-d,mult(n,n)));
        madd(ans,add);
    }
    for (int d = 1; d < n; d++) {
        int add = mult(d,mult(n-d,mult(m,m)));
        madd(ans,add);
    }
    ans = mult(ans,comb(m*n-2,k-2));
    cout << ans << '\n';
}
