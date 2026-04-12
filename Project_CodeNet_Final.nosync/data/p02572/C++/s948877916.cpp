#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#if !defined(M_PI)
#define M_E 2.71828182845904523536
#define M_LOG2E 1.44269504088896340736
#define M_LOG10E 0.434294481903251827651
#define M_LN2 0.693147180559945309417
#define M_LN10 2.30258509299404568402
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.785398163397448309616
#define M_1_PI 0.318309886183790671538
#define M_2_PI 0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2 1.41421356237309504880
#define M_SQRT1_2 0.707106781186547524401
#endif

int solve() {
    int q = 1000000007;

    int n;
    cin >> n;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> sfx_sum(n, 0);
    sfx_sum[n - 1] = a[n - 1];

    for (int i = n - 1 - 1; i >= 0; i--) {
        sfx_sum[i] = (sfx_sum[i + 1] + a[i]) % q;
    }

    ll ans = 0;

    for (int i = 0; i < n - 1; i++) {
        ans = (ans + (a[i]*sfx_sum[i + 1]) % q) % q;
    }
    return ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    // cin >> tt;

    for (int tc = 1; tc <= tt; tc++) {
        cout << solve() << "\n";
    }
}
