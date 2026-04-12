#include<bits/stdc++.h>

using namespace std;

const int inf=1e9+5;
const int MOD=1e9+7;
const int MAX=1e5+5;

#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vl vector<vector<ll> >
#define eb emplace_back

int n;
ll a[3005],dp[3005][3005]={};

long long solve(){
    for(int i=0;i<n;i++){
        dp[i][i]=a[i];
    }
    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }
    cout<<dp[0][n-1];
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    solve();
    return 0;
}