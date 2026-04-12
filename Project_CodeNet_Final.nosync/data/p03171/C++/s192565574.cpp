#include<bits/stdc++.h>
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//const long double PI = 3.14159265358979323846;
//#pragma GCC optimize ("-O3")

int n;
vector<int> ar;
vector<vector<long long>> dp;

long long go(int l, int r)
{
    // base case
    if (l > r)
        return 0;
    if (dp[l][r]!= -1e18)
        return dp[l][r];
    // pick left
    long long ans;
    ans = max(ar[l] - go(l+1, r), ar[r] - go(l, r-1));
    return dp[l][r] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    ar.resize(n);
    dp = vector<vector<long long>> (n, vector<long long> (n, -1e18));
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    cout << go(0, n-1);
    return 0;
}