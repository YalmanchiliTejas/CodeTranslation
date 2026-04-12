#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[3005][3005];
ll f(ll ar[],int i,int j){
    if(i>j){
        return 0;
    }
    //Recursive Case
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    ll ans1 = ar[i]  + min(f(ar,i+2,j),f(ar,i+1,j-1));
    ll ans2 = ar[j]  + min(f(ar,i,j-2),f(ar,i+1,j-1));
    dp[i][j] = max(ans1,ans2);
    return dp[i][j];
}

int main(){
    int n;
    cin>>n;
    ll ar[n];
    memset(dp,-1,sizeof(dp));
    ll s=0;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        s += ar[i];
    }
    ll x = f(ar,0,n-1);
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    ll y = s-x;
    cout<<x-y;
}
