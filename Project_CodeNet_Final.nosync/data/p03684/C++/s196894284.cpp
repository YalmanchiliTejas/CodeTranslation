#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stdlib.h>

using namespace std;
long long x[100001], y[100001];
int sx[100001], sy[100001], wx[100001], wy[100001];
char done[100001] = {};
int N;

priority_queue<pair<long long, int> > q;

int sortx(int a, int b) {
  return x[a] < x[b];
}

int sorty(int a, int b) {
  return y[a] < y[b];
}

int visit(int pos) {
  if (done[pos] == 1) return 0;

  done[pos] = 1;
  if (wx[pos] >= 1) {
    int next_city = sx[wx[pos] - 1];
    int cost = abs(x[pos] - x[next_city]);
    //    printf("edge1 %d to %d cost %d\n", pos, next_city, cost);
    q.push(make_pair(-cost, next_city));
  }
  if (wy[pos] >= 1) {
    int next_city = sy[wy[pos] - 1];
    int cost = abs(y[pos] - y[next_city]);
    //    printf("edge2 %d to %d cost %d\n", pos, next_city, cost);
    q.push(make_pair(-cost, next_city));
  }
  if (wx[pos] <= N - 2) {
    int next_city = sx[wx[pos] + 1];
    int cost = abs(x[pos] - x[next_city]);
    //    printf("edge3 %d to %d cost %d\n", pos, next_city, cost);
    q.push(make_pair(-cost, next_city));
  }
  if (wy[pos] <= N - 2) {
    int next_city = sy[wy[pos] + 1];
    int cost = abs(y[pos] - y[next_city]);
    //    printf("edge4 %d to %d cost %d\n", pos, next_city, cost);
    q.push(make_pair(-cost, next_city));
  }

  return 1;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld %lld", x + i, y + i);
    sx[i] = sy[i] = i;
  }
  sort(sx, sx + N, sortx);
  sort(sy, sy + N, sorty);
  for (int i = 0; i < N; i++) {
    wx[sx[i]] = i; // id to pos in sx
    wy[sy[i]] = i;
  }

  long long ans = 0;
  visit(0);
  int finished = 1;
  while (finished < N) {
    long long cost = -q.top().first;
    int pos = q.top().second;
    q.pop();

    //    printf("visiting %d\n", pos);
    if (visit(pos) == 1) {
      //      printf("accepted\n");
      finished++;
      ans += cost;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
