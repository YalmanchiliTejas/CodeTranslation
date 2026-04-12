#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// nice job //
ll n;
const ll mod = 998244353;
const ll N = 1e7 + 5;
ll fac[N];
ll ifac[N];
ll ME(ll x, ll P, ll m)
{
        ll res = 1LL;
        ll cur = x;
        while(P) {
                if(P&1) res = (res * cur)%mod;
                cur = (cur * cur)%mod;
                P >>= 1;
        }
        return res;
}
ll inv(ll x)
{
        return ME(x , mod-2, mod);
}
int main() {
        cin >> n;
        fac[0] = 1LL;
        ifac[0] = 1LL;
        for(ll i=1;i<=n+2;i++) {
                fac[i] = (fac[i-1] * i)%mod;
                ifac[i] = inv(fac[i]);
        }
        ll ans = 1LL;
        vector< ll > pw;
        pw.push_back(1LL);
        for(ll i=1;i<=n;i++) {
                pw.push_back(((pw.back())*2LL)%mod);
        }
        for(ll i=1;i<=n;i++) {
                ans = (ans * 3LL)%mod;
        }
        for(ll i = (n/2) + 1 ; i <= n ; i++) {
                ll h  = (fac[n] * ifac[i])%mod;
                h = (h * ifac[n-i])%mod;
                h = (h * pw[n-i+1])%mod;
                ans = (ans - h + mod)%mod;
        }
        cout << ans << endl;
}
