#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){
  int n,m; cin >> n >> m;
  vector<vector<int>> to(n,vector<int>(0));
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    to.at(a).push_back(b);
    to.at(b).push_back(a);
  }
  queue<vector<int>> q;
  int ans = 0;
  q.push({0});
  while(q.size()){
    auto v = q.front(); q.pop();
    for(auto x:to.at(v.at(v.size()-1))){
      bool flag = 0;
      for(auto i:v){
        if(i==x) flag = 1;
      }
      if(flag) continue;
      auto w = v;
      w.push_back(x);
      q.push(w);
    }
    if(v.size() == n) ans++;
  }
  cout << ans << endl;

}