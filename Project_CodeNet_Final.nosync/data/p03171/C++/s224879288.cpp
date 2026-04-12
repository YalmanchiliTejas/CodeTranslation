#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll minn(ll x, ll y){
    if(x<y)
        return x;
    return y;
}
ll maxx(ll x, ll y){
    if(x>y)
        return x;
    return y;
}

ll dp[3009][3009][2];
ll a[3009];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i = 1 ;i <= n; i++ ){
        for(int j=0; j + i - 1 <n;j++ ){
            if(i==1){
                dp[i][j][0] = (ll)a[j];
                dp[i][j][1] = (ll)-a[j];
            }
            else{
                dp[i][j][0] = maxx(dp[i-1][j][1] + a[j+i-1], dp[i-1][j+1][1] + a[j]); 
                dp[i][j][1] = minn(dp[i-1][j][0] - a[j+i-1], dp[i-1][j+1][0] - a[j]); 
            }
            // cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
        }
    }
    cout<<dp[n][0][0];
}