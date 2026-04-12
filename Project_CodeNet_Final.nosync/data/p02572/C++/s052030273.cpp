#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N; cin >> N;
    vl A(N);
    vl sum(N);
    rep(i, N) {
        cin >> A[i];
        sum[i] = A[i];
    }
    const ll MOD = 1000000007;

    reverse(sum.begin(), sum.end());
    rep(i, N - 1) {
        sum[i + 1] += sum[i];
        sum[i + 1] %= MOD;
    }
    reverse(sum.begin(), sum.end());

    ll res = 0;
    rep(i, N - 1) {
        ll x = A[i] * sum[i + 1] % MOD;
        res += x;
        res %= MOD;
// cout << "i: " << i << ", A[i]: " << A[i] << ", sum[i + 1]: " << sum[i + 1] << ", res " << res << endl;
    }

    cout << res << endl;
}
