#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

string N;
int K;
ll dp[101][2][5];

int main(){
    cin>>N>>K;

    int n=N.size();
    dp[0][0][0]=1;

    rep(dgt,n) rep(isless,2) rep(k,K+1){
        int c=N[dgt]-'0';
        rep(nxt,10){
            if(c<nxt && isless==0) continue;

            int isless2=isless;
            if(nxt<c) isless2=1;
            int k2=k;
            if(nxt!=0) k2++;

            dp[dgt+1][isless2][k2]+=dp[dgt][isless][k];
        }
    }

    cout<<dp[n][0][K]+dp[n][1][K]<<endl;
}


 