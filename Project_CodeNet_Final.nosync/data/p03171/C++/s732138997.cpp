#include <iostream>
#include <cmath>

using namespace std;

const int maxn=3e3+10;

int a[maxn];

long long int dp[maxn][maxn];

int main()
{
    int n;

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++)
    {
        dp[i][i]=a[i];
     //   cout<<dp[i][i]<<" ";
    }
    for(int l=1;l<n;l++)
    {
        for(int r=l-1;r>=0;r--)
        {

            dp[r][l]=max(a[l]-dp[r][l-1],a[r]-dp[r+1][l]);
           // cout<<dp[r][l]<<" ";
        }
    }
    cout<<dp[0][n-1];
	return 0;
}

