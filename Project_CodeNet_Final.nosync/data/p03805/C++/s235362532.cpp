#include <iostream>

using namespace std;

constexpr int kMaxNodeNum = 8;
bool has_path[kMaxNodeNum + 1][kMaxNodeNum + 1];
bool node_is_passed[kMaxNodeNum + 1];
int passed_node_count;
int N;

int MarkAndCountPaths(int next);

int CountPaths(int next) {
  if(passed_node_count == N)
    return 1;
  int count = 0;
  for(int i = 1; i <= N; i++) {
    if(!has_path[next][i]) continue;
    if(node_is_passed[i]) continue;
    count += MarkAndCountPaths(i);
  }
  return count;
}

int MarkAndCountPaths(int next) {
  node_is_passed[next] = true;
  passed_node_count++;
  int count = CountPaths(next);
  passed_node_count--;
  node_is_passed[next] = false;
  return count;
}

int main(int argc, char *argv[]) {
  int M;
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int from, to;
    cin >> from >> to;
    has_path[from][to] = true;
    has_path[to][from] = true;
  }
  cout << MarkAndCountPaths(1) << endl;

  return 0;
}
