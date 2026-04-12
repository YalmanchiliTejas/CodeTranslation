// 7/1 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    // vector<int> tail;
    // rep(i, N) {
    //     if (tail.empty() || tail.top()) {
    //     }
    // }

    vector<int> dp(N, -1);
    rep(i, N) {
        int left = -1;  // A[i]より小さいギリギリ
        int right = N-1;  // A[i]より大きいギリギリ

        while (right - left > 1) {
            int mid = (left + right) / 2;
            // if (dp[mid] >= A[i]) right = mid;
            if (dp[mid] < A[i]) right = mid;
            else left = mid;
        }

        dp[right] = A[i];
    }

    int res = 0;
    rep(i, N) {
        if (dp[i] != -1) res++;
        // cout << dp[i] << endl;
    }

    cout << res << endl;
}