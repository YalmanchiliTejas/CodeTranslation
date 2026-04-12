#include<bits/stdc++.h>
#define REP(i, a, b) for(long long i=a; i<=b; ++i)
#define REPN(i, a, b) for(long long i=a; i<=b; --i)
#define rep(i, a, b) for(long long i=a; i<b; ++i)
#define rep0(i,b) for(long long i=0; i<b; ++i)
#define REP0(i,b) for(long long i=0; i<=b; ++i)
#include<cmath>
#include <iomanip>
using namespace std;


typedef long long ll;



int main()
{
    int n;
    cin>>n;
    ll arr[n];
    rep0(i, n)
    {
        cin>>arr[i];
    }

    ll dp[n][n];

    memset(dp, 0, sizeof(dp));
    rep0(i, n)
    {
        dp[i][i] = arr[i];

    }


    for(int i=n-2; i>=0; --i)
    {

        for(int j=i+1; j<n; ++j)
        {

            dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
        }

    }




    cout<<dp[0][n-1]<<endl;



    return 0;

}
