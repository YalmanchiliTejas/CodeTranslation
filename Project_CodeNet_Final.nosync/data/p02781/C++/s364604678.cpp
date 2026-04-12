#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

ll choose(ll n, ll k){
    ll ret = 1;
    REP(i, k){
        ret *= (n - i);
    }
    REP(i, k){
        ret /= (i + 1);
    }
    return ret;
}

ll pow(ll x, ll y){
    if(y == 0){
        return 1;
    }else{
        return x * pow(x, y - 1);
    }
}

ll solve(const string& n, ll k, ll pos, ll state){
    const ll nd = n.size() - pos;
    if(k > 0 && nd == 0){
        return 0;
    }
    if(k == 0){
        return 1;
    }
    if(state == 1){
        return choose(nd, k) * pow(9, k);
    }
    assert(state == 0);
    const ll d = static_cast<ll>(n.at(pos) - '0');
    ll ret = 0;
    if(d > 0){
        ret += solve(n, k - 1, pos + 1, 0); // ちょうど d
    }
    if(d > 1){
        ret += (d - 1 ) * solve(n, k - 1, pos + 1, 1); // 0 より大きく d より小さい
    }
    ret += solve(n, k, pos + 1, d > 0); // ちょうど 0
    return ret;
}

int main(){
    string n;
    cin >> n;
    ll k;
    cin >> k;

    ll ans = solve(n, k, 0, 0);
    cout << ans << endl;
    return 0;
}
