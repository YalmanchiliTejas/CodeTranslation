#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const N = 3e3 + 1;

int n;
int arr[N];

ll dp[N][N][2];
int vis[N][N][2];

ll pound(int left, int right, bool turn)
{
    if (left > right)
        return 0;
    
    if (vis[left][right][turn])
        return dp[left][right][turn];
    
    vis[left][right][turn] = 1;
    
    if (!turn)
        return dp[left][right][turn] = max(pound(left + 1, right, !turn) + arr[left], pound(left, right - 1, !turn) + arr[right]);
    return dp[left][right][turn] = min(pound(left + 1, right, !turn) - arr[left], pound(left, right - 1, !turn) - arr[right]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    cout << pound(0, n - 1, 0);
    
    return 0;
}