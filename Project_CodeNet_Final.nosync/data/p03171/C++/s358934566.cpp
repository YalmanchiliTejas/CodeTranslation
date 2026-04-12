#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll N;
vector<ll> a;

//dp
vector<vector<ll>> table;

ll dp(ll i,ll j){
  if(i==j) return a.at(i);
  if(table.at(i).at(j)>-INF) return table.at(i).at(j);
  
  table.at(i).at(j)++;;
  chmax(table.at(i).at(j),a.at(i)-dp(i+1,j));
  chmax(table.at(i).at(j),a.at(j)-dp(i,j-1));
  
  return table.at(i).at(j);
}
    

int main()
{
  cin>>N;
  a=vector<ll>(N); rep(i,N) cin>>a.at(i);
  
  //dp
  table=vector<vector<ll>>(N,vector<ll>(N,-INF));

  cout<<dp(0,N-1)<<endl;
  return 0;
}