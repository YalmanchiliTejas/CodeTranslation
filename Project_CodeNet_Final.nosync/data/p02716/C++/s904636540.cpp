#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lowbit(x) ((x)&(-x))
#define inf 0x3f3f3f3f
#define endl "\n"
#define MP(x,y) (make_pair(x,y))
#define pll pair<int,int>
#define pi 3.1415926535
using namespace std;
/*
1 2 3 4 5 6 7
*/
ll n,a[200005];
ll dp[2][2][100005];
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    int x = n/2;
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0][0]=0;
    dp[0][1][1]=a[1];
    for(int i=2;i<=n;i++){
        int mx = min(i/2+1,x);
        int mn = max(0,mx-4);
        for(int j=mn;j<=mx;j++){
            if(j!=0) dp[1][1][j] = a[i] + dp[0][0][j-1];
            dp[1][0][j] = max(dp[0][0][j],dp[0][1][j]);
        }
        for(int j=mn;j<=mx;j++){
            dp[0][0][j]=dp[1][0][j];
            dp[0][1][j]=dp[1][1][j];
        }
    }
    cout<<max(dp[0][0][x],dp[0][1][x]);
}
