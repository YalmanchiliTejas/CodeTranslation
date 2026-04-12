#include<iostream>
using namespace std;

const int MAX_N = 1e5 + 1;
const int INF = 1 << 30;

int A[MAX_N];
int dp[MAX_N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) dp[i] = -INF;
    for (int i = 0; i < N; ++i) {
        int l = -1, r = N - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (dp[mid] < A[i]) r = mid;
            else l = mid;
        }
        dp[r] = A[i];
    }
    for (int i = N - 1; i >= 0; --i) {
        if (dp[i] == -INF) continue;
        cout << i + 1 << endl;
        return 0;
    }
    return 0;
}