#include <bits/stdc++.h>
#define int long long int
using namespace std;
int DP[3001][3001] = {0};
signed main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                DP[i][j] = a[j];
                continue;
            }
            else
            {
                DP[i][j] = max(a[i]-DP[i+1][j],a[j]-DP[i][j-1]);
            }
        }
    }
    cout<<DP[0][n-1];
    return 0;
}