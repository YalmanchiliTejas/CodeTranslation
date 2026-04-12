#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define pb push_back
#define INF 1000000005
#define LINF 1000000000000000005

int n,a[3005];

ll dp[3005][3005];

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            if(i%2==n%2){
                dp[i][j]=max(dp[i-1][j+1]+a[j],dp[i-1][j]+a[j+i-1]);
            }
            else{
                dp[i][j]=min(dp[i-1][j+1]-a[j],dp[i-1][j]-a[j+i-1]);
            }
        }
    }
    cout << dp[n][1];
}
