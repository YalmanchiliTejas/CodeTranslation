#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

ll num_of_patty_for(const int n) {
    if (n == 1) return 3LL;
    else return num_of_patty_for(n - 1) * 2LL + 1LL;
}

ll size_of_hamburger_for(const int n) {
    static map<int, ll> memo;
    if (memo.find(n) != memo.end()) {
        return memo[n]; 
    }

    if (n == 1) {
        return 5LL;
    } else {
        ll ans = size_of_hamburger_for(n - 1) * 2LL + 3LL;
        memo[n] = ans;
        return ans;
    }
}

static map<pair<int, ll>, ll> memo;

ll solve(const ll n, ll x) {
    ll res = 0;

    const ll ham_size = size_of_hamburger_for(n);

    if (x > ham_size) {
        x = ham_size;
    }

    if (memo.find({n, x}) != memo.end()) {
        return memo[{n, x}];
    }

    // printf("n: %lld, x: %lld\n", n, x);

    if (n == 1) {
        assert(x >= 1 && x <= 5);
        vector<ll> tmp = {0LL, 0LL, 1LL, 2LL, 3LL, 3LL};
        return tmp[x];
    }

    if (x == 1) {
        return 0LL;
    }

    if (x == (ham_size - 3) / 2 + 2) {
        // at the center
        res++;
        res += solve(n - 1, x - 2); // x - 2 will be fixed later
    } else if (2 * x > ham_size) {
        // left
        res++;
        res += solve(n - 1, x - 2); // x - 2 will be fixed later
        res += solve(n - 1, x - ((ham_size + 2 - 1) / 2));
    } else {
        // right
        res += solve(n - 1, x - 1);
    }

    memo[{n, x}] = res;
    return res;
}

int main(void) {
    ll N, X;
    cin >> N >> X;

    cout << solve(N, X) << endl;

    return 0;
}
