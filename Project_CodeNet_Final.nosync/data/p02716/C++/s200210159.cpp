#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;

int main(void){
    int N;
    cin >> N;
    lint A[N];
    rep(i,N) cin >> A[i];
    lint dp[N+5][5]={};
    int K=N%2?2:1;
    rep(i,N+5) rep(j,5) dp[i][j]=-LINF;
    dp[0][0]=0,dp[1][0]=A[0];
    if(N>=2) dp[2][1]=A[1];
    if(N>=3) dp[3][2]=A[2];
    rep(i,N) rep(j,3){
        if(i+2>N) continue;
        dp[i+2][j]=max(dp[i+2][j],dp[i][j]+A[i+1]);
        if(i+3>N) continue;
        dp[i+3][j+1]=max(dp[i+3][j+1],dp[i][j]+A[i+2]);
        if(i+4>N) continue;
        dp[i+4][j+2]=max(dp[i+4][j+2],dp[i][j]+A[i+3]);
    }
    lint ans=max(dp[N][K],dp[N-1][K-1]);
    if(K==2) ans=max(ans,dp[N-2][0]);
    cout << ans << endl;
}