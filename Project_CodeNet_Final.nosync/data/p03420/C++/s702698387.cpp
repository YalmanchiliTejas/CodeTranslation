#include <bits/stdc++.h>

#define VARNAME(x) #x
#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;
using ld = long double;

constexpr ll MOD = 1000000007LL;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 10;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for (ll b = K + 1; b <= N; b++) {
        for (ll c = 0; c + K <= N; c += b) {
            ans += min(c + b - 1, N) - (c + K) + 1;
        }
    }
    if (K == 0) {
        ans -= N;
    }
    cout << ans << endl;
    return 0;
}
