#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>
using namespace std;

using Pos = pair<int, int>;
using Visited = bitset<80>;

inline void setVisited(Visited& visited, const Pos& pos) {
  visited.set(pos.first * 8 + pos.second);
}
inline bool isVisited(Visited& visited, const Pos& pos) {
  return visited.test(pos.first * 8 + pos.second);
}
inline bool isSharp(vector<string> board, const Pos& pos) {
  if(pos.first >= board.size()) {
    return false;
  }
  if(pos.second >= board[0].size()) {
    return false;
  }
  return board[pos.first][pos.second] == '#';
}

bool solve(vector<string> board, Visited visited, const Pos& pos) {

  if(pos.first == board.size() - 1 && pos.second == board[0].size() - 1) {
    for(int h = 0; h < board.size(); ++h) {
      for(int w = 0; w < board[h].size(); ++w) {
        if(board[h][w] == '#' && !isVisited(visited, {h, w})) {
          return false;
        }
      }
    }
    return true;
  }

  Pos right = {pos.first, pos.second + 1};
  if(isSharp(board, right)) {
    auto v = visited;
    setVisited(v, right);
    if(solve(board, v, right)) {
      return true;
    }
  }
  Pos down = {pos.first + 1, pos.second};
  if(isSharp(board, down)) {
    auto v = visited;
    setVisited(v, down);
    if(solve(board, v, down)) {
      return true;
    }
  }
  return false;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> bs(H);
  for(int i = 0; i < H; ++i) {
    cin >> bs[i];
  }

  Visited visited;
  setVisited(visited, {0, 0});
  if(solve(bs, visited, {0, 0})) {
    cout << "Possible" << endl;
    return 0;
  }
  cout << "Impossible" << endl;
  return 0;
}