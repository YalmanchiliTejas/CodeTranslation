#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n) { cin >> a[i]; }

    vi dp(n, INT_MAX);
    rep(i, 0, n) { dp[distance(dp.begin(), upper_bound(all(dp), -a[i]))] = -a[i]; }
    cout << distance(dp.begin(), lower_bound(all(dp), INT_MAX)) << endl;

    return 0;
}