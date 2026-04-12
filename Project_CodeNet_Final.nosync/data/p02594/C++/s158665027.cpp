/*
    Ujjawal Pabreja [cuber_coder]
*/
#include <bits/stdc++.h> 
#include <functional> 
using namespace std;
#define speed_cubing    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll              long long
#define ld              long double
#define rep(i,a)        for(ll i = 0 ; i < a ; i++)
#define repe(i,a,b)     for(ll i = a ; i < b ; i++)
#define bac(i,a)        for(ll i = a ; i >= 0 ; i--)
#define bace(i,a,b)     for(ll i = a ; i >= b ; i--)
#define pb              push_back
#define in              insert
#define ff              first
#define ss              second
#define setbit(x)       __builtin_popcountll(x)
#define init(c,a)       memset(c,a,sizeof(c))
#define all(c)          c.begin(),c.end()
#define sz(c)           (ll)c.size()
#define lb              lower_bound
#define ub              upper_bound
#define maxe            *max_element
#define mine            *min_element
#define rev             reverse
#define Y				"YES"
#define N 				"NO"
#define endl            "\n"
#define debug(x)        cout << #x << " : " << x << endl;
const ll inf = 1e18;  
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
const ll MAX = 2e5 + 1;

inline ll add(ll a,ll b) {return ((a % mod) + (b % mod)) % mod;}
inline ll sub(ll a,ll b) {return ((a % mod) - (b % mod) + mod) % mod;}
inline ll mul(ll a,ll b) {return ((a % mod) * (b % mod)) % mod;}
ll pwr(ll x,ll n){
    if(n == 0){
        return 1;
    }
    if(n&1){
        return mul(x, pwr(mul(x, x), (n - 1) / 2));
    } else {
        return pwr(mul(x, x), n / 2);
    }
}
ll modInv(ll n){ 
    return pwr(n, mod - 2); 
}
ll gcd(ll a,ll b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
// ====== Useful functions end ======
 
// ====== Global Variables begin ======

// ====== Global Variables end ======

void speed_solve(){
    ll x;
    cin >> x;
    cout << (x >= 30 ? "Yes" : "No");
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    speed_cubing;
    ll test_cases = 1;
    // cin >> test_cases;
    rep(i,test_cases){
        // cout << "Case #" << i + 1 << ": ";
        speed_solve();
    }
    return 0;
}