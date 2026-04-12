#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
}
 int n;
 vi arr(3002);
 int dp[3002][3002];
 int memo(int s,int e)
 {
     if(s>e)
     return 0;
     if(s==e-1)
     return dp[s][e]=max(arr[s],arr[e]);
     if(s==e-2)
     {
         return dp[s][e]=max(arr[s]+min(arr[s+1],arr[e]),arr[e]+min(arr[s],arr[s+1]));
     }
     if(dp[s][e]!=-1)
     return dp[s][e];
     int x=arr[s]+min(memo(s+2,e),memo(s+1,e-1));
     int y=arr[e]+min(memo(s,e-2),memo(s+1,e-1));
     return dp[s][e]=max(x,y);
 }
int32_t main()
{
    c_p_c();
     
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    int sum=accumulate(arr.begin(),arr.end(),0ll);
    //cout<<sum;
     
    cout<<-sum+2*memo(0,n-1);
    return 0;
}