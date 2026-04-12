#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
 
using namespace std;
 
class Node{
public:
  string s;
  int p;
  vector<int> c;
  set<string> f;
  Node(){ c.clear(); f.clear(); }
  Node(string s, int p): s(s), p(p){ c.clear(); f.clear(); }
};
 
vector<Node> nodes;
int n, m;
 
void push(int s, int pos, vector<string>& vec){
  if(s + 1 == (int)vec.size()){
    if(nodes[pos].f.find(vec[s]) == nodes[pos].f.end()) nodes[pos].f.insert(vec[s]);
    return;
  }
  if(vec[s] == "." && s + 1 < (int)vec.size()) push(s + 1, pos, vec);
  if(vec[s] == "..") push(s + 1, nodes[pos].p, vec);
  bool f = false;
  for(int i=0;i<(int)nodes[pos].c.size();i++){
    int id = nodes[pos].c[i];
    if(nodes[id].s == vec[s]){
      f = true;
      push(s + 1, id, vec);
    }
  }
  if(!f){
    nodes.push_back(Node(vec[s], pos));
    nodes[pos].c.push_back((int)nodes.size()-1);
    push(s + 1, (int)nodes.size()-1, vec);
  }
}
 
int find(int s, int pos, vector<string>& vec){
  if(s + 1 == (int)vec.size()){
    if(nodes[pos].f.find(vec[s]) == nodes[pos].f.end()) return -1;
    else return pos;
  }
  if(vec[s] == "."){
    return find(s + 1, pos, vec);
  }
  if(vec[s] == ".."){
    if(pos == 0) return -1;
    else{
      return find(s + 1, nodes[pos].p, vec);
    }
  }
  for(int i=0;i<(int)nodes[pos].c.size();i++){
    int id = nodes[pos].c[i];
    if(nodes[id].s == vec[s]){
      return find(s + 1, id, vec);
    }
  }
  return -1;
}
 
string path(int p){
  string res;
  if(p == 0) res = "";
  else res += nodes[p].s;
  return res;
}
 
vector<string> parse(string str){
  vector<string> res;
  int pre = 1;
  for(int i=1;i<(int)str.size();i++){
    if(str[i] == '/'){
      res.push_back(str.substr(pre, i - pre));
      pre = i + 1;
    }
  }
  res.push_back(str.substr(pre));
  return res;
}
 
int main(){
  while(cin >> n >> m && (n|m)){
    nodes.clear();
    nodes.push_back(Node("root", -1));
    for(int i=0;i<n;i++){
      string in;
      cin >> in;
      vector<string> vec = parse(in);
      push(0, 0, vec);
    }
    for(int i=0;i<m;i++){
      string a[2], b[2];
      cin >> a[0] >> b[0];
      if(a[0][(int)a[0].size()-1] == '/'){
        a[0] += "index.html";
        a[1] = a[0];
      }else{
        a[1] = a[0] + "/index.html";
      }
      if(b[0][(int)b[0].size()-1] == '/'){
        b[0] += "index.html";
        b[1] = b[0];
      }else{
        b[1] = b[0] + "/index.html";
      }
      int ans = 0;
      for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
          vector<string> v1 = parse(a[i]);
          vector<string> v2 = parse(b[j]);
          int p1 = find(0, 0, v1);
          int p2 = find(0, 0, v2);    
          if(p1 != -1 && p2 != -1){
            if(path(p1) + "/" + v1[(int)v1.size()-1] == path(p2) + "/" + v2[(int)v2.size()-1]) ans = 2;
            else ans = max(ans, 1);
          }
        }
      }
      if(ans == 0) cout << "not found" << endl;
      else if(ans == 1) cout << "no" << endl;
      else cout << "yes" << endl;
    }
  }
  return 0;
}