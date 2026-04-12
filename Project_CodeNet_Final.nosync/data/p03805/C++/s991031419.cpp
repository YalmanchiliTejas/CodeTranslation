#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> v(n);
  vector<vector<bool>> graph(n, vector<bool> (n,0));
  for(int i=0; i<n; i++) v[i] = i;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    graph[--a][--b] = true;
    graph[b][a] = true;
  }
  do{
    bool flag = true;
    for(int i=1; i<n; i++) flag &= graph[v[i-1]][v[i]];
    ans += flag;
  }while(next_permutation(v.begin() + 1, v.end()));
  cout << ans << endl;
}