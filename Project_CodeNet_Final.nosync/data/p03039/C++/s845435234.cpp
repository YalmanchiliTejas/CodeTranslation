#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int modpow(int a, int p){
    if (p == 0) return 1;
    if (p%2 == 0) {
        int half = modpow(a, p/2);
        return (long long)half * half % mod;
    }
    else return (long long)a * modpow(a, p-1) % mod;
}
int cmb(int n, int r) {
    r = min(r, n-r);
    long long tmpM = 1, tmpD = 1;
    for (int i = 0; i<r; i++) {
        tmpM *= n-i;
        tmpD *= i+1;
        tmpM %= mod;
        tmpD %= mod;
    }
    return tmpM * modpow(tmpD, mod-2) % mod;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    long long ans = 0;
    for (int i = 1; i<N; i++) {
        ans += (long long)(N-i)*M*M*i;
        ans %= mod;
    }
    for (int i = 1; i<M; i++) {
        ans += (long long)(M-i)*N*N*i;
        ans %= mod;
    }
    ans *= cmb(N*M-2, K-2);
    ans %= mod;
    printf("%lld\n", ans);
    return 0;
}