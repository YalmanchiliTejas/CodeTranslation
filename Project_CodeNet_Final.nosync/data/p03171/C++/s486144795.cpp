// #pragma GCC optimize("03")
#include <bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define mod 1000000007

using namespace std;

int n;
ll memo[3010][3010]; 
ll dp[3010];     
ll a[3010];
ll s;

ll getsum(int l, int r) {
    return dp[r] - dp[l - 1];
}

ll solve(int l, int r) {
    if (l == r)
        return a[l];
    if (memo[l][r] != 0)
        return memo[l][r];
    
    return memo[l][r] = max(a[l] + getsum(l + 1, r) - solve(l + 1, r), a[r] + getsum(l, r - 1) - solve(l, r - 1));
}

int main() {    
    // ifstream cin("tst.in");
    // ofstream cout("tst.out");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;  
    for (int i = 1; i <= n; i++)
        cin >> a[i], dp[i] = a[i] + dp[i - 1]; 

    cout << 2 * solve(1, n) - getsum(1, n);
    return 0;
}