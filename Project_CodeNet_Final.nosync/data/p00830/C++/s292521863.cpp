#include<bits/stdc++.h>
using namespace std;
struct ele{
  int num;
  ele* parent;
  map<string, ele>children;
  void addPath(vector<string> ss){
    ele* e = this;
    for (int i = 0; i < ss.size(); i++) {
      while(i < ss.size() &&
            (e->children.find(ss[i]) != e->children.end() ||
             (ss[i] == ".." || ss[i] == "."))){
        if(ss[i] == ".."){
          e = e->parent;
          i++;
          continue;
        }else if(ss[i] == "."){
          i++;
          continue;
        }
        e = &e->children[ss[i]];
        i++;
      }
      if(i >= ss.size())break;
      ele add;
      add.parent = e;
      add.num = num + 1;
      e->children[ss[i]] = add;
      num++;
      e = &e->children[ss[i]];
    }
  }
  ele(){
    num = 1;
    parent = NULL;
  }
  void printTree(int depth = 0){
    std::cout << depth << std::endl;
    for (auto& i: children) {
      std::cout << i.first << std::endl;
    }
    for (auto& i: children) {
      i.second.printTree(depth + 1);
    }
  }
  void operator=(const ele& a){
    num = a.num;
    parent = a.parent;
    children = a.children;
  }
  int find(vector<string> ss){
    int n = ss.size();
    ele* e = this;
    for (int i = 0; i < n; i++) {
      //      std::cout << ss[i] << std::endl;
      if(e->children.size() == 0)return 0;
      if(ss[i] == ".")continue;
      if(ss[i] == ".."){
        if(e->parent == NULL)return 0;
        e = e->parent;
      }else if(e->children.find(ss[i]) != e->children.end()){
        e = &e->children[ss[i]];
      }else{
        return 0;
      }
    }
    if(e->children.size() > 0)return 0;
    if(e == this)return e->num + 10;
    return e->num;
  }
};

vector<string> split(string s, char delimiter){
  vector<string> res;
  int prev_split_point = 0;
  for (int i = 0; i < s.length(); i++) {
    while(s[i] != delimiter && i < s.length())i++;
    string add = s.substr(prev_split_point, i - prev_split_point);
    if(!add.empty())res.push_back(add);
    prev_split_point = i + 1;
  }
  return res;
}

int main(int argc, char *argv[]){
  int n, m;
  while(cin >> n >> m, n){
    ele root;
    string s, t;
    for (int i = 0; i < n; i++) {
      cin >> s;
      vector<string> ss = split(s, '/');
      if(s[s.length() - 1] == '/')
        ss.push_back("index.html");
      root.addPath(ss);
      //root.printTree();
    }
    for (int i = 0; i < m; i++) {
      cin >> s >> t;
      vector<string> ss = split(s, '/');
      vector<string> st =  split(t, '/');
      if(s[s.length() - 1] == '/')ss.push_back(".");
      if(t[t.length() - 1] == '/')st.push_back(".");
      int a[2], b[2];
      a[0] = root.find(ss);
      b[0] = root.find(st);
      ss.push_back("index.html");
      st.push_back("index.html");
      a[1] = root.find(ss);
      b[1] = root.find(st);
      for (int i = 0; i < 2; i++) {
        //std::cout << "a[" << i << "]:" << a[i] << " b[" << i << "]:" << b[i] << std::endl;
      }


      int flag = 0;
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if(a[i] == 0 || b[j] == 0){
            flag = max(0, flag);
          }else if(a[i] == b[j]){
            flag = 2;
          }else{
            flag = max(1, flag);
          }
        }
      }
      if(flag == 2){
        std::cout << "yes" << std::endl;
      }else if(flag == 1){
        std::cout << "no" << std::endl;
      }else{
        std::cout << "not found" << std::endl;
      }
    }
  }
  return 0;
}