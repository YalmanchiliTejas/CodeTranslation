#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define fastio std::ios::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int, int>
#define pll pair<ll , ll>
#define mpi make_pair
#define F first
#define S second
#define pb push_back
#define N 200005
#define INF 1000000000000000

ll dp[3005][3005];


int main()
{   
    fastio
    
    int n;cin>>n;
    vector< ll> arr(n);
    for(int i = 0 ;i<n;i++)
    {
        cin>>arr[i];
        dp[i][i] = arr[i];
    }

    vector<ll> psum(n+1,0);

    for(int i = 1 ; i<=n;i++)
    {
        psum[i] = psum[i-1] + arr[i-1];
    }

    for(int k = 2;k<=n;k++)
    {
        for(int i =0;i+k<=n;i++)
        {
            int j = i+k-1;

            dp[i][j] = psum[j+1]-psum[i]-min(dp[i+1][j] , dp[i][j-1]);


        }
    }
    
    ll ans = 2*dp[0][n-1] - psum[n];\

    cout<<ans<<endl;
    return 0;
} 