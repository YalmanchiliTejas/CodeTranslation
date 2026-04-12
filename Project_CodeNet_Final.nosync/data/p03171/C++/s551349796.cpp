#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
#define endl "\n"
int n;
int arr[3005];
ll dp[3005][3005];

ll go (int i, int j) {
    if (i > j)
        return 0;
    if (i == j)
        return arr[i];
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans = 0;
    ans = max (arr[i]-go(i+1, j), arr[j]-go(i, j-1));
    dp[i][j] = ans;
    return ans;
}

void testCase() {
    cin >> n;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++)
            dp[i][j] = -1;
    }
    for (int i=1; i<=n; i++)
        cin >> arr[i];
    cout << go (1, n) << endl;    
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}