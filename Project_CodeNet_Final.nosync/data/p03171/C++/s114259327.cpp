#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
long long int recursive(
    int start, int end, vector<int>& a, bool turn,
    unordered_map<int, unordered_map<int, long long int>>& table,
    vector<vector<bool>>& visited) {
  if (visited[start][end]) {
    return table[start][end];
  }
  visited[start][end] = true;
  if (table.count(start) <= 0) {
    unordered_map<int, long long int> m;
    m[end] = 0;
    table[start] = m;
  }

  if (start == end) {
    if (turn == 0) {
      table[start][end] = a[start];
      return a[start];
    } else {
      table[start][end] = -a[start];
      return -a[start];
    }
  }
  long long int r1 = recursive(start + 1, end, a, !turn, table, visited);
  long long int r2 = recursive(start, end - 1, a, !turn, table, visited);
  long long int maxR = max(r1 + a[start], r2 + a[end]);
  long long int minR = min(r1 - a[start], r2 - a[end]);
  if (turn == 0) {
    table[start][end] = maxR;
    return maxR;
  } else {
    table[start][end] = minR;
    return minR;
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N, 0);
  for (int i = 0; i < N; ++i) cin >> a[i];
  unordered_map<int, unordered_map<int, long long int>> table;
  vector<vector<bool>> visited(N, vector<bool>(N, 0));
  long long int r = recursive(0, N - 1, a, 0, table, visited);
  cout << r;
}