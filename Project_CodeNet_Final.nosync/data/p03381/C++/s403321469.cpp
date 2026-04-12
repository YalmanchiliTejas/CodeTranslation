#include <bits/stdc++.h>

using namespace std;

pair<int, int>v[200002];
int n, p[200002];

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort (v + 1, v + n + 1);
  for (int i = 1; i <= n; i++)
    p[v[i].second] = i;
  for (int i = 1; i <= n; i++) {
    int x = p[i];
    if (x <= n / 2)
      cout << v[n / 2 + 1].first << "\n";
    else
      cout << v[n / 2].first << "\n";
  }
  return 0;
}
