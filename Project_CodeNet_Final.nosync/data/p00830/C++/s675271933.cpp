#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

vector<string> split(string s, string t) {
	vector<string> ret;
	for(int i=0, n; i<=s.length(); i=n+1) {
		n = s.find_first_of(t, i);
		if(n == -1) n = s.length();
		string tmp = s.substr(i, n-i);
		ret.push_back(tmp);
	}
	return ret;
}

set<vector<string> > se;
set<vector<string> > dir;
set<vector<string> > file;

bool func(string &s) {
  vector<string> vs = split(s, "/");
  vector<string> res;
  //cout << s << endl;
  REP(i, vs.size()) {
    if (i && vs[i] == "") break;
    //cout << vs[i] << ":";
    if (vs[i] == ".") ;
    else if (vs[i] == "..") {
      if (dir.count(res) == 0) return 1;
      res.pop_back();
    }
    else res.push_back(vs[i]);
    if (se.count(res) == 0) return 1;
  }
  //cout << "OK" << endl;
  //cout << endl;
  if (vs[vs.size()-1]=="" || dir.count(res)) {
    res.push_back("index.html");
    //if (se.count(res) == 0) return 1;
  }
  if (file.count(res) == 0) return 1;
  s.clear();
  REP(i, res.size()) {
    if (i) s += "/";
    s += res[i];
  }
  // cout << s << endl;
  return 0;
}

int main() {
  int n,m;
  while(cin>>n>>m,n||m) {
    se.clear();
    dir.clear();
    file.clear();
    REP(i, n) {
      string s;
      cin >> s;
      vector<string> vs = split(s, "/");
      vector<string> tmp;
      REP(i, vs.size()) {
        tmp.push_back(vs[i]);
        se.insert(tmp);
        if (i != vs.size()-1)
          dir.insert(tmp);
        else
          file.insert(tmp);
      }
    }
    REP(i, m) {
      string s, t;
      cin >> s >> t;

      if (func(s) || func(t)) {
        cout << "not found" << endl;
      } else {
        if (s==t)
          cout << "yes" << endl;
        else
          cout << "no" << endl;
      }
    }
  }
}