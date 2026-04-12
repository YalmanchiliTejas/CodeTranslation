#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;
vector<pair<int, int>> ps;
vector<int> ts1, ts2;

int main(void) {
  scanf("%d%d", &h, &w);
  int mi1 = 114514, mi2 = 114514;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c; scanf(" %c", &c);
      if (c == 'B') {
	ps.push_back({j, i});
	ts1.push_back(j + i);
	ts2.push_back(j - i);
	mi1 = min(mi1, j + i);
	mi2 = min(mi2, j - i);
      }
    }
  }

  int res = 0;
  for (int i = 0; i < int(ts1.size()); i++) {
    res = max(res, ts1[i] - mi1);
  }
  for (int i = 0; i < int(ts2.size()); i++) {
    res = max(res, ts2[i] - mi2);
  }
  printf("%d\n", res);
  return 0;
}

/*
|x1-x2|+|y1-y2|

x1+y1
x1-y1

max(x1+y1-(x2+y2)(x1-x2)+(y1-y2),
(x1-y1)-(x2-y2)(x1-x2)+(y2-y1),
(y1-x1)+(x2-y2)(x2-x1)+(y1-y2),
(x2+y2)-(x1+y2)(x2-x1)+(y2-y1))
 */

