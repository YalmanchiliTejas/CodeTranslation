#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")    
using namespace std;
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
#define lli long long int
#define uli unsigned long long int
#define INF 999999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(50) << S << endl
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define TV(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define mod 998244353
#define MAX 10000000
#define ALL(a)  a.begin(),a.end()
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli A,B,C,D,E,H,W,M,K,L,R,N,num=0,sum=0,flag=0;string S,T;
  cin >> N >> K;
  DV(dp,lli,N,K+100,0);//dp[i][j]:=i番目まで見たとき，和がjにすることができる区間数
  Vec(P,lli,N,0);
  rep(i,0,N)cin >> P[i];
  if(P[0]<=K)dp[0][P[0]]=1;
  rep(i,0,N)dp[i][0]=1;
  rep(i,1,N)rep(j,0,K+1){
    if(j+P[i]<=K&&j)dp[i][j+P[i]]=(dp[i][j+P[i]]+dp[i-1][j])%mod;
    else if(j+P[i]<=K&&!j)dp[i][j+P[i]]=(dp[i][j+P[i]]+dp[i-1][j]+1)%mod;
    dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
  }
  /*rep(i,0,N){
    rep(j,0,K+1)cout << dp[i][j] << " ";
    Out("");
  }*/
  rep(i,0,N)sum+=dp[i][K];
  Out(sum%mod);
}