#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<ll> a;
ll dp[3005][3005];
// ll solve(int i,int j) {
//     if(dp[i][j] !=  0)
//     if(i == j) {
//         return a[i];
//     }
//     if(j == i+1) return max(a[i],a[j]);
//     return max(min(solve(i+2,j),solve(i+1,j-1))+ a[i], min(solve(i+1,j-1),solve(i,j-2)) + a[j]);  

    
// }
int main() {
    cin>>n;
    a.resize(n);
    ll sum = 0;
    for(int i = 0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    for(int i = n-1;i>= 0 ;i--) {
        for(int j = i;j<n;j++) {
            if(i==j) dp[i][j] = a[i];
            else if(i == j-1) dp[i][j] = max(a[i],a[j]);
            else {
                dp[i][j] = max(min(dp[i+2][j],dp[i+1][j-1])+a[i],min(dp[i+1][j-1],dp[i][j-2])+a[j]);
            }
            //printf("dp[%d][%d] = %lld\n",i,j,dp[i][j]);
        }
    }  
    ll ans =  sum - dp[0][n-1];
    ll other = sum - ans;
    cout<<other - ans<<"\n";
}