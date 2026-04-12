#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)

using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1e9+7;

ll dp[10002][2][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string N;
    cin>>N;
  	int D;
    cin>>D;
    int n=N.length();
    dp[0][0][0]=1;
    rep(i,0,n){
        rep(j,0,2){
            rep(k,0,D){
                int lim=(j?9:N[i]-'0');
                rep(d,0,lim+1){
                    dp[i+1][j||d<lim][(k+d)%D]+=dp[i][j][k];
                    dp[i+1][j||d<lim][(k+d)%D]%=MOD;
                }
            }
        }
    }
    ll ans=-1; //正の整数
    rep(j,0,2){
        ans+=dp[n][j][0];
        ans=(ans%MOD+MOD)%MOD;
    }
    cout << ans<<"\n";
}
