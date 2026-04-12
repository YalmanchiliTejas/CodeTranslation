#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    string K;
    ll D;
    cin >> K >> D;
    ll s=K.size();
    ll dp[s+1][D][2];
    rep(i,s+1) rep(j,D) rep(k,2) dp[i][j][k]=0;
    dp[0][0][1]=1;
    rep(i,s){
        rep(j,D){
            rep(k,2){
                if (k==0) rep(l,10) dp[i+1][(j+l)%D][0]=(dp[i+1][(j+l)%D][0]+dp[i][j][k])%MOD;
                else {
                    int t=K[i]-'0';
                    rep(l,t) dp[i+1][(j+l)%D][0]=(dp[i+1][(j+l)%D][0]+dp[i][j][k])%MOD;
                    dp[i+1][(j+t)%D][1]=(dp[i+1][(j+t)%D][1]+dp[i][j][k])%MOD;
                }
            }
        }
    }
    cout << (dp[s][0][0]+dp[s][0][1]+MOD-1)%MOD << endl;
}