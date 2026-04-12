#include <bits/stdc++.h>
using namespace std;

int n,m;
int fin = 1;
vector<int> v[10];

int dfs(int a,int bit){
  if(bit == fin){
    return 1;
  }

  int ans = 0;
  for(int i = 0;i < v[a].size();i++){
    if((bit & (1 << v[a][i])) == 0){
      ans += dfs(v[a][i],bit | (1 << v[a][i]));
    }
  }
  return ans;
}

int main(){
  cin >> n >> m;
  for(int i = 0;i < n;i++) fin*= 2;
  fin--;
  int a,b;
  for(int i = 0;i < m;i++){
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  cout << dfs(0,1) << endl;
  return 0;
}
