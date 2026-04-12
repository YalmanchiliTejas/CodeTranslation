#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 234567;
int ans[MAXN];

int main() {
    int N;
    while (~scanf("%d", &N)) {
          int mid = N / 2;
          vector<pii> line;
          for (int i = 0; i < N; i++) {
              int tmp;
              scanf("%d", &tmp);
              line.push_back(make_pair(tmp, i));
          }
          sort(line.begin(), line.end());
          for (int i = 0; i < int(line.size()); i++) {
              if (i < mid) ans[line[i].second] = line[mid].first;
              else ans[line[i].second] = line[mid - 1].first;
              // printf("fst = %d second = %d\n", line[i].first, line[i].second);
          }
          for (int i = 0; i < N; i++) {
              printf("%d\n", ans[i]);
          }
    }
    return 0;
}
