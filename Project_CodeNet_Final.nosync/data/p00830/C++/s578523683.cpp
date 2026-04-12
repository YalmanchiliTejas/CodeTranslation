#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <vector>
using namespace std;

set<string> D, F;

void insert(const string &s) {
  F.insert(s);
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == '/') D.insert(s.substr(0,i+1));
  }
}

string cut(string s) {
  string in;
  string t = "/";
  bool isD = *s.rbegin() == '/';
  replace(s.begin(), s.end(), '/', ' ');
  stringstream ss(s);
  while(ss >> in) {
    if(in == ".") continue;
    if(in == "..") {
      if(t.size() < 2) return "";
      int p = t.rfind('/',(int)t.size()-2);
      t.erase(p+1);
    } else {
      t += in;
      if(!ss.eof() || isD) {
	t += "/";
	if(!D.count(t)) return "";
      }
    }
  }
  return t;
}

int main() {
  int N, M;
  while(cin >> N >> M && N|M) {
    F.clear();
    D.clear();
    string s, t;
    while(N--) {
      cin >> s;
      insert(s);
    }
    while(M--) {
      cin >> s >> t;
      s = cut(s);
      t = cut(t);
      if(s == "" || t == "") {
	cout << "not found" << endl;
	continue;
      }
      vector<string> a,b;
      if(*s.rbegin() == '/') {
	a.push_back(s+"index.html");
      } else {
	a.push_back(s);
	a.push_back(s+"/index.html");
      }
      if(*t.rbegin() == '/') {
	b.push_back(t+"index.html");
      } else {
	b.push_back(t);
	b.push_back(t+"/index.html");
      }
      int found = 0;
      bool yes = false;
      for(int i = 0; i < a.size() && !yes; ++i) {
	for(int j = 0; j < b.size() && !yes; ++j) {
	  bool fa, fb;
	  fa = F.count(a[i]);
	  fb = F.count(b[j]);
	  if(fa) found |= 1;
	  if(fb) found |= 2;
	  if(fa && fb && a[i] == b[j]) yes = true;
	}
      }
      if(found != 3) cout << "not found" << endl;
      else if(yes) cout << "yes" << endl;
      else cout << "no" << endl;
    }
  }
  return 0;
}