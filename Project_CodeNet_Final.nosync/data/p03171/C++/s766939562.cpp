#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int64 long long

vector<vector<int64>> dp;
vector<vector<bool>> vis;

int64 solve(vector<int64> &vec, int l, int r){
    if (vis[l][r])
        return dp[l][r];
    if (l==r)
        return dp[l][r] = vec[l];

    vis[l][r] = true;
    int64 a = vec[l] - solve(vec, l+1, r);
    int64 b = vec[r] - solve(vec, l, r-1);

    return dp[l][r] = max(a, b);
}

signed main() {
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int64> vec(n);

    for (int i=0; i<n; i++)
        cin >> vec[i];
    

    dp.resize(n, vector<int64>(n, 0));
    vis.resize(n, vector<bool>(n, false));

    cout << solve(vec, 0, n-1);

    return 0;
}