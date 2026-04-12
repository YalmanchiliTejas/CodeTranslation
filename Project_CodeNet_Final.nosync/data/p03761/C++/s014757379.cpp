#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string w;
  cin >> w;
  map<char, int> cnt;
  for(int i = 0; i < w.length(); i++) cnt[w[i]]++;
  for(int i = 1; i < n; i++){
    string s;
    cin >> s;
    map<char, int> cnt_s;
    for(int j = 0; j < s.length(); j++) cnt_s[s[j]]++;
    for(auto p: cnt){
      if(cnt_s[p.first] == 0) cnt[p.first] = 0;
      else if(p.second > cnt_s[p.first]) cnt[p.first] = cnt_s[p.first];
    }
  }
  for(auto p: cnt){
    for(int i = 0; i < p.second; i++) cout << p.first;
  }
  return 0;
}