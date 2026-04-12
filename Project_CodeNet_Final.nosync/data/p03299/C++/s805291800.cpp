#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define int long long
using namespace std;
typedef pair<int, int> P;
const int INF = 1e15;
const int mod = 1e9 + 7;

int n;
int h[105];

long long mod_pow(long long x, long long n){
    if(n == 0) return 1;
    long long res = mod_pow(x*x % mod, n / 2);
    if(n & 1) res = res*x % mod;
    return res;
}

P calc(int L, int R, int v){
    int dp1 = 1, dp2 = 1;
    if(L > R) return {-1, -1};
    int MIN = INF;
    rep(i, L, R + 1) MIN = min(MIN, h[i]);
    int w = R - L + 1;
    rep(i, L, R + 1) if(MIN != h[i]) w--;
    int pre = L - 1;
    rep(i, L, R + 1){
        if(MIN == h[i]){
            P p = calc(pre + 1, i - 1, MIN);
            if(p.first >= 0){
                (dp1 *= p.first) %= mod;
                (dp2 *= p.first + p.second) %= mod;
            }
            pre = i;
        }
    }
    P p = calc(pre + 1, R, MIN);
    if(p.first >= 0){
        (dp1 *= p.first) %= mod;
        (dp2 *= p.first + p.second) %= mod;
    }
    (dp2 = dp2 * mod_pow(2, w) + (mod_pow(2, MIN - v) + mod - 2) * dp1) %= mod;
    (dp1 *= mod_pow(2, MIN - v)) %= mod;
    return {dp1, dp2};
}

signed main(){
    cin >> n;
    rep(i, 1, n + 1) cin >> h[i];
    cout << calc(1, n, 0).second << endl;
}