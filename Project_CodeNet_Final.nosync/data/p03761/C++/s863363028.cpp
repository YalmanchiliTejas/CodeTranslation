#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n; cin >> n;
  
  int table[n][26];
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      table[i][j] = 0;
    }
  }
  
  for (int i = 0; i < n; i++) {
    string S; cin >> S;
    
    for (int j = 0; j < S.size(); j++) {
      char tmpC = S.at(j);
      int tmpN = tmpC - 'a';
      table[i][tmpN]++;
    }
  }
  
  vector<int> ans(26, 51);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      ans[j] = min(ans[j], table[i][j]);
    }
  }
  
  for (int i = 0; i < 26; i++) {
    int tmpN = ans[i];
    char tmpC = i + 'a';
    for (int j = 0; j < tmpN; j++) cout << tmpC;
  }
  
  cout << endl;
  
}