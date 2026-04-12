#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
using namespace std;

class Point
{
public:
  int x, y;
  Point(int _x = 0, int _y = 0)
    :x(_x), y(_y) {}
};

class State
{
public:
  int jewel, num, cost;
  State(int _jewel, int _num, int _cost)
    :jewel(_jewel), num(_num), cost(_cost) {}
  bool operator < (const State& st) const
  {
    return this->cost > st.cost;
  }
};

int manhattan(const Point& p1, const Point& p2)
{
  return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main()
{
  const int INF = 1 << 30;

  int w, h;
  while (cin >> w >> h) {
    if (w == 0 && h == 0)
      break;

    int jewel = 0;
    vector<vector<string> > floor(h, vector<string>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
	cin >> floor[i][j];
	if (floor[i][j] != "S" && floor[i][j] != "G" && floor[i][j] != ".")
	  jewel = max(jewel, atoi(floor[i][j].c_str()));
      }
    }

    unsigned int size = 1;
    vector<vector<Point> > path(jewel+2);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
	if (floor[i][j] == "S") {
	  path[0].push_back(Point(j, i));
	} else if (floor[i][j] == "G") {
	  path[jewel+1].push_back(Point(j, i));
	} else if (floor[i][j] != ".") {
	  int num = atoi(floor[i][j].c_str());
	  path[num].push_back(Point(j, i));
	  size = max(size, path[num].size());
	}
      }
    }

    vector<vector<int> > dp(jewel+2, vector<int>(size, INF));
    dp[0][0] = 0;
    for (unsigned int i = 1; i < dp.size(); ++i) {
      for (unsigned int j = 0; j < path[i].size(); ++j) {
	for (unsigned int k = 0; k < path[i-1].size(); ++k) {
	  dp[i][j] = min(dp[i][j],
			 dp[i-1][k] + manhattan(path[i-1][k], path[i][j]));
	}
      }
    }
    cout << dp[jewel+1][0] << endl;
  }
  return 0;
}