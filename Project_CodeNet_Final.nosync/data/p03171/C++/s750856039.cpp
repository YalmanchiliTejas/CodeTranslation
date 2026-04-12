
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (int)(1000000007)
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 9999999999999999
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 3005
#define mxnn 2000005
int arr[mxn],dp[mxn][mxn][2],memo[mxn][mxn][2];
int func(int l,int r,int turn){
if(r==l){
        if(turn == 0) return arr[r];
        else          return -arr[r];
}
if(memo[l][r][turn]) return dp[l][r][turn];
int x;
if(turn == 0){
    x = max(arr[r]+func(l,r-1,1),arr[l]+func(l+1,r,1));
}
else x = min(func(l,r-1,0)-arr[r],-arr[l]+func(l+1,r,0));
memo[l][r][turn] = 1;
return dp[l][r][turn] = x;
}
int32_t main(){
sp;
memset(memo,0,sizeof memo);
int n;
cin >>n;
for(int i = 1;i<=n;i++) cin >>arr[i];
cout<<func(1,n,0);
return 0;
}
