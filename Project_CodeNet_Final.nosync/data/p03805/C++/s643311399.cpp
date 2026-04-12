#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
ll mod=1000000007;
const int limit_n = 8;
int mat[limit_n][limit_n];
int n,m;
int cnt=0;

void dfs(int node_id, vector<bool>& used){
  if(used[node_id]) return;
  auto used_cp = used;
  used_cp[node_id] = true;
  int cnt_used =0;
  for(int i=0; i<n;++i)if(used_cp[i]) ++cnt_used;
  if(cnt_used==n){
    ++cnt;
    return;
  }
  for(int j =0;j<n;++j){
    if(mat[node_id][j]==1) dfs(j,used_cp);
  }
}

int main() {
  cin >> n >> m;
  vector<bool> used(n, false);
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      mat[i][j] = 0;
    }
  }
  for(int j=0;j<m;++j){
    int a,b;cin >> a >> b;
    mat[a-1][b-1] = 1;
    mat[b-1][a-1] = 1;
  }
  dfs(0, used);
  cout << cnt << endl;

  return 0;
}
