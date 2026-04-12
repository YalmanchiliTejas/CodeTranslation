#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int64_t> A(n);
    copy_n(istream_iterator<int64_t>(cin), n, A.begin());

    vector<map<int, int64_t>> DP(n + 2);
    DP[0][0] = 0;
    const constexpr int64_t INF = 1e17;
    vector<int> B(n);
    for (int i = 0; i < n; i++){
        B[i] = n / 2 - (n - i + 1) / 2;
    }

    for (int i = 0; i < n; i++){
        for (const auto &[k, v]: DP[i]){
            if (k < B[i])
                continue;
            if (DP[i + 1].count(k) == 0)
                DP[i + 1][k] = -INF;
            DP[i + 1][k] = max(DP[i + 1][k], DP[i][k]);
            if (DP[i + 2].count(k + 1) == 0)
                DP[i + 2][k + 1] = -INF;
            DP[i + 2][k + 1] = max(DP[i + 2][k + 1], DP[i][k] + A[i]);
        }
    }

    int64_t ans = -INF;
    for (int i = 0; i <= n + 1; i++){
        if (DP[i].count(n / 2) != 0)
            ans = max(ans, DP[i][n / 2]);
    }
    cout << ans << endl;
}
