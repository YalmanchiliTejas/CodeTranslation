#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX=3000;
const ll limit=1e13;
int n;
ll dp[MAX][MAX][2];
vector<int> a(MAX);
ll calc(int start,int end,int turn){
    if(start>end){
        return 0;
    }
    if(dp[start][end][turn]!=limit){
        return dp[start][end][turn];
    }
    ll ans;
    if(start==end){
        ans=a[start]-calc(start+1,end,1-turn);
    }
    else{
        ans=max(a[start]-calc(start+1,end,1-turn),a[end]-calc(start,end-1,1-turn));
    }
    return dp[start][end][turn]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<n;j++){
            dp[i][j][0]=limit,dp[i][j][1]=limit;
        }
    }
    ll result=calc(0,n-1,1);
    cout<<result<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
