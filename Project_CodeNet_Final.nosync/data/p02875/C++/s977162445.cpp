#include <bits/stdc++.h>
#define REP(i, x, y) for (ll i = x; i <= y; i++)
#define BIT(t) (1ll << t)
#define PER(i, y, x) for (ll i = y; i >= x; i--)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pll pair<ll, ll>
#define SIZE(v) ll(v.size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
using namespace std;
typedef long long ll;
//        ios::sync_with_stdio(false);
//        cin.tie(nullptr);

ll const MOD = 998244353;
ll mod_p(ll x, ll y) {
       x %= MOD;
       y %= MOD;
       return (x + y + MOD) % MOD;
}

ll mod_m(ll x, ll y) {
       x %= MOD;
       y %= MOD;
       return x * y%MOD;
}

ll mod_pow(ll x, ll t) {
       x %= MOD;
       if (t == 0) {
               return 1;
       }
       else {
               ll v = mod_pow(x, t / 2);
               if (t % 2 == 0) {
                       return v * v % MOD;
               }
               else {
                       return v * v%MOD * x %MOD;
               }
       }
}

ll mod_inv(ll x) {
       return mod_pow(x, MOD - 2);
}

vll fct(1e7 + 5), invfct(1e7 + 5), pow2(1e7 + 5);
void init(){
        fct[0] = invfct[0] = pow2[0] = 1;
        REP(i,1,1e7 + 2){
                fct[i] = mod_m(fct[i-1], i);
                invfct[i] = mod_inv(fct[i]);
                pow2[i] = mod_m(pow2[i-1], 2);
        }
}

ll ncr(ll x,ll y){
        return mod_m(fct[x], mod_m(invfct[y], invfct[x-y]));
}

int main(){
        init();
        ll n;
        cin >> n;
        ll m = n / 2;
        ll tmp = 0;
        REP(i,m+1, n){
                tmp = mod_p(tmp, mod_m(ncr(n,i), pow2[n-i]));
        }
        cout << mod_p(mod_pow(3,n), mod_m(-2, tmp)) << endl;
}

