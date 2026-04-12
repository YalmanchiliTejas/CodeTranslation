#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int,int>
#define fr(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define nl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int dp[3001][3001];
int arr[3001];
int n;

int solve(int l , int r)
{
    if(r-l+1 == 1) return arr[l];
    if(r-l+1 == 2) return max(arr[l] , arr[r]);

    if(dp[l][r] != -1)return dp[l][r];

    int A = arr[l] + min(solve(l+1 , r-1) , solve(l+2 , r));
    int B = arr[r] + min(solve(l+1 , r-1) , solve(l , r-2));

    return dp[l][r] = max(A , B);
}
int32_t main()
{
    int n;
    cin>>n;
    memset(dp , -1 , sizeof(dp));
    for(int i=1; i<=n; i++)cin>>arr[i];
    int total = 0;
    for(int i=1; i <= n; i++)total += arr[i];
    int ans = solve(1 , n);
    // cout<<total<<endl;
    // cout<<ans<<endl;
    cout<<ans-(total-ans)<<endl;
    //cout<<ans<<endl;
}