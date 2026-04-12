//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<ll> T,P;

//dp
map<pair<ll,ll>,ll> table;

ll dp(ll i,ll x){
  if(x<=0) return 0;
  if(i<=0) return 1;
  if(table.count({i,x})) return table[{i,x}];
  
  if(x==1) return 0; x-=1;
  if(x<=T[i-1]) return dp(i-1,x); x-=T[i-1];
  if(x==1) return P[i-1]+1; x-=1;
  if(x<=T[i-1]) return dp(i-1,x)+P[i-1]+1;
  return P[i];
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // cout << fixed << setprecision(15);

  ll N,X; cin>>N>>X;
  
  T=vector<ll>(N+1,1); rep(i,N) T[i+1]=2*T[i]+3;
  P=vector<ll>(N+1,1); rep(i,N) P[i+1]=2*P[i]+1;
  
  //dp
  cout<<dp(N,X)<<endl;
  
  //rep(i,T[N]) cout<<dp(2,i+1)<<endl;
  return 0;
}