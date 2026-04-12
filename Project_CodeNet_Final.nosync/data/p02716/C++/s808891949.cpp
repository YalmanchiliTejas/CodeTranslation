//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

//----------------------- Print Function ----------------------//

inline void print() {
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}

template <typename T>
void print(const vector<T> &v) {
    for (auto e : v) cout << e << ' ';
    cout << endl;
}

//------------------------- Libraries -------------------------//

//--------------------------- Solve ---------------------------//

void solve() {
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<long long> dp(N+1);
    long long sum3 = 0;
    for (int i = 2; i <= N; i++) {
        if (i&1) {
            long long sum1 = dp[i-2] + A[i-1];
            long long sum2 = dp[i-3] + A[i-2];
            sum3 += A[i-3];
            dp[i] = max(sum1, max(sum2, sum3));
        }
        else {
            long long sum1 = dp[i-2] + A[i-1];
            long long sum2 = sum3 + A[i-2];
            dp[i] = max(sum1, sum2);
        }
        
    }

    cout << dp[N] << '\n';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}