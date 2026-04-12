#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;
const int maxi = 3005;
ll dp[maxi][maxi]={0};


/**

dp[l][r] = max( arr[l] + dp[l-1][r] , arr[r] -dp[l][r-1] )

maximum of difference of if we choose left and the opponents choice or if we choose right  and opponents choice

dp[i][j] is storing the maximum difference for every j in arr.
so the answer will be dp[0][n-1]

**/


int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int l=n-1;l>=0;l--)
    {
        for(int r =l;r<n;r++)
        {
            if(l==r)
            {
                dp[l][r] =arr[l];
            }
            else
            {
                dp[l][r] = max(arr[l] - dp[l+1][r] , arr[r] - dp[l][r-1]);
            }
        }
    }
    cout<<dp[0][n-1];

}

