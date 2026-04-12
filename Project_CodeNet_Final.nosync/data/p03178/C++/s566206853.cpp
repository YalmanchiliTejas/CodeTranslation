#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

string K;
int d;
const int mod=1000000007;
ll dp[10001][2][101];
int main(){
    cin>>K>>d;
    int n=K.size();
    dp[0][0][0]=1;
    rep(i,n)rep(j,2)rep(k,d){
        int ulim=j?9:K[i]-'0';
        rep(l,ulim+1){
            dp[i+1][j||l<ulim][(k+l)%d]+=dp[i][j][k];
            dp[i+1][j||l<ulim][(k+l)%d]%=mod;
        }
    }
    ll ans=0;
    rep(i,2) ans+=dp[n][i][0];
    cout<<(ans-1+mod)%mod<<endl;
    return 0;
}
