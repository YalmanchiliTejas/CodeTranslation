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
    vector<vector<int> > cost(jewel+2, vector<int>(size, INF));
    priority_queue<State> que;
    que.push(State(0, 0, 0));
    while (!que.empty()) {
      const State st = que.top();
      que.pop();
      
      if (st.jewel == jewel+1) {
	cout << st.cost << endl;
	break;
      }

      if (cost[st.jewel][st.num] < st.cost)
	continue;
      cost[st.jewel][st.num] = st.cost;

      for (unsigned int i = 0; i < path[st.jewel+1].size(); ++i) {
	int new_cost = st.cost + manhattan(path[st.jewel][st.num], path[st.jewel+1][i]);
	if (cost[st.jewel+1][i] > new_cost) {
	  cost[st.jewel+1][i] = new_cost;
	  que.push(State(st.jewel+1, i, new_cost));
	}
      }
    }

  }
  return 0;
}