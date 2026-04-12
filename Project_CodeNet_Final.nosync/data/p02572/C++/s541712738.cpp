#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
//const long long MOD = 998244353;
const long long INF_LL = 1e18+11; const int INF_int = 1e9+11;
#define ll long long
#define mp std::make_pair
#define rep(i,n) for(int i = 0;i<n;i++)
#define lrep(i,n) for(long long i = 0;i<n;i++)
#define All(a) a.begin(),a.end()
#define Debug_Output_ALL(a) for(auto x:a) cout << x << " ";cout << endl;
//aのMODbでの逆元
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    rep(i,n){
        sum+=a[i];
        sum%=MOD;
    }
    sum*=sum;
    sum%=MOD;
    rep(i,n){
        sum-=((a[i]*a[i])%MOD);
        sum%=MOD;
    }
    sum*=modinv(2,MOD);
    sum%=MOD;
    if(sum<0) sum+=MOD;
    cout << sum << endl;
}