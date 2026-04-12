#include<bits/stdc++.h>
using namespace std;

int n = 3000;
long long arr[3000];
long long dp[3001][3001];
bool sht[3001][3001];

long long rec(int l, int r)
{
    if (sht[l][r]) return dp[l][r];
    sht[l][r] = 1;
    
    if (r == l) return dp[l][r] = 0;
    
    if ((r ^ l ^ n) & 1)
        return dp[l][r] = min(rec(l + 1, r) - arr[l], rec(l, r - 1) - arr[r - 1]);
    else
        return dp[l][r] = max(rec(l + 1, r) + arr[l], rec(l, r - 1) + arr[r - 1]);
}

int main()
{
    cin >> n;
    for (int i = 0; i != n; ++i) scanf("%d", &arr[i]);
    
    cout << rec(0, n);
    
    return 0;
}