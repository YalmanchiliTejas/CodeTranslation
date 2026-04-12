#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000008;

int main()
{
    int n;
    cin >> n;
    int a[100002];
    for(int i = n - 1; i >= 0; i--) cin >> a[i];
    int dp[100002];
    fill(dp, dp + n, INF);
    for(int i = 0; i < n; i++){
        *upper_bound(dp, dp + n, a[i]) = a[i];
    }
    cout << upper_bound(dp, dp + n, INF - 1) - dp << endl;
}