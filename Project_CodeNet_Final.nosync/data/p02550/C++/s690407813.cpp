#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    ll N, X, M; cin >> N >> X >> M;

    ll A = X;
    int s = -1, t = -1;
    vector<ll> sums(M + 1, 0);
    vector<int> index(M + 1, -1);
    REP(i, 0, M + 1) {
        // cout << "# i : " << i << ", A : " << A << endl;
        if (index[A] != -1) {
            s = index[A];
            t = i - 1;
            break;
        }
        index[A] = i;
        // cout << "DEBUG : sums[i] : " << sums[i] << ", prev : " << ((i > 0) ? sums[i - 1] : 0)  << endl;
        sums[i] += A + ((i > 0) ? sums[i - 1] : 0);
        A = A * A % M;
        // cout << "--> sum : " << sums[i] << endl;
    }

    // cout << "# loop : " << s << " " << t << endl;

    ll loop_sum = 0;
    if (s != -1) {
        loop_sum = sums[t] - ((s > 0) ? sums[s - 1] : 0);
    }

    ll ans = 0;
    ans += ((min((ll)s - 1, N - 1) >= 0) ? sums[min((ll)s - 1, N - 1)] : 0);
    // cout << "before loop : " << ans << endl;
    N -= s;
    if (N > 0) {
        ans += N / (t - s + 1) * loop_sum;
        if (N % (t - s + 1) != 0) ans += sums[s + N % (t - s + 1) - 1] - ((s - 1) >= 0 ? sums[s - 1] : 0);
    }
    cout << ans << endl;

    return 0;
}