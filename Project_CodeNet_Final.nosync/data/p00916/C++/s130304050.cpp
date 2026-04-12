#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

#define SIZE 400

int sum[SIZE][SIZE];

int solve() {
  int N;
  int l[SIZE], t[SIZE], r[SIZE], b[SIZE];
  vector<int> vecY, vecX;
  map<int,int> dicX, dicY;

  scanf("%d", &N);

  if (N == 0) return false;

  memset(sum, 0, sizeof(sum));

  for (int i=0; i<N; i++) {
    scanf("%d%d%d%d", l+i, t+i, r+i, b+i);
    vecY.push_back(t[i]);
    vecY.push_back(b[i]);
    vecX.push_back(l[i]);
    vecX.push_back(r[i]);
  }

  sort(vecX.begin(), vecX.end());
  sort(vecY.begin(), vecY.end());

  vecX.erase(unique(vecX.begin(), vecX.end()),vecX.end());
  vecY.erase(unique(vecY.begin(), vecY.end()),vecY.end());

  for (int i=0; i<vecX.size(); i++)
    dicX[vecX[i]] = i;
  for (int i=0; i<vecY.size(); i++)
    dicY[vecY[i]] = i;

  for (int i=0; i<N; i++) {
    int x = (dicX[l[i]] + 3) * 2;
    int y = (dicY[b[i]] + 3) * 2;
    int p = (dicX[r[i]] + 3) * 2;
    int q = (dicY[t[i]] + 3) * 2;

    sum[y][x]++;
    sum[y][p+1]--;
    sum[y+1][x+1]--;
    sum[y+1][p]++;
    sum[q][x+1]++;
    sum[q][p]--;
    sum[q+1][x]--;
    sum[q+1][p+1]++;
  }

  for (int i=0; i<300; i++)
    for (int j=0; j<300; j++)
      sum[i][j+1] += sum[i][j];

  for (int i=0; i<300; i++)
    for (int j=0; j<300; j++)
      sum[i+1][j] += sum[i][j];

  int ans = 0;
  /*
  for (int i=0; i<50; i++) {
    for (int j=0; j<50; j++)
      printf("%d", sum[i][j]);
    puts("");
  }
  */
  for (int i=0; i<300; i++) {
    for (int j=0; j<300; j++) {
      if (sum[i][j]) continue;

      queue<pair<int,int> > que;

      que.push({i, j});

      ans++;

      while(que.size()) {
        auto p = que.front();
        que.pop();

        int y = p.first;
        int x = p.second;

        if (sum[y][x]) continue;
        sum[y][x] = true;

        if (y > 0) que.push({y-1, x});
        if (x > 0) que.push({y, x-1});
        if (y < 300) que.push({y+1, x});
        if (x < 300) que.push({y, x+1});
      }
    }
  }

  printf("%d\n", ans);

  return true;
}

int main() {
  while(solve());
  return 0;
}

