#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;

typedef long long ll;
const ll N=2e5+7;
ll dp[N][2];
ll arr[N];
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)  cin>>arr[i];
    dp[2][0]=arr[1];
    dp[2][1]=arr[2];
    rep(i,3,n){
        if(i&1){
            dp[i][1]=max({dp[i-2][0],dp[i-2][1],dp[i-3][0],dp[i-3][0]})+arr[i];// 7 <- 5,4
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);//7<-6
        }
        else {
            dp[i][1]=max({dp[i-2][1],dp[i-2][0]})+arr[i];//6<-4 no 5 because dp[5][0]=max(dp[4][1],dp[4][0])
            dp[i][0]=dp[i-2][0]+arr[i-1];//6<-4 because dp[4][0]must take a[1] a[3]
        }
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
    return 0;
}
/* 
if N%2==0 2 choice


if N%2==1
dp[i][flag] 前i项，最后一项flag？拿:not take  
不行，还要记录拿几个（其实是可以的，再加一个约束：取i/2个，转移的时候不会考虑别的）
dp[i][j]
j=i/2-1 .. (i+1)/2
i=4 j= 1 2
i=3 j= 0 1 2
i=5 j= 1 2 3
5
1 2 3 4 5
1 3
1 4 
1 5
2 4
2 5
3 5
 */