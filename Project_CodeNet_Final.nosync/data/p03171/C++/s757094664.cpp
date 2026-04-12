#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll n,a[100009],dp[3009][3009],ps[100009];

ll f(ll l, ll r){
    if(l>r)return 0;
    if(dp[l][r]==-1){
        dp[l][r]=max(ps[r]-ps[l-1]-f(l+1,r), ps[r]-ps[l-1]-f(l,r-1));
    }
    return dp[l][r];
}

int main(){
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        ps[i]=a[i]+ps[i-1];
    }
    cout << 2*f(1,n)-ps[n] << endl;
}