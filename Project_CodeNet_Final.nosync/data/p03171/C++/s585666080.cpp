#include <bits/stdc++.h>
using namespace std;
#define finish(x) reutrn cout << x << endl, 0;
#define ll long long

int n, x;
ll dp[3001][3001][2];
vector <int> a;

ll solve(int l, int r, int cur){
    if(r < l) return 0;
    ll &ret = dp[l][r][cur];
    if(ret != -1) return ret;
    if(cur == 0) return ret = max(solve(l + 1, r, cur ^ 1) + a[l], solve(l, r - 1, cur ^ 1) + a[r]);
    return ret = min(solve(l + 1, r, cur ^ 1) - a[l], solve(l, r - 1, cur ^ 1) - a[r]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0 ; i < n && cin >> x ; i++)
        a.push_back(x);
    cout << solve(0, n - 1, 0) << endl;
}
