#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n;
    cin>>n;
    ll a[n];
    ll ans = -1e18;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n%2==0){
        ll dp[n]={};
        for(int i=0;i<n;i++) dp[i] = -1e18;
        dp[0]=a[0], dp[1]=a[1];
        for(int i=2;i<n;i++){
            if(i%2){
                dp[i] = max(dp[i-2],dp[i-3])+a[i];
            }
            else{
                dp[i] = dp[i-2] + a[i];
            }
        }
        chmax(ans,max(dp[n-1],dp[n-2]));
    }
    else{
        if(n==3){
            ans = max({a[0],a[1],a[2]});
            cout << ans << endl;
            return 0;
        }
        ll sum = 0;
        for(int i=0;i<n;i++) sum += a[i];
        ll dp[n][3];
        for(int i=0;i<n;i++){
            dp[i][0]=1e18;
            dp[i][1]=1e18;
            dp[i][2]=1e18;
        }
        dp[0][0] = a[0];
        dp[1][0] = a[1];
        dp[1][1] = a[1];
        dp[1][2] = a[0]+a[1];
        for(int i=2;i<n;i++){
            dp[i][0] = dp[i-2][0] + a[i];
            if(i%2==0){
                dp[i][1] = min(dp[i-2][1],dp[i-1][0]) + a[i];
            }
            else{
                dp[i][2] = min(dp[i-2][2],min(dp[i-1][0],dp[i-1][1])) + a[i];
            }
        }
        ans = sum - min(dp[n-1][1],dp[n-2][2]);
    }
    cout << ans << endl;
}
