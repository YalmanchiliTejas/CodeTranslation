#include <bits/stdc++.h>
using namespace std;
long long int n, S;
long long int  a[3030], dp[3030][3030];
long long int solve(int i, int j){

    if(dp[i][j] != -1)
        return dp[i][j];

    if(i > j)
        return 0LL;

    return dp[i][j] = max(a[i] + min(solve(i + 2, j), solve(i + 1, j - 1)),
                          a[j] + min(solve(i + 1, j - 1), solve(i, j - 2)));
}
int main(){
    //freopen("test.in", "r+", stdin);
    memset(dp, -1, sizeof dp);

    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i], S += a[i];
    cout<<2 * solve(0, n - 1) - S<<endl;
}
