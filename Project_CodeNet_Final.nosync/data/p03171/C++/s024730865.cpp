#include <iostream>
using namespace std;
typedef long long ll;

ll a[3002];
ll dp[3002][3002];

ll rec(int l, int r, bool f){
    if(r < l) return 0;
    ll left, right;
    if(dp[l + 1][r]) left = dp[l + 1][r];
    else left = dp[l + 1][r] = rec(l + 1, r, !f);
    if(dp[l][r - 1]) right = dp[l][r - 1];
    else right = dp[l][r - 1] = rec(l, r - 1, !f);
    if(f) return max(right + a[r], left + a[l]);
    else return min(right - a[r], left - a[l]);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << rec(0, n - 1, true) << endl;
}