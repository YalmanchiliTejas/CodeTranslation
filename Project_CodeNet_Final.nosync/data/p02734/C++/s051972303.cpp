#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=998244353;



int main(){
    ll N;
    cin >> N;
    ll S;
    cin >> S;
    vector<ll> A(N+1,0);
    for(ll i=0;i<N;i++){
        cin>>A[i+1]
    ;}
    ll ans=0;
    //L確定
    vector<vector<ll>> dp(N+1, vector<ll>(S+1, 0));
    for(ll i=1;i<=N;i++){
        //L=iのときを追加
        dp[i][0]++;
        if(A[i]<=S){
            dp[i][A[i]]++;
        }
        //以下、L<iのとき
        //A[i]採用する方
        for(ll j=A[i];j<=S;j++){
            dp[i][j]+=dp[i-1][j-A[i]];
            dp[i][j]%=MOD;
        ;}
        //A[i]採用しない方
        for(ll j=0;j<=S;j++){
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;
        ;}
        ans+=(MOD+dp[i][S]-dp[i-1][S])*(N-i+1)%MOD;
        ans%=MOD;
    ;}
    cout<<ans<<endl;

    return 0;
}
