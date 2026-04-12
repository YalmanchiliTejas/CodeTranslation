#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define fi first
#define se second 
#define mp make_pair
#define int long long
int dp[3005][3005];
signed main()
{
    IOS
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int L = n-1;L >=0 ;L--)
    {
      for(int R = L;R < n;R++)
      {
        if(L == R) dp[L][R] = arr[L];
        else dp[L][R] = max(arr[L] - dp[L+1][R],arr[R] - dp[L][R-1]);
      }
    }
    cout<<dp[0][n-1];
    return 0;
}