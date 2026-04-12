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



int main()
{
  ll N,M; cin>>N>>M;
  vector<vector<int>> graph(N,vector<int>(N,0));
  rep(i,M){
    ll a,b; cin>>a>>b; a--,b--;
    graph[a][b]=1;
    graph[b][a]=1;
  }
  
  ll ans=0;
  vector<ll> vec(N);
  rep(i,N) vec.at(i)=i;
  do{
    if(vec[0]!=0) break;
    ll judge=1;
    rep(i,N-1){
      ll s=vec[i],g=vec[i+1];
      if(!graph[s][g]) judge=0;
    }
    if(judge) ans++;
  }while(next_permutation(vec.begin(),vec.end()));
  
  cout<<ans<<endl;
  return 0;
}
