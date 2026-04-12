#include <iostream>
#include <map>
#include <vector>
using namespace std;
using Map = map<char, int>;

template <class T> inline bool chmin(T& a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  string s;
  vector<Map> maps(n);
  for(int i = 0; i < n; ++i) {
    cin >> s;
    for(int j = 0; j < s.size(); ++j) {
      maps[i][s[j]]++;
    }
  }

  for(int i = 0; i < 26; ++i) {
    int mnv = 1000;
    char a = 'a' + i;
    for(int j = 0; j < maps.size(); ++j) {
      chmin(mnv, maps[j][a]);
    }
    for(int j = 0; j < mnv; ++j) {
      cout << a;
    }
  }
  cout << endl;
  return 0;
}