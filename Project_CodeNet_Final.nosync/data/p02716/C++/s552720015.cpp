#include<bits/stdc++.h>
#define rp(i,n) for(ll i=0; i<n; i++)
using namespace std;
using ll=long long;

ll dp[200010][3];
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i=1; i<=n; i++){
        cin >> a.at(i);
    }
    if(n==2){
        cout << max(a.at(1),a.at(2)) << endl;
        return 0;
    }
    dp[0][0]=0;
    dp[1][0]=a.at(1);
    dp[1][1]=a.at(2);
    dp[1][2]=a.at(3);
    for(ll i=2; i<=n/2; i++){
        dp[i][0]=dp[i-1][0]+a.at(i+i-1);
        dp[i][1]=max(dp[i-1][1]+a.at(i+i),dp[i-1][0]+a.at(i+i));
        if(n%2==1){
            dp[i][2]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+a.at(i+i+1);
        }
    }
    ll ans;
    if(n%2==0) ans=max(dp[n/2][0],dp[n/2][1]);
    else ans=max(max(dp[n/2][0],dp[n/2][1]),dp[n/2][2]);
    cout << ans << endl;
    return 0;
}