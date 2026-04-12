#include <bits/stdc++.h>
using namespace std;

int N, M;
set<string> dir, file;

string conv(string s, bool check) {
  bool flag = *s.rbegin() == '/';
  replace(s.begin(), s.end(), '/', ' ');
  deque<string> deq;
  string now = "";
  for(stringstream ss(s); ss >> s; ) {
    if(check) {
      if(!dir.count(now + "/")) return "#";
    } else {
      dir.insert(now + "/");
    }
    if(s == "..") {
      if(deq.empty()) return "#";
      now = deq.back();
      deq.pop_back();
    } else if(s == ".") {
      //
    } else {
      deq.push_back(now);
      now += "/" + s;
    }
  }
  if(flag) now += "/";
  return now;
}

int main() {
  for(; cin >> N >> M && (N|M); ) {
    dir.clear();
    file.clear();
    for(int i = 0; i < N; ++i) {
      string s;
      cin >> s;
      file.insert(conv(s, false));
    }
    while(M--) {
      string a, b;
      cin >> a >> b;
      a = conv(a, true);
      b = conv(b, true);
      vector<string> va, vb;
      if(*a.rbegin() == '/') {
        va.push_back(a + "index.html");
      } else {
        va.push_back(a);
        va.push_back(a + "/index.html");
      }
      if(*b.rbegin() == '/') {
        vb.push_back(b + "index.html");
      } else {
        vb.push_back(b);
        vb.push_back(b + "/index.html");
      }
      int res = 0;
      for(int i = 0; i < va.size(); ++i) {
        if(!file.count(va[i])) continue;
        for(int j = 0; j < vb.size(); ++j) {
          if(!file.count(vb[j])) continue;
          res = max(res, 1);
          if(va[i] == vb[j]) {
            res = 2;
          }
        }
      }
      if(res == 0) cout << "not found" << endl;
      else if(res == 1) cout << "no" << endl;
      else cout << "yes" << endl;
    }
  }
  return 0;
}