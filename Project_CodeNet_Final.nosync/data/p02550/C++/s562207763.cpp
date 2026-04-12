#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, ans;
int x, m, dist[100005], p[100005];
ll memo[100005];

ll dp(ll _x, ll prev, ll _n){
    if (_n == 0) return 0;
    if (dist[_x] != -1){
        int cycle_size = dist[prev] - dist[_x] + 1;
        ll cycle_weight = memo[prev] - memo[p[_x]];
        ll tmp = _n / cycle_size * cycle_weight;
        _n %= cycle_size;
        while (_n != 0){
            tmp += _x;
            _x = (_x * _x) % m;
            --_n;
        }
        return tmp;
    }
    else{
        dist[_x] = dist[prev] + 1;
        memo[_x] = memo[prev] + _x;
        p[_x] = prev;
        ll nx = (_x * _x) % m;
        ll tmp = _x + dp(nx, _x, --_n);
        //printf("%lld %lld %lld\n", tmp, memo[_x], _x);
        return tmp;
    }
}

int main(){
    scanf("%lld", &n);
    scanf("%d%d", &x, &m);
    memset(memo, -1, sizeof memo);
    memset(dist, -1, sizeof dist);
    memset(p, -1, sizeof p);
    memo[m] = 0;
    p[x] = m;
    ll ans = dp(x, m, n);
    cout<<ans;
}

