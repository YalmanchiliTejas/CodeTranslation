#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;
const int inf = 1e15;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N =2e5+10;
int dp[N][3];

void solve()
{
   int n;
    cin >> n;
    
    int a[n];
    f(i,n) cin >> a[i];
    
        f(i,n) f(j,3) dp[i][j] = -inf;
        
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        dp[2][2] = a[2];
        dp[2][0] = a[0] + a[2];
    
        for(int i=3;i<n;i++)
        {
           dp[i][0] = a[i] + dp[i-2][0];
           dp[i][1] = a[i] + max(dp[i-2][1],dp[i-3][0]);
           dp[i][2] = a[i] + max(dp[i-2][2],dp[i-3][1]);
            
           if(i>3) dp[i][2] = max(dp[i][2],a[i] + dp[i-4][0]);
        }
        
  if(n%2 == 1)
  {
        int res = dp[n-1][2];
        res = max(res,dp[n-2][1]);
        res = max(res,dp[n-3][0]);
        cout << res;
  }
  else
  {
      int res = dp[n-1][1];
      res = max(res,dp[n-2][0]);
    
      cout << res;
  }
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}