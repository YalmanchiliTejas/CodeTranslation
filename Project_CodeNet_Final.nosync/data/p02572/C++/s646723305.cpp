#include <bits/stdc++.h>

#include <vector>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

typedef long long ll;

const long long MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> Aj(N);
    rep(i, N) {
        cin >> A[i];
    }
    ll tot = 0;
    rep(i, N) {
        tot += A[N - i - 1];
        tot %= MOD;
        Aj[N - i - 1] = tot;
    }

    tot = 0;
    rep(i, N - 1) {
        tot += A[i] * Aj[i + 1];
        tot %= MOD;
    }
    cout << tot << endl;

    return 0;
}
