#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;
const long double EPS = 1e-10;
const int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

ll fact[200001], rfact[200001];

ll perm(ll n, ll r){
    return (fact[n] * rfact[r]) % MOD;
}

ll comb(ll n, ll r){
    return (perm(n, r) * rfact[n-r]) % MOD;
}

void init(ll n){
    fact[0] = fact[1] = 1;
    rfact[0] = rfact[1] = 1;
    for(int i=2;i<=n;++i) {
        fact[i] = (fact[i-1] * (ll)i) % MOD;
        rfact[i] = 1;
        ll k = MOD-2;
        ll a = fact[i];
        while(k > 0){
            if(k & 1){
                rfact[i] *= a;
                rfact[i] %= MOD;
            }
            a *= a;
            a %= MOD;
            k  >>= 1;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;

    init(n*m);

    ll ans_x = 0;
    for(ll l=1;l<n;++l) {
        ans_x += l * (n-l) * m * m;
    }
    ll ans_y = 0;
    for(ll l=1;l<m;++l) {
        ans_y += l * (m-l) * n * n;
    }

    ll c = comb(n*m-2, k-2);
    cout << (c * ((ans_x+ans_y)%MOD))%MOD << endl;
}
