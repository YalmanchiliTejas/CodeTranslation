#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

ll pow_mod(ll a, ll b, ll m){
    ll ret = 1;
    while (b > 0) {
        if (b & 1) {
            ret = ret * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}

ll inv_mod(ll a, ll m){
    return pow_mod(a, m - 2, m);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll sum = 0;
    ll sum2 = 0;
    rep(i, N) {
        sum += A[i];
        sum %= mod;
        sum2 += A[i] * A[i];
        sum2 %= mod;
    }
    ll ans = sum * sum % mod;
    ans -= sum2;
    (ans += mod) %= mod;
    (ans *= inv_mod(2, mod)) %= mod;
    output(ans);
    
    
    
    return 0;
}
