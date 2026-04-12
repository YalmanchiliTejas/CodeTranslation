#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
    int N; cin>>N;
    vi A(N);
    rep(i,0,N) cin>>A[i];
    vii dp(N+1,vi(N));
    REP(i,1,N){
        REP(j,0,N-i){
            dp[i][j]=max(A[j+i-1]-dp[i-1][j],A[j]-dp[i-1][j+1]);
        }
    }
    cout<<dp[N][0]<<endl;
}