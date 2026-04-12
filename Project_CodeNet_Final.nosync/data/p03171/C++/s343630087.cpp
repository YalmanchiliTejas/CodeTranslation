#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
ll solve(ll i,ll j, ll arr[], ll dp[3000][3000], ll n){

    if(i>j){
        return 0;
    }
    else if(i==j){
        dp[i][j]=arr[i];
        return arr[i];
    }
    else if(dp[i][j]!=0){
        return dp[i][j];
    }
    else{
        ll ret = arr[i] - solve(i + 1, j,arr,dp,n );
        ret = max(ret, arr[j] - solve(i, j-1,arr,dp,n));
        dp[i][j]=ret;
        return ret;
    }
    return 0;
}
int main(int argc, char const *argv[])
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        ll arr[n],dp[3000][3000]={0};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cout<<solve(0,n-1,arr,dp,n)<<endl;
    }
    return 0;
}
