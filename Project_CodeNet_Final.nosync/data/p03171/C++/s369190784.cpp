#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

bool flag=true;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++) cin >> a[i];
    int x=0,y=0;

    vector<vector<ll>> dp(n,vector<ll>(n,0));

    for(int l=n-1; l>=0; l--){
        for(int r=l; r<n; r++){
            if(l==r) dp[l][r]=a[l];
            else{
                dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<'\n';

    return 0;
}
