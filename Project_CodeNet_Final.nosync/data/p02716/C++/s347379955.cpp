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
    for(int i=0;i<n;i++) cin>>a[i];
    if(n%2==0){
        ll dp[n+1]={};
        for(int i=0;i<=n;i++) dp[i]=-1e18;
        dp[0] = a[0];
        dp[1] = a[1];
        for(int i=2;i<n;i++){
            if(i%2){
                dp[i] = max(dp[i-2],dp[i-3])+a[i];
            }
            else{
                dp[i] = dp[i-2] + a[i];
            }
        }
        ll ans = max(dp[n-1],dp[n-2]);
        cout << ans << endl;
        return 0;
    }
    else{
        ll dp[n+1][2];
        for(int i=0;i<=n;i++){
            dp[i][0]=-1e18;
            dp[i][1]=-1e18;
        }
        dp[0][0] = a[0];
        dp[1][0] = a[1];
        for(int i=2;i<n;i++){
            dp[i][0] = dp[i-2][0] + a[i];
            if(i%2 && i>=3) chmax(dp[i][0],dp[i-3][0]+a[i]);
            if(i>=3){
                if(i==3) dp[i][1] = a[i];
                ll ret = dp[i-2][1];
                if(i%2==0) chmax(ret,dp[i-3][0]);
                if(i%2 && i>=4) chmax(ret,dp[i-4][0]);
                dp[i][1] = max(dp[i][1],ret + a[i]);
            }
            else dp[i][1] = a[i];
        }
        ll ans = max(dp[n-1][1],dp[n-2][0]);
        chmax(ans,dp[n-2][1]);
        if(n>=3) chmax(ans,dp[n-3][0]);
        cerr << dp[n-1][1] << " " << dp[n-2][0] << " " << dp[n-2][1] << " " << dp[n-3][0] << endl;
        cout << ans << endl;
    }


}