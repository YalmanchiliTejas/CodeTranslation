#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll =long long;
#define mINF -1000000000000000

int main()
{
    int N;cin>> N;
    vector<ll> A(N+1);
    for (int i=0;i<N;i++) cin >> A[i];
    ll dp[N+1][3][2];
    for (int i=0;i<N+1;i++)
        for (int j=0;j<3;j++) 
            for (int k=0;k<2;k++) dp[i][j][k]=mINF;
    dp[0][1][0]=0;
    dp[0][1][1]=0;
    for (int i=1;i<N+1;i++)
    {
        if ((i-1)%2==0)
        {
        dp[i][0][0]=max(dp[i-1][0][1],dp[i-1][0][0]);
        dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][1][1]);
        dp[i][1][1]=dp[i-1][0][0]+A[i-1];
        dp[i][2][0]=dp[i-1][2][1];
        dp[i][2][1]=dp[i-1][1][0]+A[i-1];
        }
        else
        {
        dp[i][0][0]=max(dp[i-1][1][1],dp[i-1][1][0]);
        dp[i][0][1]=dp[i-1][0][0]+A[i-1];
        dp[i][1][0]=max(dp[i-1][2][0],dp[i-1][2][1]);
        dp[i][1][1]=dp[i-1][1][0]+A[i-1];
        dp[i][2][1]=dp[i-1][2][0]+A[i-1];
        }
    }
    cout << max(dp[N][1][0],dp[N][1][1]) << endl;
return 0;

}