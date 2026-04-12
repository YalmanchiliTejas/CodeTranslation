#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3 + 5;
const long long mod = 1e9 + 7;
long long dp[MAX_N][MAX_N];
long long calc[MAX_N][MAX_N];
int n, a, b, c, d;

long long power(long long x, long long y, long long p){
    long long res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
long long fact[MAX_N], inv_fact[MAX_N];
void pre(){
    fact[0] = 1;
    inv_fact[0] = 1;
    int i = 0;
    for(i = 1; i < MAX_N; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
        inv_fact[i] = power(fact[i], mod - 2, mod);
    }
}
long nCr(int n, int r){
    if(n < r)
        return 0;
    long long ans = fact[n];
    ans *= inv_fact[r];
    ans %= mod;
    ans *= inv_fact[n - r];
    ans %= mod;
    return ans;
}

long long go(int size, int till_now){
    if(size == b + 1){
        if(till_now == n) {
            //cout << size << " " << till_now << "\n";
            return 1;
        }
        else
            return 0;
    }
    if(dp[size][till_now] != -1)
        return dp[size][till_now];
    long long ans = go(size + 1, till_now);
    long long ways = 1;
    //if(c != 1)
        //ways = calc[size][till_now];
    int rem = n - till_now;
    for(int i = 1; i < c; i++){
        if(rem - (i - 1) * size < size)
            break;
        ways *= nCr(rem - (i - 1) * size, size);
        ways %= mod;
    }
    for(int i = c; i <= d; i++){
        if(rem - (i - 1) * size < size)
            break;
        ways *= nCr(rem - (i - 1) * size, size);
        ways %= mod;
        ans += ((ways * inv_fact[i]) % mod * go(size + 1, till_now + size * i)) % mod;
        ans %= mod;
    }
    return dp[size][till_now] = ans;
}
void solve(){
    int i = 0, j = 0;
    for(i = a; i <= b; i++){
        for(j = 0; j <= n; j++){
            int rem = n - j;
            if(rem - (c - 1) * i < 0)
                break;
            calc[i][j] = power(power(fact[i], c - 1, mod), mod - 2, mod);
            calc[i][j] *= fact[n];
            calc[i][j] %= mod;
            calc[i][j] *= inv_fact[rem - (c - 1) * i];
            calc[i][j] %= mod;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << go(a, 0) << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t = 1;
    //cin >> t
    while(t--){
        cin >> n >> a >> b >> c >> d;
        solve();
    }

    return 0;
}
