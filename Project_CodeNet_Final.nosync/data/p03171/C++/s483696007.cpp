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

int main() {    
    // ifstream cin("tst.in");
    // ofstream cout("tst.out");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;  
    for (int i = 1; i <= n; i++)
        cin >> a[i], dp[i] = a[i] + dp[i - 1]; 

    for (int i = 1; i <= n; i++)
        memo[i][i] = a[i];

    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int st = i;
            int dr = i + len - 1;
            memo[st][dr] = max(a[st] + getsum(st + 1, dr) - memo[st + 1][dr], a[dr] + getsum(st, dr - 1) - memo[st][dr - 1]);
        }

    cout << 2 * memo[1][n] - getsum(1, n);

    return 0;
}