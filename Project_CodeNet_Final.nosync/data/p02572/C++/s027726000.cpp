#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

//a^n (mod m)
const ll mod = 1e9+7;
ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

//mod mでの a の逆元を求める
ll modinv(ll a) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod; 
    if (u < 0) u += mod;
    return u;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n;
    cin>>n;
    ll a[n];
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        sum %= mod;
        ans += (sum+mod-a[i]) * a[i] % mod;
        ans %= mod;
    }
    ans *= modinv(2);
    ans %= mod;
    cout << ans << endl;
    
}   