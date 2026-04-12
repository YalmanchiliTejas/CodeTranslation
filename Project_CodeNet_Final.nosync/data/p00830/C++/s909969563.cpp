#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <sstream>
using namespace std;

set<string> S;
set<string> F;

void init() {
  S.clear();
  F.clear();
}

void insert(string &s) {
  F.insert(s);
  for(int i = 1; i < s.size(); ++i) {
    if(s[i-1] == '/') {
      S.insert(s.substr(0,i));
      //      cout << s.substr(0,i) << endl;
    }
  }
}

bool isValid(const string &s) {
  if(s[(int)s.size()-1] != '/' && F.count(s)) return true;
  if(s[(int)s.size()-1] == '/' && S.count(s)) return true;
  if(s[(int)s.size()-1] != '/' && S.count(s+"/")) return true;
  return false;
}

string cut(string s) {
  string sum = "";
  string tmp = "";
  for(int begin = 0, i = 1; i <= s.size(); ++i) {
    if(i == s.size() || s[i-1] == '/') {
      string t = s.substr(begin,i-begin);
      begin = i;
      if(t == "../" || t == "..") {
	if(sum.size() <= 1) return "";
	int j;
	for(j = (int)sum.size()-2; j >= 0 && sum[j] != '/'; --j);
	sum = sum.substr(0,j+1);
      } else if(t != "./" && t != ".") {
	sum += t;
      }
      if(!isValid(sum)) return "";
    }
  }
  return sum;
}

int main() {
  int n, m;
  while(cin >> n >> m && (n|m)) {
    init();
    for(int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      insert(s);
    }
    for(int i = 0; i < m; ++i) {
      string s, t;
      cin >> s >> t;
      s = cut(s);
      t = cut(t);
      if(s == "" || t == "") {
	cout << "not found" << endl;
      } else {
	vector<string> v[2];
	if(s[(int)s.size()-1] != '/') {
	  v[0].push_back(s);
	  s += '/';
	}
	v[0].push_back(s+"index.html");
	if(t[(int)t.size()-1] != '/') {
	  v[1].push_back(t);
	  t += '/';
	}
	v[1].push_back(t+"index.html");
	bool flag = false;
	int p = 0;
	for(int i = 0; i < v[0].size() && !flag; ++i) {
	  for(int j = 0; j < v[1].size() && !flag; ++j) {
	    if(F.count(v[0][i])) p |= 1;
	    if(F.count(v[1][j])) p |= 2;
	    if(F.count(v[0][i]) && F.count(v[1][j]) && v[0][i] == v[1][j]){ 
	      flag = true;
	    }
	  }
	}
	if(p != 3) cout << "not found" << endl;
	else if(flag) cout << "yes" << endl;
	else cout << "no" << endl;
      }
    }
  }
  return 0;
}