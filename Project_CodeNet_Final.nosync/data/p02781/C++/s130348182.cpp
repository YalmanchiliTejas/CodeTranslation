#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#include<queue>
#define ll long long
#define itn int
#define co(ans) cout<<ans<<endl;
#define COYE cout<<"YES"<<endl;
#define COYe cout<<"Yes"<<endl;
#define COye cout<<"yes"<<endl;
#define CONO cout<<"NO"<<endl;
#define CONo cout<<"No"<<endl;
#define COno cout<<"no"<<endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;


int main(){
  string S;
  cin>>S;
  int K;
  cin>>K;
  ll ans=0;
  
  
  long long dp[101][2][5];
  // dp[決めた桁数][未満フラグ][0でない数を使った回数]
  
  int L=S.size();
  fill((long long*)dp,(long long*)dp+sizeof(dp)/sizeof(long long),0);
  dp[0][0][0]=1;
  
  for(int i=0; i<L; ++i){
  int D=S[i]-'0';
    for(int j=0; j<2; ++j){
	  for(int k=0; k<5; ++k){
		for(int d=0; d<=(j?9:D); ++d){
		  if(d>0 && k<=3) dp[i+1][j||(d<D)][k+1]+=dp[i][j][k];
          if(d==0 && k<=3) dp[i+1][j||(d<D)][k]+=dp[i][j][k];
        }
      }
    }
  }
  
  cout<<dp[L][0][K]+dp[L][1][K]<<endl;
  return 0;
}