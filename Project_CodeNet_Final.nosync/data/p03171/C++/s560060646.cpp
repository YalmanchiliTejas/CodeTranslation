#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[3002][3002][2], a[3002];

long long memo (int st, int dr, int p) {
  int semn;
  if (dp[st][dr][p])
    return dp[st][dr][p];
  if (p)
    semn = -1;
  else
    semn = 1;
  if (st == dr)
    return dp[st][dr][p] = semn * a[st];
  long long aux1 = memo(st + 1, dr, !p) + semn * a[st];
  long long aux2 = memo(st, dr - 1, !p) + semn * a[dr];
  if (p)
    return dp[st][dr][p] = min(aux1, aux2);
  else
    return dp[st][dr][p] = max(aux1, aux2);
}


int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    dp[i][i][0] = a[i], dp[i][i][1] = -a[i];
  cout << memo(1, n, 0);
  return 0;
}
