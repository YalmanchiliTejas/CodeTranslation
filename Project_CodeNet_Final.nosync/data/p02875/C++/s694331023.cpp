//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)

    
const int MAX = 10000001;
const int MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll MOD = 998244353;
    COMinit();
    ll n;
    cin>>n;
    ll f = n/2 + 1;

    vector<ll> v2(n);
    v2[0] = 1;
    FOR(i,1,n){
        v2[i] = (v2[i-1]*2)%MOD;
    }
    ll x = 3;
    FOR(i,1,n) x = (x*3)%MOD;
    ll res = 0;
    FOR(i,f,n+1){
        //cout<<"n = "<<n<<" i = "<<i<<" "<<COM(n,i)<<" "<<v2[n-i]<<endl;
        //cout<<COM(n,i) * v2[n-i]<<endl;
    
        res += mod(COM(n,i) * v2[n-i],MOD);
        if(res<0)cout<<res<<endl;
    }
    //cout<<endl;
    //cout<<x<<endl;
    x = mod(x-2*res,MOD);
    cout<<x<<endl;

}