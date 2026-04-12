#include<bits/stdc++.h>
#define rep(n) for(int i=0;i<(n);i++)
#define rep1(n) for(int i=1;i<=(n);i++)
#define all(n) n.begin(),n.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define pb push_back
#define debug(x) cout<<#x<<"="<<x<<'\n';
ll dp[3005][3005];
ll arr[3005];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>arr[i];
       dp[i][i] = arr[i];
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int r = i+l-1;
            dp[i][r] = max(arr[i] - dp[i+1][r] , arr[r] - dp[i][r-1]);
            //cout<<i<<" "<<r<<" "<<dp[i][r]<<'\n';
        }
    }

    cout<<dp[1][n]<<'\n';

}
