#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

ll dp[10005][101][2];
vector<int> digit;
int d;
ll solve(int id,int sum,int y){
if(id<0){
    if(sum%d==0)
        return 1;
    return 0;
}
if(dp[id][sum][y]!=-1)return dp[id][sum][y];
ll ways=0;
int k=y?digit[id]:9;
for(int i=0; i<=k; ++i){
    int ny=(digit[id]==i)?y:0;
    int nsum=(sum+i)%d;
    ways=(ways+solve(id-1,nsum,ny))%mod;
}
return dp[id][sum][y]=ways;
}


int main(){
sp;
    string a;
    cin>>a>>d;
    memset(dp,-1,sizeof dp);
    for(int i=a.size()-1; i>-1; --i)digit.pb(a[i]-'0');
    ll x=solve(a.size()-1,0,1);
    cout<<(x-1+mod)%mod<<"\n";
return 0;}
