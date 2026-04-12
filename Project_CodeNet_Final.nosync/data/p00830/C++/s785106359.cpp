#include <bits/stdc++.h>
using namespace std;
struct PathologicalPaths
{
  struct node
  {
    set< string > pages;
    map< string, node* > children;
  };

  vector< string > split(const string& input, char delimiter)
  {
    istringstream stream(input);
    string field;
    vector< string > result;
    while(getline(stream, field, delimiter)) result.push_back(field);
    return(result);
  }
  PathologicalPaths(vector< string >& base, vector< pair< string, string > >& query)
  {
    node* root = new node();
    root -> children.insert({".", root});
    for(auto s : base) {
      vector< string > spd = split(s, '/');
      node* now = root;
      for(int i = 1; i < spd.size() - 1; i++) {
        auto p = now -> children.insert({spd[i], new node()});
        if(p.second) p.first -> second -> children.insert({"..", now});
        now = p.first -> second;
        now -> children.insert({".", now});
      }
      now -> pages.insert(spd.back());
    }
    for(auto ps : query) {
      vector< string > spd[2] = {split(ps.first, '/'), split(ps.second, '/')};
      if(ps.first.back() == '/') spd[0].push_back(string());
      if(ps.second.back() == '/') spd[1].push_back(string());
      node *now[2] = {root, root};
      bool found = true;
      for(int j = 0; j < 2; j++) {
        for(int i = 1; i < spd[j].size(); i++) {
          if(now[j] -> children.find(spd[j][i]) == now[j] -> children.end()) {
            if(i < spd[j].size() - 1) found = false;
            break;
          } else {
            now[j] = now[j] -> children[spd[j][i]];
            if(i == spd[j].size() - 1) {
              spd[j].push_back("index.html");
              break;
            }
          }
        }
      }
      if(spd[0].back().empty()) spd[0].back() = "index.html";
      if(spd[1].back().empty()) spd[1].back() = "index.html";
      
      auto p = now[0] -> pages.find(spd[0].back());
      auto q = now[1] -> pages.find(spd[1].back());
      if(!found || p == now[0] -> pages.end() || q == now[1] -> pages.end()) {
        cout << "not found" << endl;
      } else {
        if(p == q){
          cout << "yes" << endl;
        } else {
          cout << "no" << endl;
        }
      }      
    }
  }
};

int main()
{
  int N, M;
  while(cin >> N >> M, N) {
    vector< string > A(N);
    vector< pair< string, string > > B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i].first >> B[i].second;
    new PathologicalPaths(A, B);
  }
}