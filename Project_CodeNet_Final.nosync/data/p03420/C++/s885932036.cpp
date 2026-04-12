#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

// 最大公約数
ll gcd(ll a, ll b)
{
   if (a%b == 0) {
       return(b);
   } else {
       return(gcd(b, a%b));
   }
}

// 最小公倍数
ll lcm(ll a, ll b){
   return a / gcd(a, b) * b;
}

//素数判定
bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } // n > 3 が保証された
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(unsigned i = 5; i * i <= n; i += 6) {
        if(n % i     == 0) return false; // (6の倍数)-1
        if(n % (i+2) == 0) return false; // (6の倍数)+1
    }
    return true;
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*   *   *   *   *   *   *   *   *   *   *   */

void solve() {
    ll n, k; cin >> n >> k;
    ll ans = 0;
    Rep(b, k+1, n){  // N = pb + r (0 <= r < b)
        ll p, r;
        p = (n+1)/b;
        r = (n+1)%b;
        ans += p*(b-k) + max(0LL, r-k);
    }
    if(k == 0) ans -= n;
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
