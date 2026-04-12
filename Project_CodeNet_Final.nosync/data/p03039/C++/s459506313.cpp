#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mod_pow(int x,int y) {
    int res = 1;
    while(y > 0) {
        if(y%2) {
            res = res*x%mod;
        }
        x = x*x%mod;
        y/=2;
    }
    return res;
}
int fac[200005], finv[200005], inv[200005];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 200005; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
int COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
signed main() {
    int N,M,K;
    cin >> N >> M >> K;
    COMinit();
    int ans = 0;
    for(int i = 1; i < N; i++) {
        ans += i*M%mod*M%mod*(N-i)%mod*COM(N*M-2,K-2)%mod;
        ans %= mod;
    }
    for(int i = 1; i < M; i++) {
        ans += i*N%mod*N%mod*(M-i)%mod*COM(M*N-2,K-2)%mod;
        ans %= mod;
    }
    cout << ans << endl;
}
