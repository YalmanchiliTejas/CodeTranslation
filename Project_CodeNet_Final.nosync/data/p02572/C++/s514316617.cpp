#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const long long MOD = 1000000007;

void solve(long long N, std::vector<long long> A) {
    std::vector<long long> B(N);
    for (int i = N - 2; 0 <= i; i--) {
        B[i] = B[i + 1] + A[i + 1];
        B[i] %= MOD;
    }
    long long ans = 0;
    rep (i, N) {
        ans += A[i] * B[i];
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
