#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<vector<int>> v(n + 1, vector<int>(26));
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < s.size(); j++){
      v.at(i).at(s.at(j) - 'a')++;
    }
  }
  
  for(int i = 0; i < 26; i++){
    int keep = 50;
    for(int j = 0; j < n; j++){
      keep = min(keep, v.at(j).at(i));
    }
    v.at(n).at(i) = keep;
  }
  
  for(int i = 0; i < 26; i++){
    char c = i + 'a';
    for(int j = 0; j < v.at(n).at(i); j++){
      cout << c;
    }
  }
  cout << endl;
}