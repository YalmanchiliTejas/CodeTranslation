#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int a[3005];
int mod=998244353;
int dp[3004][3005];
signed main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);  
   
 #ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
 #endif
 
// -------------------------------------Code starts here---------------------------------------------------------------------     

    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][a[i]]+=i;
        dp[i][a[i]]%=mod;
        for(int j=1;j<=s;j++)
        {
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=mod;
        }
        for(int j=1;j<=s-a[i];j++)
        {
            dp[i][j+a[i]]+=dp[i-1][j];
            dp[i][j+a[i]]%=mod;
        }
        ans=(ans+dp[i][s])%mod;
    }
    cout<<ans;

// -------------------------------------Code ends here------------------------------------------------------------------
     clock_t clk;
 	clk = clock();
 
    clk = clock() - clk;
 	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
 	return 0;
 }
 