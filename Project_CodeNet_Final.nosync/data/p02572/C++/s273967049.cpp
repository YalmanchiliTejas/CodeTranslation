#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll n, a[202020], s;

ll pw(ll a, ll b){
    ll ret = 1; a %= mod;
    while(b){
        if(b & 1) ret = ret * a % mod;
        b >>= 1; a = a * a % mod;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i], s += a[i];
    s %= mod;
    ll res = s * s % mod;
    for(int i=1; i<=n; i++){
        res -= a[i] * a[i] % mod;
        res %= mod; res += mod; res %= mod;
    }
    cout << res * pw(2, mod-2) % mod;
}