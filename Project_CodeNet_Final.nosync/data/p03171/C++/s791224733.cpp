#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n;
    cin>>n;
    ll a[n];
    ll dp[n][n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[i][i]=a[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            dp[j][j+i-1]=max(a[j]-dp[j+1][j+i-1],a[j+i-1]-dp[j][j+i-2]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}