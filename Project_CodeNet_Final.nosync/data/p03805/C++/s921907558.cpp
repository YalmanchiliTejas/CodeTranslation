#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int ans = 0;
int bfs(int x, vector<int> a, vector<vector<int>> r){
  a[x] = 1;
  bool flag = true;
  rep(i,a.size()) if(a[i] != 1) flag = false;
  if(flag) {
    ans++;
    return 0;
  }
  
  rep(i,r[x].size()) if(a[r[x][i]] == 0)bfs(r[x][i], a, r);
  
  return 0;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  vector<vector<int>> r(n);
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    r[a[i]].push_back(b[i]);
    r[b[i]].push_back(a[i]);
  }

  vector<int> arr(n,0);
  bfs(0,arr,r);
  cout << ans << endl;
  return 0;
}
