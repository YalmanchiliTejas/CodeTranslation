#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;

const int nmax = 8;
bool graph[8][8];

int dfs(int v, int n, bool visit[nmax]){

  bool check = true;
  
  REP(i,n){
    if(!visit[i]) check = false;
  }
  
  if(check) return 1;
  
  int sum = 0;
  
  REP(i,n){
    if(!graph[v][i]) continue;  //パスが存在して
    if(visit[i]) continue;      //未訪問ならば
    visit[i] = true;
    sum += dfs(i,n,visit);
    visit[i] = false;
  }
  
  return sum;
 
}
  


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  
  REP(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    graph[a][b] = graph[b][a] = true;
  }
  
  bool visit[n];
  REP(i,n) visit[i] = false;
  visit[0] = true;

  cout << dfs(0,n,visit) << endl;
  
  return 0;
}