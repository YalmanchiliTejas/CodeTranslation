#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i = 0; i < n; i++) {
    cin >> s.at(i);
  }
  int alp = 26;
  vector<string> ans;
  for(int i = 0; i < alp; i++) {
    int cnt = 10000;
    for(int j = 0; j < n; j++) {
      int tmp = 0;
      for(int k = 0; k < s.at(j).size(); k++) {
        if('a' + i == s.at(j).at(k)) {
          tmp++;
        }
      }
      cnt = min(tmp, cnt);
    }
    for(int l = 0; l < cnt; l++) {
      cout << char('a' + i);
    }
  }
  cout << endl;
}
