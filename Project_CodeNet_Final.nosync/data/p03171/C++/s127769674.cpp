#include <bits/stdc++.h>
#include <cstring>
#include <map>
#include <set>
#define int long long int
using namespace std;


signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    #endif

    int n, i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int low=n-1;low>=0;low--){
        for(int high=low;high<n;high++){
            if(low==high)
                dp[low][high] = a[low];
            else
                dp[low][high] = max(a[low]-dp[low+1][high], a[high]-dp[low][high-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}


