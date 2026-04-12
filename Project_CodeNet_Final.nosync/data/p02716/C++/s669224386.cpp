#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<double> Vec;
typedef vector<Vec> Mat;
typedef pair<ll,ll> P;
typedef pair<double,ll> Pd;
typedef pair<double,double> PD;
typedef priority_queue<P,vector<P>,greater<P> > P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd> > Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-6;


#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod
#define MUL(a,b) a=(a*b)%mod

ll dp[200010][3][2];

int main(){
    ll N; cin>>N;
    vec d(N); 
    rep(i,N) cin>>d[i];
    rep(i,200010) rep(j,3) rep(k,2) dp[i][j][k]=-INF;
    dp[0][0][0]=0;
    rep(i,N) rep(j,3){
        dp[i+1][j][1]=dp[i][j][0]+d[i];
        dp[i+1][j][0]=dp[i][j][1];
        if(j>0) dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j-1][0]);
    }
    ll ans=-INF;
    if(N%2) ans=max(dp[N][1][0],dp[N][2][1]);
    else ans=max(dp[N][0][0],dp[N][1][1]);
    cout<<ans<<endl;

}