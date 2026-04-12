#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<char, int> cnt;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    int l = s.size();
    map<char, int> next, now;
    for(int j = 0; j < l; j++){
      char c = s.at(j);
      now[c]++;
      if(i == 0) cnt[c]++;
    }
    for(auto a : now){
      if(!cnt.count(a.first)) continue;
      int k = min(a.second, cnt.at(a.first));
      next[a.first] = k;
    }
    cnt = next;
  }
  
  vector<char> ans(0);
  for(auto a : cnt){
    for(int i = 0; i < a.second; i++){
      ans.push_back(a.first);
    }
  }
  sort(ans.begin(), ans.end());
  
  for(auto a : ans) cout << a;
  cout << endl;
}