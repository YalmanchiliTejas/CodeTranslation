#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

const int inf = 1e17;
const int Max = 3010;
int arr[Max];
int memo[Max][Max];
int solve(int l, int r, bool First) {//inclusive, inclusive
    if(l > r) return 0;
    if(memo[l][r] != inf) return memo[l][r];
    if(First) {
        return memo[l][r] = max(arr[l] + solve(l+1,r, !First), arr[r] + solve(l,r-1,!First));
    }
    return memo[l][r] = min(-arr[l] + solve(l+1,r,!First), -arr[r] + solve(l,r-1,!First));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        for(int j = 0; j < n; ++j) {
            memo[i][j] = inf;
        }
    }
    cout << solve(0, n-1, true) << '\n';
    return 0;
}
























