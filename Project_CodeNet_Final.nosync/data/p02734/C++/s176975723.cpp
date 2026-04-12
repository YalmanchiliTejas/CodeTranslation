#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 998244353
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
  int N,S; cin>>N>>S;
  vi A(N);
  rep(i,0,N) cin>>A[i];
  vii dp(N+1,vi(S+1));
  int ans=0;
  rep(i,0,N){
    dp[i][0]=i+1;
    REP(j,0,S) dp[i+1][j]=dp[i][j];
    if(A[i]<=S){
      ans+=dp[i][S-A[i]]*(N-i)%MOD;
      ans%=MOD;
      REP(j,A[i],S){
        dp[i+1][j]+=dp[i][j-A[i]];
        dp[i+1][j]%=MOD;
      }
    }
  }
  cout<<ans<<endl;
  }

