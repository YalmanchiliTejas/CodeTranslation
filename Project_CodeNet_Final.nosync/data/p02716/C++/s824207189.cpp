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

    vll a(n);
    rep(i, 0, n) { cin >> a[i]; }

    if (n % 2 == 0) {
        ll left = 0, right = 0;

        rep(i, 0, n / 2) {
            right = max(left, right) + a[2 * i + 1];
            left = left + a[2 * i];
        }
        cout << max(right, left) << endl;
        return 0;
    }

    ll left = 0, mid = 0, right = 0;
    rep(i, 0, n / 2) {
        right = max(left, max(mid, right)) + a[2 * i + 2];
        mid = max(left, mid) + a[2 * i + 1];
        left = left + a[2 * i];
    }
    cout << max(left, max(mid, right)) << endl;

    return 0;
}