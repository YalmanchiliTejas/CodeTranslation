#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main () {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > node;
  node.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    node[a].push_back(b);    
    node[b].push_back(a);    
  }  
  vector<string> ans;
  ans.push_back("1");
  while (ans[0].size() < n) {
    int size = ans.size();
    for (int i = 0; i < size; i++) {
      int itr = ans[i][ans[i].size() - 1] - 48;
      string h = ans[i];
      for (int j = 0; j < node[itr].size(); j++) {
        if (j == 0) {
          ans[i] = ans[i] + to_string(node[itr][j]);  
        }    
        else {
          ans.push_back(h + to_string(node[itr][j]));  
        }
      }
    }  
  }
  int answer = 0;
  vector<int> init(n + 1, 0);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j <= n; j++) {
      init[j] = 0;  
    }    
    for (int j = 0; j < ans[i].size(); j++) {
      int itr = ans[i][j] - 48;
      init[itr]++;  
    }
    for (int j = 1; j <= n; j++) {
      if (init[j] == 1) {
          
      } 
      else {
        break;  
      } 
      if (j == n) {
        answer++;  
      }
    }
  }
  cout << answer << endl;
}