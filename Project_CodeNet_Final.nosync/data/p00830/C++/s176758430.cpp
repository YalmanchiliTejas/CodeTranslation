#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

vector<string> spl(string s) {
  vector<string> res;
  int old = 1;
  while(1) {
    int p = s.find("/", old);
    if (p == string::npos) break;
    res.push_back(s.substr(old, p-old));
    old = p + 1;
  }
  res.push_back(s.substr(old));
  return res;
}

pair<bool, vector<string>> ff(vector<vector<string>>& lst, vector<string>& file) {
  vector<string> path;
  bool isdir = true;
  int n = lst.size();
  bool added = false;
  for (string name:file) {
    if (name == ".") continue;
    if (name == "..") {
      if (path.empty() || !isdir) return make_pair(false, path);
      else {
        path.pop_back();
        continue;
      }
    }
    bool fnd = false;
    REP(i,n){
      bool ok = lst[i].size() > path.size();
      REP(j,path.size()) {
        if (lst[i].size() <= j || path[j] != lst[i][j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        if (name == lst[i][path.size()]) {
          path.push_back(name);
          isdir = (path.size() != lst[i].size());
          fnd = true;
          break;
        } else if (name == "" && lst[i].size() == path.size() + 1 && lst[i][path.size()] == "index.html") {
          path.push_back("index.html");
          fnd = true;
          added = true;
          break;
        }
      }
    }
    if (!fnd) return make_pair(false, path);
  }
  REP(i,n) {
    if (path == lst[i]) return make_pair(true, path);
    if (path.size() + 1 != lst[i].size()) continue;
    bool ok = true;
    REP(j,path.size()) {
      if (path[j] != lst[i][j]) {
        ok = false;
        break;
      }
    }
    if (! added && ok && lst[i].back() == "index.html") {
      return make_pair(true, lst[i]);
    }
  }
  return make_pair(false, path);
}

int main() {
  while(1){
    int n,m;
    cin>>n>>m;
    if(!n)break;
    vector<vector<string>> f(n);
    REP(i,n) {
      string fp;
      cin>>fp;
      f[i] = spl(fp);
    }
    REP(i,m) {
      string a,b;
      cin>>a>>b;
      auto fa = spl(a);
      auto fb = spl(b);
      auto pa = ff(f, fa);
      auto pb = ff(f, fb);
      if (pa.first && pb.first) {
        if (pa.second == pb.second) {
          cout << "yes" << endl;
        } else {
          cout << "no" << endl;
        }
      } else {
        cout << "not found" << endl;
      }
    }
  }
  return 0;
}