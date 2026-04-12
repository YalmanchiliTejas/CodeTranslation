#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
int n , a[N];
ll memo[N][3];
ll solve(int i , int f) {
    if(i >= n)
        return 0;
    ll &ans = memo[i][f];
    if(~ans)
        return ans;
    ans = -1e18;
    if(f < 2)
        ans = solve(i + 1 , f + 1);
    if(i != n - 1 || f)
        ans = max(ans , solve(i + 2 , f) + a[i]);
    return ans;
}
int main() {
    abdelrahman010
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(memo, -1, sizeof memo);
    if(n & 1)
        cout << solve(0, 0);
    else
        cout << solve(0 , 1);
    return 0;
}