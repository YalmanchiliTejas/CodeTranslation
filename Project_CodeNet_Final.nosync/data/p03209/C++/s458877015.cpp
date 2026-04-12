#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> d, p;

ll solve(ll n, ll x) {
    if (n == 0) return 1;
    if (x == 1) return 0;
    if (x <= d.at(n - 1) + 1) return solve(n - 1, x - 1);
    if (x == d.at(n - 1) + 2) return p.at(n - 1) + 1;
    if (x <= d.at(n - 1) * 2 + 2) return solve(n - 1, x - d.at(n - 1) - 2) + p.at(n - 1) + 1;
    return p.at(n - 1) * 2 + 1;
}

int main() {
    ll n, x;
    scanf("%lld%lld", &n, &x);
    d.resize(n + 1), p.resize(n + 1);
    d.at(0) = 1, p.at(0) = 1;
    for (ll i = 0; i < n; ++i) d.at(i + 1) = 2 * d.at(i) + 3, p.at(i + 1) = 2 * p.at(i) + 1;
    printf("%lld\n", solve(n, x));
    return 0;
}
