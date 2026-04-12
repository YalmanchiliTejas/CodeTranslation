#include<bits/stdc++.h>
#define int long long
#define INF 1e18
using namespace std;
int n,a[3001],dp[3001][3001];
int Dp_Rec(int L, int R)
{
    if(dp[L][R]) return dp[L][R];
    if(L == R) return dp[L][R] = a[L];
    if(L > R) return dp[L][R] = INF;
    return dp[L][R] = max(a[R] - Dp_Rec(L,R-1),a[L] - Dp_Rec(L+1,R));
}
main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    cout << Dp_Rec(1,n);
}