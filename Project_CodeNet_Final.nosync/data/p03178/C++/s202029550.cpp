#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,l,r) for(int i=(l),i##_len=(r);i<r;++i)
#define int long long
using namespace std;
constexpr int mod = 1e9+7;
signed main(){
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<vvi> vvvi;
    string K;cin>>K;
    int D;cin>>D;
    int N=K.size();
    vvvi dp(N+1,vvi(D,vi(2,0)));
    //dp[i][j][k]:i桁目までで総和をDで割った余りがjであるもの,k=1ならばKに一致
    dp[0][0][1]=1;
    REP(i,K.size()) REP(j,D){
        REP(k,10){
            (dp[i+1][(j+k)%D][0]+=dp[i][j][0])%=mod;
            if(k<K[i]-'0') (dp[i+1][(j+k)%D][0]+=dp[i][j][1])%=mod;
            if(k==K[i]-'0') (dp[i+1][(j+k)%D][1]+=dp[i][j][1])%=mod;
        }
    }
    cout<<(dp[N][0][0]+dp[N][0][1]+mod-1)%mod<<endl;
}