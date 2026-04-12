/**
   Solution by Abil
**/
# include <bits/stdc++.h>

# define fr first
# define sc second
# define pb push_back
# define mk make_pair
# define sz(s) s.size()
# define all(s) s.begin(),s.end()
# define int long long

using namespace std;

const long long N = (1e5 + 10);
const long long mod = (1e9 + 7);
const long long inf = (1e9 + 7);

int dp[3005][3005][2], arr[N];

int ans(int l,int r,int per){
    if(l > r){
        return 0;
    }
    if(dp[l][r][per] != -1){
        return dp[l][r][per];
    }
    if(per == 0){
       return dp[l][r][per] = max(ans(l + 1,r,1 - per) + arr[l],ans(l,r - 1,1 - per) + arr[r]);
    }
    if(per == 1){
       return dp[l][r][per] = min(ans(l + 1,r,1 - per) - arr[l],ans(l,r - 1,1 - per) - arr[r]);
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << ans(1,n,0);
}
