#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;

signed main(){
    string N;int K;cin>>N>>K;
    int dpk[N.size()+1][5];
    int dpm[N.size()+1][5];
    //dp[決めた桁数][0でない数字の個数](ただしdpkはN以下確定、dpmはN以下未確定)
    REP(i,N.size()+1)REP(j,5)dpk[i][j]=dpm[i][j]=0;
    REPS(i,N.size()){
        int d=N[i-1]-'0';
        if(i==1){
            if(d>=1){
                dpk[1][1]=d-1;
                dpk[1][0]=1;
                dpm[1][1]=1;
            }
            if(d==0){
                dpm[1][0]=1;
            }
        }
        else{
            if(d>=1){
                REP(k,4){
                    dpk[i][k+1]+=dpk[i-1][k]*9+dpm[i-1][k]*(d-1);
                    dpk[i][k]+=dpk[i-1][k]+dpm[i-1][k];
                    dpm[i][k]+=dpm[i-1][k-1];
                }
            }
            if(d==0){
                REP(k,4){
                    dpk[i][k+1]+=dpk[i-1][k]*9;
                  	dpk[i][k]+=dpk[i-1][k];
                    dpm[i][k]+=dpm[i-1][k];
                }
            }
        }
    }
    cout<<dpk[N.size()][K]+dpm[N.size()][K]<<endl;
}