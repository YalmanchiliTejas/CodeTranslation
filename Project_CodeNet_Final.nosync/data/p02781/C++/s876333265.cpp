#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

ll dp[110][2][5];
int main(){
    string s; cin >> s;
    int n = s.size();
    ll K; cin >> K;

    dp[0][0][0]=1;
    rep(i,n){
        int D = s[i]-'0';
        rep(j,2){
            rep(k,K+1){
                for(int d=0;d<=(j ? 9:D);d++){
                    dp[i+1][j | (d<D)][k + (d>0)] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[n][0][K]+dp[n][1][K] << endl;
}