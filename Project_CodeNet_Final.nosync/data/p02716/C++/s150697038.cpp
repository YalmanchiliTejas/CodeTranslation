#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = n - 1; i >= 0; --i)

const ll NG = numeric_limits<ll>::min();

ll n;
vector<ll> a;

map<pair<ll, ll>, ll> cache;
ll solve(ll pos, ll num){
    assert(num >= 0);
    if(num == 0){
        return 0;
    }else if(n - pos < 2 * num - 1){
        return NG;
    }

    if(cache.count({pos, num})){
        return cache.at({pos, num});
    }

    ll tmp1 = solve(pos + 2, num - 1);
    if(tmp1 != NG){
        tmp1 += a.at(pos);
    }

    ll tmp2 = solve(pos + 1, num);

    const ll ans = max(tmp1, tmp2);
    cache[{pos, num}] = ans;
    return ans;
}

int main(){
    cin >> n;
    a.resize(n);

    REP(i, n){
        cin >> a.at(i);
    }

    cout << solve(0, n / 2) << endl;
    return 0;
}
