#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
//typedef complex<D> P;
#define F first
#define S second
const ll MOD=1000000007;
//const ll MOD=998244353;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}

ll N;
vector<vector<ll>> edge;
bool jd=false;

bool dfs(ll u,ll p){
  int cnt=0;
  for(auto &v:edge[u]){
    if(v==p){continue;}
    if(dfs(v,u)){cnt++;}
  }
  if(cnt>=2){jd=true; return false;}
  if(cnt==1){return false;}
  if(p==-1){jd=true;}
  return true;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>N;
  edge.resize(N);
  for(int i=1;i<N;i++){
    int u,v;
    cin>>u>>v;
    u--; v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(0,-1);
  cout<<(jd?"First":"Second")<<endl;

  


  return 0;
}
