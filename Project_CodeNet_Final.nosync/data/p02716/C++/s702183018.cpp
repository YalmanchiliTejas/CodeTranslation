#include "bits/stdc++.h"
#define ll long long
using namespace std;
const int N = 2e5+5;

int a[N];
ll x[N],y[N],dp[N],fi[N];

int main()
{
    ios::sync_with_stdio(false);

    int n;  cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n%2==0){
        dp[1] = a[1] , dp[2] = a[2];
        for(int i=2;i<=n/2;i++){
            dp[i*2-1] = dp[i*2-3] + a[i*2-1];
            dp[i*2] = a[i*2] + max( dp[i*2-3] , dp[i*2-2] );
        }
        cout<<max(dp[n],dp[n-1])<<endl;
    }
    else{
        ll ans = 0;
        for(int i=2;i<=n;i+=2)
            ans += a[i];
        int cnt = 0 , tot = 0;
        for(int i=1;i<=n;i+=2){
            x[cnt+1] = x[cnt] + a[i];
            cnt++;
        }
        for(int i=n;i>=1;i-=2){
            y[tot+1] = y[tot] + a[i];
            tot++;
        }

        dp[1] = a[1] , dp[2] = a[2];
        for(int i=2;i<=n/2;i++){
            dp[i*2-1] = dp[i*2-3] + a[i*2-1];
            dp[i*2] = a[i*2] + max( dp[i*2-3] , dp[i*2-2] );
        }

        fi[n] = a[n] , fi[n-1] = a[n-1];
        for(int i=n-3;i>1;i-=2){
            fi[i] = a[i] + max( fi[i+2] , fi[i+3] );
            fi[i+1] = a[i+1] + fi[i+3];
        }

        for(int i=1;i<n;i++){
            ll sum;
            if(i%2)
                sum = y[n/2-i/2] + dp[i-1];
            else sum = x[i/2] + fi[i+2];
            ans = max( ans,sum );
        }
        cout<<ans<<endl;
    }
}