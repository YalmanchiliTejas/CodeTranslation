#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int ID;
struct file{
  string name;
  bool dir;
  int id;
  map<string, file> sub;
  file* parent;
  file() {}
  file(string name, bool dir, file* par) : dir(dir), parent(par), name(name) {
    if(dir) id = -8;
    else id = ID++;
  }
  file* make(string name, bool d){
    //printf("%s make %s\n", this->name.c_str(), name.c_str());
    sub[name] = file(name, d, (d) ? this : NULL);
    return &(sub[name]);
  }
};

vector<string> make_path(string s){
  bool f = (s[s.size() - 1] == '/');
  REP(i, s.size()) if(s[i] == '/') s[i] = ' ';
  stringstream ss(s);
  vector<string> path;
  while(ss>>s) path.push_back(s);
  if(f) path.push_back(".");
  return path;
}

int get_file(vector<string> path, file* cur){
  //cout<<"get_file"<<endl;
  REP(i, path.size()){
    if(path[i] == "."){
      if(!cur->dir) return -1;
    }else if(path[i] == ".."){
      if(!cur->dir) return -1;
      cur = cur->parent;
      if(!cur) return -3;
    }else if(!cur->sub.count(path[i])){
      //cout<<"not found "<<path[i]<<endl;
      return -1;
    }else{
      cur = &(cur->sub[path[i]]);
    }
    //cout<<cur->name<<endl;
  }
  if(cur->dir){
    if(cur->sub.count("index.html")){
      cur = &(cur->sub["index.html"]);
    }else{
      //cout<<"not found "<<"index.html"<<endl;
      return -2;
    }
  }
  return cur->id;
}

int main(){
  int N, M;
  while(cin>>N>>M && N){
    ID = 0;
    file root("root", true, NULL);
    REP(i, N){
      string s; cin>>s;
      vector<string> path = make_path(s);
      file* cur = &root;
      REP(i, path.size()){
        if(cur->sub.count(path[i])){
          cur = &(cur->sub[path[i]]);
        }else{
          cur = cur->make(path[i], (i != path.size() - 1));
        }
      }
    }
    REP(i, M){
      string s1; cin>>s1;
      string s2; cin>>s2;
      vector<string> path1 = make_path(s1);
      vector<string> path2 = make_path(s2);
      int id1 = get_file(path1, &root);
      int id2 = get_file(path2, &root);
      //debug(path1.begin(), path1.end());
      //debug(path2.begin(), path2.end());
      //printf("id1 = %d id2 = %d\n", id1, id2);
      if(id1 < 0 || id2 < 0){
        cout<<"not found"<<endl;
      }else if(id1 == id2){
        cout<<"yes"<<endl;
      }else{
        cout<<"no"<<endl;
      }
    }
  }
  return 0;
}