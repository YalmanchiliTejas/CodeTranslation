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
vector<vector<bool>> checked;
vector<vector<ll>> table;

ll dp(ll i,ll j){
  if(i==j) return 0;
  if(checked.at(i).at(j)) return table.at(i).at(j);
  
  checked.at(i).at(j)=true;
  if((N-(j-i))%2==0){
    table.at(i).at(j)=-INF;
    chmax(table.at(i).at(j),dp(i+1,j)+a.at(i));
    chmax(table.at(i).at(j),dp(i,j-1)+a.at(j-1));
  }
  else{
    table.at(i).at(j)=INF;
    chmin(table.at(i).at(j),dp(i+1,j)-a.at(i));
    chmin(table.at(i).at(j),dp(i,j-1)-a.at(j-1));
  }
  
  return table.at(i).at(j);
}

int main()
{
  cin>>N;
  a=vector<ll>(N); rep(i,N) cin>>a.at(i);
  
  //dp
  checked=vector<vector<bool>>(N+1,vector<bool>(N+1,false));
  table=vector<vector<ll>>(N+1,vector<ll>(N+1));
  
  cout<<dp(0,N)<<endl;
  return 0;
}