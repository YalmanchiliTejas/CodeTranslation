#include <iostream>

using namespace std;

long long int a[3005], dp[3005][3005][2];

//dp[l][r][p] = optimal value of (X-Y) when array is from l to r and
//it is players p's turn
long long int solve(int l, int r, int p)
{
    if(dp[l][r][p] != (long long int)(1e15))
        return(dp[l][r][p]);
    if(l == r)
    {
        if(p == 1) return(-a[l]);
        return(a[l]);
    }
    if(p == 0)
        dp[l][r][p] = max(a[l]+solve(l+1, r, 1-p), a[r]+solve(l, r-1, 1-p));
    else
        dp[l][r][p] = min(-a[l]+solve(l+1, r, 1-p), -a[r]+solve(l, r-1, 1-p));
    return(dp[l][r][p]);
}

int main()
{
    int n;
    long long int ans;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j][0] = dp[i][j][1] = (long long int)(1e15);
    ans = solve(0, n-1, 0);
    cout << ans << endl;
    return(0);
}