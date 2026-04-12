#include<bits/stdc++.h>
using namespace std;
#define N 3005
#define ll long long
ll dp[N][N], n, arr[N];

ll cal(int i, int j)
{
    if(j < i) return 0;
    if(dp[i][j] != -1) return -dp[i][j];
    dp[i][j] = max(arr[i] + cal(i + 1, j), arr[j] + cal(i, j - 1));
    return -dp[i][j];
}



int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    cout << -cal(1, n) << endl;
}
