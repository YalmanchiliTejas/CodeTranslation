#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int N,M,ans;
vector<bool> seen;
void dfs(vector<vector<int>> &G,int v,int cnt){
  seen[v]=true;
  cnt++;
  for(auto nv:G[v]){
    if(seen[nv]!=false) continue;
    dfs(G,nv,cnt);
  }
  seen[v]=false;
  if(cnt==N){
    ans++;
  }
}

int main()
{
  cin >> N >> M;
  ans=0;
  vector<P> A(M);
  vector<vector<int>> List(N,vector<int> ());
  REP(i,M){
    cin >> A[i].first >> A[i].second;
    A[i].first--;
    A[i].second--;
    List[A[i].first].push_back(A[i].second);
    List[A[i].second].push_back(A[i].first);
  }
  
  seen.assign(N,false);
  dfs(List,0,0);

  cout << ans << endl;
}