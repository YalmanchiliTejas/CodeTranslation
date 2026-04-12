#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


ll N, X;
vector<pair<ll, ll>> w;


ll solve(int i) {
    if (X == 0) return 0;
    if (i == 0) return 1;
    if (X == 1) return 0;
    X--;
    if (X <= w[i-1].first) return solve(i - 1);
    X -= w[i-1].first;
    if (X == 1) return w[i-1].second + 1;
    X--;
    if (X <= w[i-1].first) return w[i-1].second + 1 + solve(i - 1);
    return 2 * w[i-1].second + 1;
}


int main() {
    cin >> N >> X;
    w = vector<pair<ll, ll>>(N + 1);
    w[0] = make_pair(1, 1);
    for (int i = 1; i <= N; i++) {
        w[i].first = 2 * w[i-1].first + 3;
        w[i].second = 2 * w[i-1].second + 1;
    }
    ll ans = solve(N);
    cout << ans << endl;
}
