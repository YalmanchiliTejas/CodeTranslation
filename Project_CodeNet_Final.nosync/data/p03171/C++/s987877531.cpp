#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    vector<ll> a(n);
    vector< vector<ll> > dp(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        scanf("%lld", a.begin() + i);
        dp.at(i).at(i) = a.at(i);
    }
    for (ll i = 1; i < n; ++i) for (ll j = 0; j < n - i; ++j) {
        if (i % 2) dp.at(j).at(j + i) = min(dp.at(j + 1).at(j + i) - a.at(j), dp.at(j).at(j + i - 1) - a.at(j + i));
        else dp.at(j).at(j + i) = max(dp.at(j + 1).at(j + i) + a.at(j), dp.at(j).at(j + i - 1) + a.at(j + i));
    }
    printf("%lld\n", dp.at(0).back() * (n % 2 ? 1 : -1));
    return 0;
}
