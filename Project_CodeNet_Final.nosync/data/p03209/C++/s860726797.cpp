#include <bits/stdc++.h>
/*#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
*/#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")    
using namespace std;
/*namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;
using Real = mp::number<mp::cpp_dec_float<1024>>;
*/#define lli long long int
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
Vec(P,lli,51,1);
Vec(Q,lli,51,1);
lli dfs(lli N,lli K){
  lli prs=0;
  if(!N)prs++;
  else if(K<2)prs+=0;
  else if(K<P[N-1]+2)prs+=dfs(N-1,K-1);
  else if(K==P[N-1]+2)prs+=1+Q[N-1];
  else if(K<P[N-1]*2+3)prs+=1+Q[N-1]+dfs(N-1,K-2-P[N-1]);
  else prs+=Q[N];
  return prs;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli A,B,C,D,E,H,W,M,K,L,R,N,num=0,sum=0,flag=0;string S,T;
  cin >> N >> K;
  rep(i,1,51)P[i]=P[i-1]*2+3;
  rep(i,1,51)Q[i]=Q[i-1]*2+1;
  Out(dfs(N,K));
}