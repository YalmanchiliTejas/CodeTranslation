#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N;
  scanf("%d", &N);

  unordered_map< int64, int > dp;
  dp[0] = -1;
  int64 now = 0;
  int ret = 0;
  for(int i = 0; i < N; i++) {
    int D;
    scanf("%d", &D);
    now += D;
    if(dp.count(now)) ret = max(ret, i - dp[now]);
    else dp[now] = i;
  }
  printf("%d\n", ret);
}