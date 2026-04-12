#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll rec(vector<ll>& a,vector<vector<ll>>& dp,int i,int j,int n) {
    if (dp[i][j] > INT64_MIN) return dp[i][j];
    if (i+j == n) return dp[i][j] = 0;
    if ((i+j)&1) return dp[i][j] = min(rec(a,dp,i+1,j,n)-a[i],rec(a,dp,i,j+1,n)-a[n-j-1]);
    else return dp[i][j] = max(rec(a,dp,i+1,j,n)+a[i],rec(a,dp,i,j+1,n)+a[n-j-1]);
}
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,INT64_MIN));
    for (int i = 0;i < n;++i) cin >> a[i];
    cout << rec(a,dp,0,0,n);
    return 0;
}