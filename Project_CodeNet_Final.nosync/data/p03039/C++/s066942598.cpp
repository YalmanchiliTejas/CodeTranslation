#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

constexpr int MOD = 1000000007;

int mod(ll x){
    return x > 0 ? x % MOD : (x+MOD) % MOD;
}

int modm(ll x,ll m){
    return x * m % MOD;
}

int modpow(ll x, ll p) {
    int ret = 1;
    while(p > 0) {
        if (p & 1) ret = modm(ret,x);
        x = modm(x,x);
        p >>= 1;
    }
    return ret;
}

// x * modinv(d)
int modd(ll x,ll d) {
    return modm(x,modpow(d,MOD-2));
}

int main(void)
{
    IOS
    int n, m, k;
    cin >> n >> m >> k;
    ll dn = 0;
    FOR(i,1,n) dn = mod(dn + modm(i,n-i));
    ll dm = 0;
    FOR(i,1,m) dm = mod(dm + modm(i,m-i));
    int c = 1;
    for(int nm = n*m-2,d = 1; d <= k-2; nm--,d++) {
        c = modd(modm(c,nm), d);
    }

    int ans = mod(modm(dn,modm(m,m)) + modm(dm,modm(n,n)) );
    ans = modm(ans,c);

    cout << ans << endl;


    return 0;
}
