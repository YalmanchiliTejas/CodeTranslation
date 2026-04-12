#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int MAX_L = 301;

int T[MAX_L][MAX_L];
pair<int, int> prev[MAX_L][MAX_L];

string LCS(const string &s, const string &t) {
  for(int i = 1; i <= s.size(); ++i) {
    for(int j = 1; j <= t.size(); ++j) {
      int tmp = T[i-1][j-1];
      if(s[i-1] == t[j-1]) ++tmp;
      T[i][j] = max(max(T[i-1][j], T[i][j-1]), tmp);
      if(T[i][j] == T[i-1][j]) {
	prev[i][j] = make_pair(i-1, j);
      } else if(T[i][j] == T[i][j-1]) {
	prev[i][j] = make_pair(i, j-1);
      } else if(T[i][j] == tmp) {
	prev[i][j] = make_pair(i-1, j-1);
      }
    }
  }

  string res = "";
  pair<int, int> p(s.size(), t.size());
  int size = T[s.size()][t.size()];
  while(size) {
    p = prev[p.first][p.second];
    if(size != T[p.first][p.second]) {
      size = T[p.first][p.second];
      res += s[p.first];
    }
  }
  reverse(res.begin(), res.end());
  return res;
}


int main() {
  T[0][0] = 0;
  for(int i = 0; i < MAX_L; ++i) T[i][0] = T[0][i] = 0;

  string str;
  while(getline(cin, str) && str != "#END") {
    string ans = "";
    for(int i = 1; i < str.size(); ++i) {
      string s = str.substr(0, i);
      string t = str.substr(i);
      string res = LCS(s, t);
      if(res.size() > ans.size()) ans = res;
    }
    cout << ans << endl;
  }
  return 0;
}