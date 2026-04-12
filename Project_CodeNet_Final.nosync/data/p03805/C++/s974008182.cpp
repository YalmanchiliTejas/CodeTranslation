#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int kMaxNodeNum = 8;
bool has_path[kMaxNodeNum + 1][kMaxNodeNum + 1];
bool node_is_passed[kMaxNodeNum + 1];
int passed_node_count;
int N, M;

int countPaths(int next) {
  node_is_passed[next] = true;
  passed_node_count++;
  if(passed_node_count == N) {
    node_is_passed[next] = false;
    passed_node_count--;
    return 1;
  }
  int count = 0;
  for(int i = 1; i <= N; i++) {
    if(!has_path[next][i]) continue;
    if(node_is_passed[i]) continue;
    count += countPaths(i);
  }
  node_is_passed[next] = false;
  passed_node_count--;
  return count;
}

int main(int argc, char *argv[]) {
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int from, to;
    cin >> from >> to;
    has_path[from][to] = true;
    has_path[to][from] = true;
  }
  cout << countPaths(1) << endl;

  return 0;
}
