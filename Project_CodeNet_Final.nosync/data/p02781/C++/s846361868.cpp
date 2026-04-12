#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 999999999999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(25) << S << endl
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define TV(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define mod 1000000007
#define MAX 10000000
#define ALL(a)  a.begin(),a.end()
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli A,B,C,D,E,F,N,M,K,L,X,Y,Z,H,W,sum=0,num=0,flag=0;string S,T;
  cin >> S >> K;
  N=S.size();
  lli dp[N][K+1][2];//dp[上位i桁確定][0でない数字がj個][未満フラグ]
  rep(i,0,N)rep(j,0,K+1)rep(k,0,2)dp[i][j][k]=0;
  rep(i,0,S[0]-'0'+1){
    if(i==S[0]-'0')dp[0][1][0]++;
    else{
      if(i>0)dp[0][1][1]++;
      else dp[0][0][1]++;
    }
  }
  rep(i,1,N){
    A=S[i]-'0';
    rep(j,0,K)rep(k,0,2){
      if(k){
        rep(l,1,A)dp[i][j+1][1]+=dp[i-1][j][0];
        if(A>0)dp[i][j+1][0]+=dp[i-1][j][0];
        if(A==0)dp[i][j][0]+=dp[i-1][j][0];
        else dp[i][j][1]+=dp[i-1][j][0];
      }
      else{
        dp[i][j+1][1]+=9*dp[i-1][j][1];
        dp[i][j][1]+=dp[i-1][j][1];
      }
    }
    if(A!=0)dp[i][K][1]+=dp[i-1][K][0]+dp[i-1][K][1];
    if(A==0){
      dp[i][K][0]+=dp[i-1][K][0];
      dp[i][K][1]+=dp[i-1][K][1];
    }
  }
  Out(dp[N-1][K][0]+dp[N-1][K][1]);
}
