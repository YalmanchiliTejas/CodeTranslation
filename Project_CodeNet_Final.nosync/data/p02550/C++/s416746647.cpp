#include "bits/stdc++.h"

using namespace std;

typedef long double ld;
typedef long long ll;

#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define f first
#define s second

template<typename T, typename U> bool ckmin(T &a, U b){ return b < a ? a = b, true : false; }
template<typename T, typename U> bool ckmax(T &a, U b){ return b > a ? a = b, true : false; }

ll n, x, m;
vector<bool> used;
vector<ll> res, cyc;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> m;
    used.assign(m, false);
    while(!used[x]){
        used[x] = true;
        res.pb(x);
        x = (x * x)%m;
    }
    ll rep = -1, ans = 0;
    for(int i = 0; i < sz(res); ++i){
        if(res[i] == x) rep = i;
    }
    assert(rep != -1);
    for(int i = rep; i < sz(res); ++i) cyc.pb(res[i]);
    for(int i = 0; i < rep; ++i){
        if(n <= 0) break;
        ans += res[i]; --n;
    }
    if(n == 0){
        cout << ans;
        return 0;
    }
    // cout << rep << " " << n << " " << sz(res) << " "  << sz(cyc) << "\n";
    // for(auto i : res) cout << i << " ";
    // cout << "\n" << rep << "\n";
    ll tot = 0;
    for(auto i : cyc){
        tot += i;
    }
    ans += tot * (n/(sz(cyc)));
    for(int i = 0; i < n%(sz(cyc)); ++i){
        ans += cyc[i];
    }
    cout << ans;
    return 0;
}