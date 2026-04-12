#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 10000001;

int n, fact[N], inv[N], mod = 998244353;

int powlog(int a, int b){
    if(b == 0) return 1;
    int ret = powlog(a, b / 2);
    if(b % 2) return 1LL * ret * ret % mod * a % mod;
    return 1LL * ret * ret % mod;
}
int C(int n, int r){
    return 1LL * fact[n] * inv[r] % mod * inv[n - r] % mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    for(int i = 1 ; i < N ; i++){
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    inv[N - 1] = powlog(fact[N - 1], mod - 2);
    for(int i = N - 2 ; i >= 0 ; i--){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    }
    cin >> n;
    int cur = 0;
    for(int i = n / 2 + 1 ; i <= n ; i++){
        cur = (cur + 1LL * C(n, i) * powlog(2, n - i)) % mod;
    }
    cout << (1LL * powlog(3, n) - 2 * cur + 2 * mod) % mod;
}
