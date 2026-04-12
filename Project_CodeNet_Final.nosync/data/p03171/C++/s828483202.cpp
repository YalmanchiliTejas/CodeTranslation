#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[3001][3001];
ll a[3001];
ll n;
ll solve(ll l, ll r){
    if(l > r){
        return 0;
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    dp[l][r] = max(a[l] - solve(l+1,r), a[r] - solve(l,r-1));

return dp[l][r];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<solve(1,n)<<"\n";
}
