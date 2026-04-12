
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;


int hoge(){
  int n;
  cin >> n;

  set<char> char_set;
  vector<map<char, int>> c_frq_maps(n);
  for (int i = 0; i < n; ++i) {

    //
    string s;
    cin >> s;
    for(char c: s){
      char_set.insert(c);

      if(c_frq_maps[i].count(c) == 0) c_frq_maps[i][c] = 1;
      else c_frq_maps[i][c] += 1;
    }
//    for(auto kv: c_frq_maps[i]) cout << kv.first << " " << kv.second << endl;
//    cout << "-- -- --" << endl;
  }

  //
  vector<char> chars;
  for(char c: char_set){
    int m = n+1;
    for(auto c_frq_map: c_frq_maps){
//      cout << c << " " << m << endl;
      m = min(m, c_frq_map[c]);
    }

    for (int i = 0; i < m; ++i) {
      chars.push_back(c);
    }
  }

  sort(chars.begin(), chars.end());
  for(char c: chars) cout << c;
  cout << endl;

}

int main() {
  //
  int n;
  cin >> n;

  vector<vector<int>> table(n, vector<int>(26, 0));
  for (int i = 0; i < n; ++i) {

    //
    string s;
    cin >> s;
    for (char c: s) {
      table[i][c -'a']++;
    }
  }

  for (int i = 0; i < 26; ++i) {
    int m = 2500;
    for (int j = 0; j < n; ++j) {
      m = min(m, table[j][i]);
    }
    char c = 'a' + i;
    for (int j = 0; j < m; ++j) {
      cout << c;
    }
  }

  cout << endl;

  return 0;
}

