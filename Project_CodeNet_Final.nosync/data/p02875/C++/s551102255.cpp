#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll mod = 998244353;

ll modpow(ll a, ll e){
        ll res = 1;
        do {
                if(e % 2) res = res * a % mod;
                a = a * a % mod;
        } while(e >>= 1);
        return res;
}

int main(){
        cin.tie(0);
        cin.sync_with_stdio(0);
        cin.exceptions(cin.failbit);

        int n;
        cin >> n;

        vector<ll> fs(n+1,1);
        rep(i,0,n) fs[i+1] = fs[i] * (i+1) % mod;

        auto bin = [&](int n, int k){
                return fs[n] * modpow(fs[k] * fs[n-k] % mod, mod-2) % mod;
        };

        ll sub = 0;

        rep(i,n/2+1,n+1) sub += bin(n, i) * modpow(2, n-i) % mod;

        ll ans = modpow(3, n) - 2*sub;
        ans %= mod;

        if(ans < 0) ans += mod;

        cout << ans << endl;
}