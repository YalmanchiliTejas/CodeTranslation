#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> s(n), t(n);
  vector<unsigned long long> u(n), v(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &s[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &t[i]);
  for (int i = 0; i < n; i++)
    scanf("%llu", &u[i]);
  for (int i = 0; i < n; i++)
    scanf("%llu", &v[i]);

  vector<vector<unsigned long long>> ans(n, vector<unsigned long long>(n));
  bool succ = true;
  for (int b = 0; succ && b < 64; b++) {
    vector<int> ub(n), vb(n);
    for (int i = 0; i < n; i++) ub[i] = (u[i] >> b) & 1;
    for (int i = 0; i < n; i++) vb[i] = (v[i] >> b) & 1;

    vector<vector<int>> now(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      if (s[i] == 0 && ub[i] == 1)
        for (int j = 0; j < n; j++)
          now[i][j] = 1;

    for (int i = 0; i < n; i++)
      if (t[i] == 0 && vb[i] == 1)
        for (int j = 0; j < n; j++)
          now[j][i] = 1;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (s[i] == 1 && t[j] == 1 && ub[i] == 1 && vb[j] == 1)
          now[i][j] = 1;

    bool rf = false, cf = false;
    vector<int> rc, cc;
    for (int i = 0; i < n; i++) {
      if (ub[i] == 1) rf = true;
      if (vb[i] == 1) cf = true;

      if (s[i] == 0 && ub[i] == 0)
        rc.push_back(i);
      if (t[i] == 0 && vb[i] == 0)
        cc.push_back(i);
    }

    if (!cf) {
      int x = 0;
      for (int i = 0; i < n; i++)
        if (s[i] == 1 && ub[i] == 1) {
          if (cc.empty())
            succ = false;
          else {
            now[i][cc[x % cc.size()]] = 1;
            x++;
          }
        }
    }

    if (!rf) {
      int x = 0;
      for (int i = 0; i < n; i++)
        if (t[i] == 1 && vb[i] == 1) {
          if (rc.empty())
            succ = false;
          else {
            now[rc[x % rc.size()]][i] = 1;
            x++;
          }
        }
    }

    for (int i = 0; i < n; i++)
      if (s[i] == 0) {
        int f = 1;
        for (int j = 0; j < n; j++)
          f = f & now[i][j];
        if (f != ub[i])
          succ = false;
      }
      else {
        int f = 0;
        for (int j = 0; j < n; j++)
          f = f | now[i][j];
        if (f != ub[i])
          succ = false;
      }

    for (int i = 0; i < n; i++)
      if (t[i] == 0) {
        int f = 1;
        for (int j = 0; j < n; j++)
          f = f & now[j][i];
        if (f != vb[i])
          succ = false;
      }
      else {
        int f = 0;
        for (int j = 0; j < n; j++)
          f = f | now[j][i];
        if (f != vb[i])
          succ = false;
      }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        ans[i][j] += (static_cast<unsigned long long>(now[i][j]) << b);
  }

  if (succ)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        printf("%llu%c", ans[i][j], " \n"[j + 1 == n]);
  else
    printf("-1\n");

  return 0;
}