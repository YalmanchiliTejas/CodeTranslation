#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
int main(){
  pair<int, int> tmp;
  vector< pair<int, int> > team;
  while(scanf("%d,%d", &tmp.second, &tmp.first)){
    if(tmp.first == 0 && tmp.second == 0) break; 
    team.push_back(tmp);
  }
  sort(team.rbegin(), team.rend());
  
  int cnt = 1;
  map<int, int> ans;
  
  ans.insert(make_pair(team[0].second, cnt));
  
  for(int i = 1 ; i < team.size() ; i++){
    if(team[i-1].first > team[i].first) ++cnt;
    ans.insert(make_pair(team[i].second, cnt));
  }
  
  int n;
  while(cin >> n){
    cout << ans[n] << endl;
  }
  return 0;
}