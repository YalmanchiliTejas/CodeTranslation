    #include<bits/stdc++.h>
    #include<math.h>

    typedef long long int ll;
    #define pb         push_back
    #define mp         make_pair
    #define F          first
    #define S          second
    #define fl(i,a,b)  for(ll i=a;i<b;i++)
    #define pll        pair<ll,ll>
    #define pii        pair<int,int>
    #define all(v)     v.begin(),v.end()
    #define M 1000000007
    #define tr(v, it) for(auto it = v.begin(); it != v.end(); it++)
    #define fast   ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed;
    using namespace std;
    ll dp[3005][3005];
    ll dfs(ll arr[], int i , int j)
    {
        if(i==j)
            return arr[i];
        if(j==i+1)
            return max(arr[i],arr[j]);
        if(dp[i][j]!=-1)
            return dp[i][j];
        ll ans;
        ans = max((arr[i]+min(dfs(arr, i+2, j),dfs(arr,i+1, j-1))), arr[j]+min(dfs(arr,i+1,j-1),dfs(arr,i, j-2)));
        return dp[i][j]=ans;
    }
    int main()
    {
            fast
         int n;
         cin>>n;
         ll arr[n];
         ll sum=0;
         for(int i=0; i<n; i++)
         {
             cin>>arr[i];
             sum = sum+arr[i];
         }
         memset(dp,-1,sizeof(dp));
        ll x =dfs(arr,0,n-1);
        ll y  = sum-x;
        cout<<x-y;
        return 0;

    }

