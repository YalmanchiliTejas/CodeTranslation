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
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    vector<vector<ll>> dp(N,vector<ll>(N,0));
    rep(i,N) dp[i][i]=a[i];
    rep(j,N){
        rep(i,N){
            if (j==0) dp[i][i+j]=a[i];
            if (j==0||i+j>=N) continue;
            dp[i][i+j]=max(a[i]-dp[i+1][i+j],a[i+j]-dp[i][i+j-1]);
        }
    }
    cout << dp[0][N-1] << endl;
}