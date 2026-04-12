#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;

const int MAX_N = 3*1e3 + 100;
const i64 NaN = 1e16;
//(l,r)=> 前からl個, 後ろからr個が無い時の最適X-Y
i64 dp[MAX_N][MAX_N];
int N;
vector<i64> a;
i64 recursive(int l, int r) {
    if(dp[l][r] != NaN) return dp[l][r];
    if(l + r >= N) return 0;
    i64 L = recursive(l + 1, r), R = recursive(l, r + 1);
    if( (l + r) % 2 == 0 ) { // 太郎
        dp[l][r] = max(L + a[l], R + a[N - 1 - r]);
    } else { // 次郎
        dp[l][r] = min(L - a[l], R - a[N - 1 - r]);
    }
    return dp[l][r];
}
int main() {
    cin >> N;
    a = vector<i64>(N);
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            dp[i][j] = NaN;
        }
    }
    for(auto &x : a) cin >> x;
    cout << recursive(0, 0) << endl;
    return 0;
}