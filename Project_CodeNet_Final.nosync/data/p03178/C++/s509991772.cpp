
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
#define mxn 10005
#define mxnn 2000005
string s;
int n,d;
int dp[mxn][105][2];
int func(int ind,int sum,int tight){
if(ind ==n) return (sum%d == 0 );
if(dp[ind][sum][tight] != -1) return dp[ind][sum][tight];
int start = 0;
int en = (tight ? s[ind]-'0': 9);
int res = 0;
int new_tight = 0;
for(int i = start;i<=en;i++){
    int x = (sum+i)%d;
    if(tight && i==en) new_tight = 1;
    res = (res+func(ind+1,x,new_tight))%mod;
}
return dp[ind][sum][tight] = res;
}
int32_t main(){
sp;
cin >>s;
n = s.size();
cin >>d;
memset(dp,-1,sizeof dp);
cout<<(func(0,0,1)-1+mod)%mod;
return 0;
}
