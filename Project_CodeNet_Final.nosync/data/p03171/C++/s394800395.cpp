#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define endl '\n'
ll n;
ll arr[3005];
ll dp[3005][3005][2];
ll solve(ll i,ll j,ll s)
{

    if(i>j){
        return 0;
    }

    if(dp[i][j][s]==-1){

        if(s==0){
            dp[i][j][s] = max(arr[i]+solve(i+1,j,1),arr[j]+solve(i,j-1,1));
        }
        else{
            dp[i][j][s] = min(-arr[i]+solve(i+1,j,0),-arr[j]+solve(i,j-1,0));
        }
    }
    //cout<<i<<" "<<j<<" "<<s<<" "<<dp[i][j][s]<<endl;
    return dp[i][j][s];


}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.tie(0);

    memset(dp,-1,sizeof(dp));
    cin>>n;

    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<solve(0,n-1,0)<<endl;






}
