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

void testCase() {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> arr[i];
    ll dp[n+2][n+2];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++)
            dp[i][j] = 0;
        dp[i][i] = arr[i];
    }    
    for (int len=1; len<n; len++) {
        int i=1;
        int j=i+len;
        while (j<=n) {
            dp[i][j] = max (arr[i]-dp[i+1][j], arr[j]-dp[i][j-1]);
            i++;
            j++;
        }
    }
    cout << dp[1][n] << endl;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}