//
//  main.cpp
//  ABC162F
#include <iostream>
#include <vector>
#include <algorithm>
//#include<cassert> // combinationを使う時
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
ll a[200005]={};
ll dp[100005][2]={};
ll dp2[100005][2][2]={};
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    rep(i,n) cin>>a[i];
    dp[0][0]=a[0]; // i:グループ番号 j:0:左 1:右
    dp[0][1]=a[1];
    dp2[0][0][0]=a[0];
    dp2[0][1][0]=a[1];
    dp2[1][0][1]=a[2];
    dp2[1][1][1]=a[3];
    // 偶数個のとき　各グループからひとつずつ取る
    ll ans=0; // 偶数個のときの答え
    ll ans2=0; // 奇数個のときの答え候補
    if(n%2==0){
        for(int i=1;i<n/2;i++){
            dp[i][0]=dp[i-1][0]+a[2*i];
            dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i*2+1];
        }
        ans=max(dp[n/2-1][0],dp[n/2-1][1]);
    } else{
        // 奇数個のとき　一番最後の数を使うなら、ひとつのグループを使わない
        // 一番最後の数を使わないなら、最後のグループまでで答えを作る
        for(int i=1;i<n/2;i++){
            dp2[i][0][0]=dp2[i-1][0][0]+a[2*i];
            dp2[i][1][0]=max(dp2[i-1][0][0],dp2[i-1][1][0])+a[i*2+1];
            if(i==1){
                dp2[1][0][1]=a[2];
                dp2[1][1][1]=a[3];
            }else{
                dp2[i][0][1]=max(max(dp2[i-2][0][0],dp2[i-2][1][0]),dp2[i-1][0][1])+a[i*2];
                dp2[i][1][1]=max(max(dp2[i-2][0][0],dp2[i-2][1][0]),
                                 max(dp2[i-1][0][1],dp2[i-1][1][1]))+a[i*2+1];
            }
        }
        if(n>=5){
            ans2=max(max(dp2[n/2-1][0][0],dp2[n/2-1][1][0]),dp2[n/2-1][0][1]+a[n-1]);
        }else{
            ans2=max(max(a[0],a[1]),a[2]);
        }
    }
    if(n%2==0){
        cout<<ans<<endl;
    } else{
        cout<<ans2<<endl;
    }
    //rep(i,n/2)rep(j,2)rep(k,2) cout<<"dp2["<<i<<"]["<<j<<"]["<<k<<"]="<<dp2[i][j][k]<<endl;
    return 0;
}
