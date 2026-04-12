    #include<bits/stdc++.h>
    using namespace std;
    
    #define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    #include <ext/pb_ds/assoc_container.hpp> 
    #include <ext/pb_ds/tree_policy.hpp> 
    using namespace __gnu_pbds; 
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    
    #define int long long 
    #define double long double
    
    #define all(a)      (a).begin(),(a).end()
    #define sz(x)       (int)x.size()
    
    #define ff first
    #define ss second
    #define mp make_pair
         
    #define pb push_back
    #define endl "\n" 
         
    #define f(i,l,r) for(int i=l;i<=r;i++)
    #define rf(i,r,l) for(int i=r;i>=l;i--)    

    #define bp __builtin_popcountll
    #define inf 1e18
    
    const int N=1e5+5; 
    const int MOD=1e9+7;
    void solve()
    {
        int n;
        cin>>n;
        int a[n+1];
        f(i,1,n)
        cin>>a[i];
        if(n%2==0)
        {
        	int dp[n+1];
        	dp[0]=0;
        	dp[1]=a[1];
        	dp[2]=a[2];
        	f(i,3,n)
        	{
        		if(i%2==0)
        		dp[i]=max(dp[i-2],dp[i-3])+a[i];
        		else
        		dp[i]=dp[i-2]+a[i];
        	}
        	int ans=max(dp[n],dp[n-1]);
        	cout<<ans;
        	return;
        }
        else
        {
        	int dp[n+1][2];
        	dp[0][0]=0;
        	dp[0][1]=0;
        	dp[1][0]=0;
        	dp[1][1]=a[1];
        	dp[2][0]=a[2];
        	dp[2][1]=a[2];
        	dp[3][0]=max(a[3],a[1]);
        	dp[3][1]=a[1]+a[3];
        	f(i,4,n)
        	{
        		if(i%2==0){
        			dp[i][0]=max(dp[i-2][0],dp[i-3][1])+a[i];
        			dp[i][1]=max(dp[i-2][0],dp[i-3][1])+a[i];
        		}
        		else
        		{
        			dp[i][0]=max(dp[i-2][0],dp[i-3][0])+a[i];
        			dp[i][1]=dp[i-2][1]+a[i];
        		}
        		
        	}
        	int ans=max(max(dp[n][0],dp[n-1][0]),dp[n-2][1]);
        	cout<<ans;
        	return;
        }
    }
    
    signed main()  
    {
        FAST
        int t=1;
        // cin>>t;
        while(t--)
        {
            solve();
        }
    }

