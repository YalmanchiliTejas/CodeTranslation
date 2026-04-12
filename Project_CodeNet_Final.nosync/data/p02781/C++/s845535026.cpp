#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;



int main(){
    string s;
    cin >> s;
    ll K;
    cin >> K;
    ll N=s.size();

    vector<ll> num(N,0);
    for(ll i=0;i<N;i++){
        num[i]=s[i]-'0'
    ;}                 

    //未満フラグ、
    vector<vector<ll>> dp(2, vector<ll>(4, 0));
    dp[1][0]=1;
    dp[1][1]=num[0]-1;
    dp[0][1]=1;

    for(ll j=1;j<N;j++){
        vector<vector<ll>> dp2(2, vector<ll>(4, 0));
        if(num[j]!=0){
            //0の追加
            for(ll i=0;i<4;i++){
                dp2[1][i]+=dp[0][i]
            ;}
            for(ll i=0;i<4;i++){
                dp2[1][i]+=dp[1][i]
            ;}
            //numの追加
            for(ll i=1;i<4;i++){
                dp2[0][i]+=dp[0][i-1]
            ;}
            for(ll i=1;i<4;i++){
                dp2[1][i]+=dp[1][i-1]
            ;}
            //1からnum-1の追加
            for(ll i=1;i<4;i++){
                dp2[1][i]+=dp[0][i-1]*(num[j]-1)+dp[1][i-1]*(num[j]-1)
            ;}
            //num+1から9の追加
            for(ll i=1;i<4;i++){
                dp2[1][i]+=dp[1][i-1]*(9-num[j])
            ;}

        }
        else if(num[j]==0){
            //0の追加
            for(ll i=0;i<4;i++){
                dp2[1][i]+=dp[1][i];
                dp2[0][i]+=dp[0][i];
            ;}
            //1から9の追加
            for(ll i=1;i<4;i++){
                dp2[1][i]+=dp[1][i-1]*9
            ;}
        }
        for(ll i=0;i<4;i++){
            dp[1][i]=dp2[1][i];
            dp[0][i]=dp2[0][i]
        ;}

    ;}

    cout<<dp[0][K]+dp[1][K]<<endl;
    

    return 0;
}
