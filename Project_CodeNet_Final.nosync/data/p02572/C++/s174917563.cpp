#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <map>

using namespace std;
constexpr int64_t MOD = 1'000'000'007;

int64_t mod_inv(int64_t a) {
    int64_t b = MOD, u = 1, v = 0;
    while (b) {
        int64_t t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

int main(void) {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    int64_t sum = accumulate(A.begin(), A.end(), 0L) % MOD;
    int64_t ans = sum * sum % MOD;

    for(int i=0; i<N; i++) {
        ans -= A[i] * A[i];
        ans %= MOD;
    }

    ans *= mod_inv(2);
    ans %= MOD;
    if(ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}
