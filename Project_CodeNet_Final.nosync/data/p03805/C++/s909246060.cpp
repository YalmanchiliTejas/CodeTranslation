#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define INF (1e9)
#define MOD (1e9+7)

/////////////////////////////////////////////////////////

void DFS(vector<vector<int>> V, vector<int> P, int cur , int &res){
  P.push_back(cur);
  if(P.size() == V.size()) res++;
  else{
    rep(i, 0, V[cur].size()){
      if(find(all(P), V[cur][i]) != P.end()) continue;
      DFS(V, P, V[cur][i], res);
    }
  }
}

void Main(){
  int N, M; cin >> N >> M;
  vector<vector<int>> V(N);
  rep(i, 0, M){
    int a, b; cin >> a >> b;
    a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  vector<int> P;
  int res = 0;
  DFS(V, P, 0, res);
  cout << res << endl;
}

/////////////////////////////////////////////////////////

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout << std::fixed << std::setprecision(15);

  Main();
}
