#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007

int main(){
    string N;ll K;
    cin>>N>>K;

    ll dp[110][2][5];//i桁目までで0以外を使用したのはk個　jはtrueかfalseで、trueならsmallerはnより小さく、そうでなければnと同じ
    rep(i,110)rep(j,2)rep(k,5) dp[i][j][k]=0;
    dp[0][0][0]=1;

    for(ll i=0;i<N.size();i++){
        for(ll k=0;k<=K;k++){
            //i桁目でnより小さいなら次の桁は1~9全部ok
            dp[i+1][true][k+1]+=9*dp[i][true][k];//次の桁で0以外を選択する場合
            dp[i+1][true][k]+=dp[i][true][k];//0を選ぶ場合

            //i桁目までnと同じで,次の桁で初めてnより小さくなる場合
            if(N[i]!='0'){    
                dp[i+1][true][k+1]+=(N[i]-'0'-1)*dp[i][false][k];//0以外を選択する場合
                dp[i+1][true][k]+=dp[i][false][k];//0を選択する場合
            }

            //i桁目でnと同じで次の桁でもnと同じ時
            if(N[i]!='0'){
                dp[i+1][false][k+1]+=dp[i][false][k];//次の桁が0でないとき
            }else{
                dp[i+1][false][k]+=dp[i][false][k];//次の桁が0の時
            }
        }
    }

    cout<<dp[N.size()][0][K]+dp[N.size()][1][K]<<endl;
    return 0;
}