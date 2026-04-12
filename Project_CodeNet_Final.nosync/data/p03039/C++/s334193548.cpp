#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

ll inv_mod(ll a, ll MOD)
{
    ll b = MOD, u = 1, v = 0;
    while(b){
        ll t = a/b;
        a -= t*b;   swap(a,b);
        u -= t*v;   swap(u,v);
    }
    u %= MOD;
    if(u < 0) u+= MOD;
    return u;
}

int main()
{
    ll i,j;
    ll n,m,k;
    cin >> n >> m >> k;
    
    int max_number = n*m - 2;
    int MOD = 1e9+7;
    
    vector<ll> fac(max_number+1,1);
    vector<ll> inv(max_number+1,1);
    vector<ll> finv(max_number+1,1);
    vector<ll> nCk(max_number+1,1);
    for(i = 2;i <= max_number;++i){
        inv.at(i) = MOD - inv.at(MOD%i)*(MOD/i)%MOD;
    }
    for(i = 1;i <= max_number;++i){
        fac.at(i) = fac.at(i-1)*i%MOD;
        finv.at(i) = finv.at(i-1)*inv.at(i)%MOD;
    }
    for(i = 1;i <= max_number;++i){
        nCk.at(i) = fac.at(max_number)*finv.at(i)%MOD*finv.at(max_number-i)%MOD;
    }


    ll tmp = 0;
    for(i = 0;i < n;++i){
        rep(j,m){
            tmp += m*((i+1)*i/2 + (n + i -1)*(n-i)/2 - i*(n - i));
            tmp += n*((j+1)*j/2 + (m + j -1)*(m-j)/2 - j*(m - j));
        }
        tmp %= MOD;
    }
    tmp *= inv_mod(2, MOD);
    tmp %= MOD;
    cout << tmp*nCk.at(k-2)%MOD << endl; 

    return 0;
}