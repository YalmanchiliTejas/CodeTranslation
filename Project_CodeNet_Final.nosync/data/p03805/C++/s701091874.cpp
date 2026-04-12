#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int ans = 0, n;

void func(vector<vector<int> >& v, int id, map<int, int>& mp){
  if(mp[id] > 0){
    return;
  }
  mp[id]++;
  if(mp.size() == n){
    ans++;
    mp.erase(id);
    return;
  }
  for(int i = 0; i < v[id].size(); i++){
    func(v, v[id][i], mp);
  }
  mp.erase(id);
  return;
}

void solve(){
  int m; cin >> n >> m;
  vector<vector<int> > v(n + 1);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  map<int, int> mp;
  mp[1]++;
  for(int i = 0; i < v[1].size(); i++){
    func(v, v[1][i], mp);
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
