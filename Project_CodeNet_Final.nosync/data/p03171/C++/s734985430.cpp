#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MAXN = 5 + 3000;
ll memo[MAXN][MAXN][2];
int N;
int arr[MAXN];

ll dp(int i, int j, bool t) {
    if(i > j) return 0LL;
    ll& ans = memo[i][j][t];
    if(ans == -1) {
        if(t) {
            ans = max(arr[i] + dp(1 + i, j, !t), arr[j] + dp(i, j - 1, !t));
        } else {
            ans = min(dp(1 + i, j, !t) - arr[i], dp(i, j - 1, !t) - arr[j]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    foi(i,0,N) {
        cin >> arr[i];
    }
    memset(memo, -1, sizeof memo);
    cout << dp(0, N - 1, true) << '\n';
    return 0;
}
