#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll fmemo[200002];
ll imemo[200002];
ll ifmemo[200002];
ll s[200002];
ll t[200002];
int m;

ll modpow(ll x, ll n){
    ll res = 1;
    ll mul = x;
    while(n){
        if(n % 2) res = res * mul % MOD;
        mul = mul * mul % MOD;
        n /= 2;
    }
    return res;
}

ll fact(ll n){
    if(n == 0) return 1;
    if(fmemo[n]) return fmemo[n];
    return fmemo[n] = n * fact(n - 1) % MOD;
}

ll ifact(ll n){
    if(n == 0) return 1;
    if(ifmemo[n]) return ifmemo[n];
    return ifmemo[n] = imemo[n] * ifact(n - 1) % MOD;
}

ll com(ll n, ll k){
    if(k > n) return 0;
    if(k == n || k == 0) return 1;
    return (fact(n) * ifact(k) % MOD) * ifact(n - k) % MOD;
}

ll sum(int i){
    if(i == 0) return 0;
    if(s[i] > 0) return s[i];
    return s[i] = sum(i - 1) + i;
}

ll tate(int i){
    if(i == 1) return 0;
    if(t[i] > 0) return t[i];
    return t[i] = (tate(i - 1) + sum(i - 1)) % MOD;
}

ll count(int k){
    if(k == 0) return 0;
    ll line = sum(k - 1);
    int up = 1, down = m - 1;
    ll plsum = sum(m - 1);
    ll nowsum = plsum;
    for(int i = 1; i < m; i++){
        nowsum = nowsum + up - down;
        plsum += nowsum;
        up++;
        down--;
    }
    return (count(k - 1) + tate(m) + line * m * m + plsum * (k - 1)) % MOD;
}

int main()
{
    ll n, k;
    cin >> n >> m >> k;
    for(ll i = 1; i <= 200001; i++){
        imemo[i] = modpow(i, MOD - 2);
    }
    for(int i = 0; i <= 200001; i++){
        s[i] = 0, t[i] = 0;
    }
    cout << (com(n * m - 2, k - 2) * count(n)) % MOD << endl;
}
