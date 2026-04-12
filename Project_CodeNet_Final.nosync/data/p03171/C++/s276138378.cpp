#include <iostream>
#define int long long
using namespace std;
int F[3005][3005],i,j,n,m,A[3005];
bool cal[3005][3005];
int dp(int i, int j)
{
    int res;
    if ((n - j + i -1) % 2 == 0) res=1; else res=-1;
    if (i >= j)
    {
        if (i == j) return A[i]*res;
        else return 0;
    }
    if (cal[i][j]) return F[i][j];
    if (res==1) {
        F[i][j]=max(dp(i+1,j) + A[i] , dp(i,j-1) + A[j]);
    } else {
        F[i][j]=min(dp(i+1,j) - A[i] , dp(i,j-1) - A[j]);
    }
    cal[i][j]=true;
    return F[i][j];
}
signed main()
{
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> A[i];
    }
    cout << dp(1,n);
    return 0;
}
