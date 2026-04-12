#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int X, Y, Z; scanf("%d %d %d", &X, &Y, &Z);
  int ans = (X - Z) / (Y + Z);
  printf("%d\n", ans);
  return 0;
}
