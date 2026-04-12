#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;

#define REP(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

class P{
public:
  string name;
  bool file;  //true : is file, false : is folder
  vector<int> child;
  int par;

  P(string _name, bool _file, vector<int> _child, int _par){
    name = _name;
    file = _file;
    child = _child;
    par = _par;
  }
};

vector<string> split(string s){
  vector<string> res;
  int i = 1;
  int n = s.length();

  while(true){
    string ts = "";

    while(i < n && s[i] != '/'){
      ts += s[i];
      i++;
    }

    if(ts != ""){
      res.push_back(ts);
    }

    if(ts == "" || i == n){
      break;
    }
    i++;
  }

  return res;
}

vector<P> t;

int getNext(const vector<int> &v, string s){
  for(int i = 0; i < v.size(); i++){
    int to = v[i];
    if(t[to].name == s){
      return to;
    }
  }

  return -1;
}

void addPage(const vector<string> &v){
  int n = v.size();
  int now = 0;

  for(int i = 0; i < n; i++){
    int next = getNext(t[now].child, v[i]);

    if(next == -1){
      t[now].child.push_back(t.size());
      t.push_back(P(v[i], (i == n - 1), vector<int>(), now));
      now = t.size() - 1;
    }
    else{
      now = next;
    }
  }
}

int getPage(const vector<string> &v, bool flg){
  int n = v.size();
  int now = 0;

  for(int i = 0; i < n; i++){
    //cout << now<<","<<t[now].name<<","<<t[now].file<<","<<i<<endl;

    if(t[now].file && i != n - 2){
      return -1;
    }

    if(v[i] == "."){
      continue;
    }
    if(v[i] == ".."){
      if(t[now].par == -1) return -1;
      now = t[now].par;
      continue;
    }

    int next = getNext(t[now].child, v[i]);

    if(next == -1){
      return -1;
    }
    else{
      now = next;
    }
  }

  if(!t[now].file || flg){
    now = getNext(t[now].child, "index.html");
  }
  if(!t[now].file) return -1;

  return now;
}

void showTree(){
  for(int i = 0; i < t.size(); i++){
    cout << i << " : ";
    cout << t[i].name << "(" << t[i].file << ") : ";
    for(int j = 0; j < t[i].child.size(); j++){
      cout << t[i].child[j] << ",";
    }
    cout<<endl;
  }
}

int main(){
  int n, m;

  while(cin >> n >> m, n || m){
    t.clear();
    t.push_back(P("/", false, vector<int>(), -1));

    for(int i = 0; i < n; i++){
      string s;
      cin >> s;

      vector<string> v = split(s);
      addPage(v);
    }

    //showTree();

    for(int i = 0; i < m; i++){
      string a, b;
      cin >> a >> b;

      vector<string> va = split(a);
      int ida = getPage(va, a[a.length() - 1] == '/');

      vector<string> vb = split(b);
      int idb = getPage(vb, b[b.length() - 1] == '/');

      if(ida == -1 || idb == -1){
        cout << "not found\n";
      }
      else if(ida == idb){
        cout << "yes\n";
      }
      else{
        cout << "no\n";
      }
    }
  }
}