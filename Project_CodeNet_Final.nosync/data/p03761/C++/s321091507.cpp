#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N; cin >> N;
  vector<vector<lint> > alp(N, vector<lint> (26, 0));
  for(lint i = 0; i < N; i++){
    string s; cin >> s; 
    for(lint j = 0; j < s.size(); j++){
      alp[i][s[j] - 'a']++;
    }
  }
  string ans;
  for(lint i = 0; i < 26; i++){
    lint c = 200;
    for(lint j = 0; j < N; j++){
      c = min(c, alp[j][i]);
    }
    for(lint j = 0; j < c; j++) ans += char('a' + i);
  }
  cout << ans << endl;
}