#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 500005

ll dp[3001][3001][2];
ll a[mxn];

ll solve(int i,int j,int turn){
if(i>j)return 0;
ll &ans=dp[i][j][turn];
if(ans!=-1)return ans;
if(turn==1)
    ans=max(a[i]+solve(i+1,j,turn^1),a[j]+solve(i,j-1,turn^1));
else ans=ans=min(-a[i]+solve(i+1,j,turn^1),-a[j]+solve(i,j-1,turn^1));
return ans;
}

int main(){
sp;
int n;
memset(dp,-1,sizeof dp);
cin>>n;
for(int i=1; i<=n; ++i)cin>>a[i];
cout<<solve(1,n,1);
return 0;}
