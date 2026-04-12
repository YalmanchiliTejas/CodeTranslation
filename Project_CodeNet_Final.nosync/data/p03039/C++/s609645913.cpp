#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long fact[200005];
void precalc(){
    fact[0] = 1;
    for(long long i = 1; i <= 200000; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
long long bigmod(long long a, long long p){
    if(p == 0){
        return 1;
    }
    long long ans = bigmod(a, p/2);
    ans = (ans * ans) % mod;
    if(p % 2 == 1){
        ans = (ans * a) % mod;
    }
    return ans;
}
long long inverse(long long a){
    return bigmod(a, mod - 2);
}
long long nCr(long long n, long long m){
    long long ans = (fact[n] * inverse(fact[n - m])) % mod;
    ans = (ans * inverse(fact[m])) % mod;
    return ans;
}
long long sum(long long n, long long m){
    long long ans = (m * (m - 1) * (m + 1))/6;
    ans = ans % mod;
    ans = (ans * n) % mod;
    ans = (ans * n) % mod;
    return ans;
}
int main(){
    precalc();
    int n, m, k;
    cin >> n >> m >> k;
    long long ans = (sum(n, m) + sum(m, n)) % mod;
    ans = (ans * nCr(n * m - 2, k - 2)) % mod;
    cout << ans;
    return 0;
}