#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<string> s(n);
  for(int i=0; i<n; ++i) cin >> s[i];
  
  vector<vector<int>> letter(n, vector<int>(26, 0));
  for(int i=0; i<n; ++i){
    for(char x : s[i]){
      ++letter[i][(int)x - 97];
    }
  }
  
  vector<bool> use(26, true);
  for(int i=0; i<n; ++i){
    for(int j=0; j<26; ++j){
      if(letter[i][j] == 0){
        use[j] = false;
      }
    }
  }
  
  vector<int> res(26, 0);
  for(int i=0; i<26; ++i){
    if(!use[i]) continue;
    int minuse = letter[0][i];
    for(int j=1; j<n; ++j){
      minuse = min(minuse, letter[j][i]);
    }
    res[i] = minuse;
  }

  for(int i=0; i<26; ++i){
    if(res[i] == 0) continue;
    char c = (char)(i+97);
    for(int j=0; j<res[i]; ++j){
      cout << c;
    }
  }
  cout << endl;
  
  return 0;
}