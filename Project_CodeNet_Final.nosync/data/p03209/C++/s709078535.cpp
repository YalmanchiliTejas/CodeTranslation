#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

ll pub_count[60];
ll patty_count[60];

void init_count(ll N) {
    for (int i = 0; i <= N; ++i) {
        pub_count[i] = -3 + 4 * pow(2, i);
        patty_count[i + 1] = patty_count[i] * 2 + 1;
    }
}

ll solve(ll N, ll X) {
    if (N == 0)
        return (X <= 0 ? 0 : 1);
    else if (X <= 1 + pub_count[N - 1]) return solve(N - 1, X - 1);
    else return 1 + patty_count[N - 1] + solve(N - 1, X - 2 - pub_count[N - 1]);
}

int main() {
    ll N, X; cin >> N >> X;
    patty_count[0] = 1;
    init_count(N);
    cout << solve(N, X) << endl;
}