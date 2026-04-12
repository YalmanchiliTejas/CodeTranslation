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
  string S; cin>>S;
  int K; cin>>K;
  int N=S.size();
  vii dp(N,vi(K));
  vi cp(N);
  rep(i,0,S[0]-'0') dp[0][i%K]++;
  cp[0]=(S[0]-'0')%K;
  rep(i,1,N){
    int X=S[i]-'0';
    rep(j,0,K){
      rep(l,0,10){
        dp[i][(j+l)%K]+=dp[i-1][j];
        dp[i][(j+l)%K]%=MOD;
      }
    }
    rep(j,0,X){
      dp[i][(cp[i-1]+j)%K]++;
      dp[i][(cp[i-1]+j)%K]%=MOD;
    }
    cp[i]=(cp[i-1]+X)%K;
  }
  int ans=(dp[N-1][0]+MOD-1)%MOD;
  if(cp[N-1]==0) ans=(ans+1)%MOD;
  cout<<ans<<endl;
  }

