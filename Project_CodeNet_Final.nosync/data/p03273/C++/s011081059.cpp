#include <bits/stdc++.h>

using namespace std;

void eliminate_empty_line(vector< vector<bool> > &map)
{
  auto itr = map.begin();
  while (itr != map.end()) {
    if ( accumulate(itr->begin(), itr->end(), true, logical_and<bool>()) ) {
      itr = map.erase(itr);
    } else {
      ++itr;
    }
  }
}

vector< vector<bool> > transpose(vector< vector<bool> > &src)
{
  uint64_t H = src.size(), W = src[0].size();
  vector< vector<bool> > dst(W, vector<bool>(H));
  for (uint64_t h = 0; h < H; ++h) {
    for (uint64_t w = 0; w < W; ++w) {
      dst[w][h] = src[h][w];
    }
  }
  return dst;
}

ostream& operator<<(ostream &os, const vector< vector<bool> > &map)
{
  for (uint64_t h = 0; h < map.size(); ++h) {
    for (uint64_t w = 0; w < map[h].size(); ++w) {
      os << (map[h][w] ? '.' : '#');
    }
    os << endl;
  }
  return os;
}

int main()
{
  uint64_t H, W;
  cin >> H >> W;
  
  vector< vector<bool> > map(H, vector<bool>(W));
  for (uint64_t h = 0; h < H; ++h) {
    for (uint64_t w = 0; w < W; ++w) {
      char c;
      cin >> c;
      map[h][w] = c == '.';
    }
  }
  
  eliminate_empty_line(map);
  
  map = transpose(map);
  
  eliminate_empty_line(map);
  
  map = transpose(map);
  
  cout << map << endl;
  
  return 0;
}