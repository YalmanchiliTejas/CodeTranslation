#include<bits/stdc++.h>
/* #define int long long */
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
signed main(){
    ll n;
    cin >> n;
    vector<ll> a(n), suma(n+1);
    rep(i, n) cin >> a[i];
    rep(i, n) suma[i+1] = suma[i] + a[i];
 
    ll ans = 0;
    rep(i, n-1){
        ll x = suma[n] - suma[i+1];
        x %= MOD;
        /* cout << a[i] << " * " << x << endl; */
        ans += (a[i] * x);
        ans %= MOD;
    }
    cout << ans << endl;
}