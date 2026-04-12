#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <cstring>

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
typedef long long ll;
const ll MOD = (ll)1e9 + 7;
const int N = 1e4+5, inf = 1e9+5;
ll add(ll x, ll y) { x += y; if (x >= MOD) return x - MOD; return x; }
ll sub(ll x, ll y) { x -= y; if (x < 0) return x + MOD; return x; }
ll mult(ll x, ll y) { return (x * y) % MOD; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll dp[N][105][2];
int d;
string num;
ll f(int i, int mod, bool lower) {
    if (i == num.size()) return mod == 0;
    if (dp[i][mod][lower] != -1) return dp[i][mod][lower];

    ll ans = 0;
    for (int digit = 0; digit <= (lower ? 9 : num[i]-'0'); ++digit) {
        int need = ((mod-digit)%d+d)%d;
        ans = add(ans, f(i+1, need, lower || digit < num[i]-'0'));
    }
    return dp[i][mod][lower] = ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> num >> d;
    memset(dp, -1, sizeof(dp));
    cout << sub(f(0, 0, false), 1) << endl;
    return 0;
}