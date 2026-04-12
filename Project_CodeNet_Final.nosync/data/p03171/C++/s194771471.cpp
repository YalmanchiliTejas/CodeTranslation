#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007;
vector<vector<vector<long long>>>dp; // dp(i,j) probablity of coming j heads when i coins
vector<int>v;

long long winner(int l,int r,int player){
    if(l>r){
        return 0;
    }
    if(dp[l][r][player]!=-1){
        return dp[l][r][player];
    }
    long long x;
    if(player==0){
         x = max(v[l]+winner(l+1,r,1-player),v[r]+winner(l,r-1,1-player));
    }else{
        x = min(winner(l+1,r,1-player)-v[l],winner(l,r-1,1-player)-v[r]);
    }
    return dp[l][r][player]=x;
}

void solve(){
    int n;cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    dp.resize(n,vector<vector<long long> >(n,vector<long long>(2,-1)));
    int l=0,r=n-1;
    long long x = winner(l,r,0);
    cout<<x<<"\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);

    cout.precision(10);
    int t=1;//cin>>t;
    while(t--){

        solve();
    }
    return 0;
}
