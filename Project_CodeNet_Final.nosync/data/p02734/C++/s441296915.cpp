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

const int MOD = 998244353;
const int N = 3005;
int dp[N][N];

void solve()
{
   int n,s;
    cin >> n >> s;
    
    int a[n];
    f(i,n) cin >> a[i];
    
    int res = 0;
    
    for(int i=0;i<n;i++)
    {
       
        for(int j=1;j<=s;j++)
        {
            if(j!= s && i > 0) dp[i][j] = dp[i-1][j];
            
            if(a[i] <= j)
            {
                if(a[i] == j) dp[i][j] += (i+1);
                else if(i > 0) dp[i][j] += dp[i-1][j-a[i]];
            }
            
            dp[i][j]%=MOD;
           
            if(j == s) res=(res+(dp[i][j]*(n-i))%MOD)%MOD;
            
        }
    }
    
    cout << res;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}