#include <bits/stdc++.h>

#define REP(i, n) for(decltype(n) i = 0; i < n; i++)

#define ALL(c)   c.begin(), c.end()
#define SORT(c)  std::sort(ALL(c))
#define RSORT(c) std::sort(ALL(c), std::greater<decltype(c)::value_type>())

using namespace std;
using ll = long long;

const int MOD  = (int)1e9 + 7;
const int INF  = (int)1e9 + 1;
const ll  LINF = (ll)1e18 + 1;

ll solve(ll N, ll X,
         const vector<ll>& a,
         const vector<ll>& p) {
    if(N == 0) {
        return (X <= 0) ? 0 : 1;
    }
    else if(X <= 1 + a[N - 1]) {
        return solve(N - 1, X - 1, a, p);
    }
    else {
        return p[N - 1] + 1 + solve(N - 1, X - 2 - a[N - 1], a, p);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X;
    std::cin >> N >> X;

    vector<ll> a(1, 1), p(1, 1);
    REP(i, N) {
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1);
    }

    std::cout << solve(N, X, a, p) << std::endl;

    return 0;
}
