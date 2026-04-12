#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9+7;
#define pb push_back
typedef long long ll;
const long long int N = 1e5;



int main(){
    int n;
    cin>>n;
    vector<vector<ll>> dp(n+5,vector<ll>(n+5,0));
    ll a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[1][n];
    return 0;
}