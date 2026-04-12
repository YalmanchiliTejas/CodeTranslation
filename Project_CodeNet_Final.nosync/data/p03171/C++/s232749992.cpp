#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define int long long
#define pii pair<int, int>

const int N = 3005;

int dp[N][N], a[N];
int n;

int solve(int beg, int end) {     // maximum difference you get for [beg, end]
    if(beg == end)
        return dp[beg][end] = a[beg];
    if(dp[beg][end] != -1)
        return dp[beg][end];
    dp[beg][end] = max(a[beg] - solve(beg+1, end), a[end] - solve(beg, end-1));
    return dp[beg][end];
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i;
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for(i = 1 ; i <= n ; i++)
        cin >> a[i];
    cout << solve(1, n) << endl;
    return 0;
}
