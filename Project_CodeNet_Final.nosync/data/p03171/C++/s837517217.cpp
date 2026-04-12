#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
 
int main(){
    int N;cin>>N;
    vector<ll> a(N);
    REP(i,N)cin>>a[i];
    vector<vector<ll>> dp(N,vector<ll>(N,0LL));
    if(N%2==0){
        REP(i,N)dp[i][0]=-a[i];
        FOR(j,1,N)FOR(i,0,N){
            if(i+j>=N)continue;
            else{
                if((j+1)%2==0){
                    dp[i][j]=max(a[i]+dp[i+1][j-1],a[i+j]+dp[i][j-1]);
                }else{
                    dp[i][j]=min(-a[i]+dp[i+1][j-1],-a[i+j]+dp[i][j-1]);
                }
            }
        }
    }
    if(N%2==1){
        REP(i,N)dp[i][0]=a[i];
        FOR(j,1,N)FOR(i,0,N){
            if(i+j>=N)continue;
            else{
                if((j+1)%2==0){
                    dp[i][j]=min(-a[i]+dp[i+1][j-1],-a[i+j]+dp[i][j-1]);
                }else{
                    dp[i][j]=max(a[i]+dp[i+1][j-1],a[i+j]+dp[i][j-1]);
                }
            }
        }
    }
    cout<<dp[0][N-1]<<endl;
    return 0;
}