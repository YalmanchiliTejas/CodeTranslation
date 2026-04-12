#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> myds;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define F first
#define S second
#define vec(x) vector<x> 
#define pi(x,y) pair<x,y>
#define pqq(x) priority_queue<x> 
#define min_heap(x) priority_queue<x, vector<x>, greater<x> >
#define all(x) x.begin(),x.end()
#define rep(i,x,y) for(int i=x;i<y;i++)
#define repd(i,x,y,k) for(int i=x;i<y;i+=k)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define rev(x) reverse(all(x))
#define full(x,a) memset(x,a,sizeof(x))
#define lcm(x,y) ((x*y)/__gcd(x,y))
#define mod 1000000007
#define bitcount __builtin_popcountll
#define pb push_back
#define indexof order_of_key
#define valueat find_by_order

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dxx[8]={0,0,1,-1,-1,-1,1,1};
int dyy[8]={1,-1,0,0,-1,1,1,-1};


main(){
    fastio;
    int n;
    cin>>n;
    int arr[n+1];
    rep(i,1,n+1)
        cin>>arr[i];
    int dp[n+1],sum[n+1];
    dp[0]=dp[1]=0;
    sum[1]=arr[1];
    repd(i,3,n+1,2)
        sum[i]=sum[i-2]+arr[i];
    rep(i,2,n+1){
        if(i&1) //odd
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        else{   //even
            dp[i]=arr[i]+dp[i-2];
            dp[i]=max(dp[i],sum[i-1]);
        }
    }
    cout<<dp[n]<<endl;   
}
