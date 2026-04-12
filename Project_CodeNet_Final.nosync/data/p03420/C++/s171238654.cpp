#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    ll ans = 0;
    for (int k = K + 1; k <= N; k++) {
        ans += ((N + 1) / k) * (k - K);
        if (((N + 1) % k) - K > 0)
            ans += (N + 1) % k - K;
    }

    if (K == 0)
        ans -= N;

    cout << ans << endl;
}