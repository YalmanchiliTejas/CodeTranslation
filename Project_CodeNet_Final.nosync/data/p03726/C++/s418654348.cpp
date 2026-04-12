#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
const ll Mod = 1000000007;
int N;
vector<int> Graph[110000];
vector<int> Depth[110000];
vector<int> Deep(110000);
vector<int> Parent(110000);
vector<int> child[110000];
int root = 0;
void BFS() {
  for (int i = 0; i < (int)Deep.size(); i++) {
    Deep[i] = 999999;
  }
  priority_queue<P, vector<P>, greater<P>> Q;
  Q.push(make_pair(0,root));
  Depth[0].push_back(root);
  Deep[root] = 0;
  while (!Q.empty()) {
    P p = Q.top();
    Q.pop();
    for (int i = 0; i < (int)Graph[p.S].size(); i++) {
      if (Deep[Graph[p.S][i]] > p.F + 1) {
        Q.push(make_pair(p.F+1,Graph[p.S][i]));
        Deep[Graph[p.S][i]] = p.F + 1;
        Depth[p.F+1].push_back(Graph[p.S][i]);
        Parent[Graph[p.S][i]] = p.S;
        child[p.S].push_back(Graph[p.S][i]);
      }
    }
  }
}
int main() {
  cin >> N;
  vector<bool> exist(N);
  bool can = false;
  for (int i = 0; i < N; i++) {
    exist[i] = true;
  }
  for (int i = 0; i < N-1; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }
  
  BFS();

  int Pa = (int)Graph[0].size();
  for (int i = N; i >= 0; i--) {
    for (int j = 0; j < (int)Depth[i].size(); j++) {
      int s = Depth[i][j];
      int ch = 0;
      vector<int> vec;
      bool Flag = false;
      if (i == 1 && Pa == 1) {
        Flag = true;
      }
      for (int k = 0; k < (int)child[s].size(); k++) {
        if (exist[child[s][k]]) {
          vec.push_back(child[s][k]);
          ch++;
        }
      }
      if (i <= 1) {
        if (Flag) {
          if (ch == 0) {
            continue;
          } else if (ch == 1) {
            can = true;
          } else if (ch >= 2) {
            can = true;
          }
        } else {
          if (ch == 0) {
            continue;
          } else if (ch == 1) {
            exist[s] = false;
            if (Parent[s] == 0) Pa--;
            exist[vec[0]] = false;
            if (Parent[vec[0]] == 0) Pa--;
          } else if (ch >= 2) {
            can = true;
          }
        }
      } else {
        if (ch == 0) {
          continue;
        } else if (ch == 1) {
          exist[s] = false;
          if (Parent[s] == 0) Pa--;
          exist[vec[0]] = false;
          if (Parent[vec[0]] == 0) Pa--;
        } else if (ch >= 2) {
          can = true;
        }
      }
    }
    if (can) {
      break;
    }
  }

  if (can) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}