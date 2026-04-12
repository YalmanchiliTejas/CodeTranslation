#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int n; cin >> n;
  vector<vector<int>> v(n, vector<int>(26, 0));
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < s.size(); j++){
      v[i][(int)(s[j] - 'a')]++;
    }
  }
  for(int i = 0; i < 26; i++){
    int minv = v[0][i];
    for(int j = 1; j < n; j++){
      minv = min(v[j][i], minv);
    }
    for(int j = 0; j < minv; j++) cout << (char)('a' + i);
  }
  cout << endl;
  return;
}

int main(){
  solve();
  return 0;
}
