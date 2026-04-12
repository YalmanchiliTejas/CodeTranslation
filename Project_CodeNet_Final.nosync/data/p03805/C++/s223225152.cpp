#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define pb push_back
#define REP(i,m,n) for (int i=m;i<n;i++)
#define FOR(i,m,n,a) for(int i=m;i<n;i+=a)
const ll MOD=1e9+7;


vvl graph;
int ct=0;

bool check(vl visit){
  REP(i,0,visit.size()){
    if(visit[i]==0){
      return false;
    }
  }
  return true;
}

void dfs(int n,vl visit){
  visit[n]=1;
  REP(i,0,graph[n].size()){
    if(visit[graph[n][i]]==0){
      dfs(graph[n][i],visit);
    }
  }

  if(check(visit)) ct++;
}

int main(){
  int N,M;
  cin >> N >> M;
  graph = vvl(N);

  int a,b;
  REP(i,0,M){
    cin >> a >> b;
    graph[a-1].pb(b-1);
    graph[b-1].pb(a-1);
  }

  vl visit(N,0);
  dfs(0,visit);

  cout << ct << endl;

  return 0;
}
