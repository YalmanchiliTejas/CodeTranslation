#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
ll dp[3001][3001];
ll fun(int x,int y,int *a){
    if(x>y)return 0;
    if(x==y)return a[x];
    if(dp[x][y]>-1)return dp[x][y];
    ll X=a[x]+min(fun(x+2,y,a),fun(x+1,y-1,a));
    ll Y=a[y]+min(fun(x+1,y-1,a),fun(x,y-2,a));
    ll ans=max(X,Y);
    return dp[x][y]=ans;
}
void solve()
{
    int n;
    cin>>n;
    int a[n];
    ll sum=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    memset(dp,-1,sizeof dp);
    ll X=fun(0,n-1,a);
    cout<<X-(sum-X);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
        cout<<endl;
    }
}
