#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans;

    if(n%2==0){
        ll dp[(n/2)+1][2];
        dp[0][0]=dp[0][1]=0;
        rep(i,n/2){
            dp[i+1][0]=dp[i][0]+a[i*2];
            dp[i+1][1]=max(dp[i][0],dp[i][1])+a[2*i+1];
        }
        ans=max(dp[n/2][0],dp[n/2][1]);
    }
    else{
        ll dp[(n/2)+1][2][2];
        rep(i,2)rep(j,2) dp[0][i][j]=0;
        rep(i,n/2){
            dp[i+1][0][0]=dp[i][0][0]+a[i*2];
            dp[i+1][1][0]=max(dp[i][0][0],dp[i][1][0])+a[2*i+1];
            if(i!=0) dp[i+1][0][1]=max(dp[i][0][0],max(dp[i][0][1]+a[2*i],dp[i][1][0]));
            else dp[i+1][0][1]=0;
            //dp[i+1][1][1]=max(dp[i][1][1],dp[i][1][0])+a[2*i+1];
        }
        ans=max(max(dp[n/2][0][0],dp[n/2][1][0]),dp[n/2][0][1]+a[n-1]);
    }

    cout << ans << endl;
    return 0;
}
