#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

ll burgerN(ll n, ll x, vector<ll>& ps, vector<ll>& ls) {


    if (n == 0) return 1;
    if (x <= 1) return 0;



    if (x <= (ls[n-1] + 1)) {
        return burgerN(n-1, x-1, ps, ls);
    } else if (x == (ls[n-1] + 2)) {
        return ps[n-1] + 1;
    } else if (x <= (2 + 2 * ls[n-1])) {
        return ps[n-1] + 1 + burgerN(n-1, x-ls[n-1]-2, ps, ls);
    } else {
        return 2 * ps[n-1] + 1;
    }

    return 0;
    
}

int main() {
    ll N, X;
    cin >> N >> X;

    vector<ll> p_nums = {1};
    vector<ll> layer_nums = {1};

    for (ll i=0; i<=N; i++) {
        p_nums.emplace_back(p_nums[i]*2+1);
        layer_nums.emplace_back(layer_nums[i]*2+3);
    }

    ll res = burgerN(N, X, p_nums, layer_nums);
    cout << res << endl;

    return 0;
}