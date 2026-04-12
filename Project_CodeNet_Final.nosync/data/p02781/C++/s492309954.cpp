#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

ll dp[110][2][5];

int main() {
    string N;
    int K;
    cin>>N>>K;

    int n=N.size();
    dp[0][0][0]=1;

    rep(dgt,n){
        rep(isless,2){
            rep(k,K+1){
                int c=N[dgt]-'0';
                rep(nxt,10){
                    if(c<nxt && isless==0) continue;

                    int dgt2=dgt+1;
                    int isless2=isless;
                    if(nxt<c) isless2=1;
                    int k2=k;
                    if(nxt!=0) k2++;

                    dp[dgt+1][isless2][k2]+=dp[dgt][isless][k];
                }
            }
        }
    }

    ll ans=dp[n][0][K]+dp[n][1][K];
    cout<<ans<<endl;
}