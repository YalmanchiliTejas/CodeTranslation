#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
static int N;
static int M;
static map<int, vector<int>> m;

// マップ作製
void makemap () {
  for (int i = 0; i < M; i++) {
    for (int j = 1; j <= N; j++) {
      if (graph[i][0] == j) {
        if (m.count(j) == 0) {
          m[j] = {graph[i][1]};
        } else {
          m[j].push_back(graph[i][1]);
        }
      }
      if (graph[i][1] == j) {
        if (m.count(j) == 0) {
          m[j] = {graph[i][0]};
        } else {
          m[j].push_back(graph[i][0]);
        }
      }      
    }
  }
}

bool findNum (vector<int> vec, int num) {
  bool ret = false;
  for (auto x : vec) {
    if (x == num) {
      ret = true;
      break;
    }
  }
  return ret;
}

int main()
{
  // 入力受け取り
  int g1,g2;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> g1 >> g2;
    graph.push_back({g1,g2});
  }
  
  // 初期化
  makemap();
  
  // カウント
  int counter = 0;
  vector<int> v(N-1);
  iota(v.begin(), v.end(), 2);
  do {
    int before = 1;
    int exist = 1;
    for(auto x : v) {
      if (!findNum(m[before], x)) break;
      exist++;
      before = x;
    }
    if (exist == N) {
      counter++;
    }
  } while( next_permutation(v.begin(), v.end()) ); 
  
  cout << counter << endl;
  
  return 0;
}
