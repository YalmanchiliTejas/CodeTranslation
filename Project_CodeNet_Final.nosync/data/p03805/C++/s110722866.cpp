#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> edges;
vector<vector<int>> nodes;
int count = 0;

void search(int position, vector<bool> is_visited) {
  is_visited[position] = true;
  //全部訪れていたら終わり
  int is_visited_count = 0;
  for (const auto& b : is_visited)
    if (b) is_visited_count++;
  if(is_visited_count == n) {
    count++;
    return;
  }

  //次のエッジについて探索
  for (const auto& next_position : nodes[position]) {
    if (!is_visited[next_position])
      search(next_position, is_visited);
  }
  return;
}

int main(){
  cin >> n >> m;
  edges.resize(m);
  for (auto& edge : edges) {
    int a, b;
    cin >> a >> b;
    edge.first = a - 1;
    edge.second = b - 1;
  }
  
  //エッジ基準に書き換え
  nodes.resize(n);
  for (auto& edge : edges) {
    nodes[edge.first].push_back(edge.second);
    nodes[edge.second].push_back(edge.first);
  }
  
  //探索
  vector<bool> is_visited(n, false);
  search(0, is_visited);
  cout << count << endl;
  return 0;  
}