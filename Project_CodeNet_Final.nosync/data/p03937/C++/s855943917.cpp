#include <bits/stdc++.h>

using namespace std;

int N, M;
char mp[100][100];

bool check() {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      for (int x = 1; x <= N; x++)
        for (int y = 1; y <= M; y++)
          if (((x < i && y > j) || (x > i && y < j)) && mp[x][y] == '#' && mp[i][j] == '#')
            return false;
  return true;
}

int main() {
  //  freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) scanf("%s", mp[i] + 1);
  puts(check() ? "Possible" : "Impossible");
  return 0;
}
