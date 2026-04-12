/**
 *    author:  tourist
 *    created: 13.05.2020 20:31:35       
**/
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;       
  vector<int> s(n);
  vector<int> t(n);
  vector<ull> u(n);
  vector<ull> v(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> u[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<vector<ull>> a(n, vector<ull>(n));
  for (int bit = 0; bit < 64; bit++) {
    vector<int> ub(n);
    vector<int> vb(n);
    for (int i = 0; i < n; i++) {
      ub[i] = (int) ((u[i] >> bit) & 1);
      vb[i] = (int) ((v[i] >> bit) & 1);
    }
    vector<vector<int>> b(n, vector<int>(n, -1));
    auto Set = [&](int i, int j, int val) {
      if (b[i][j] == (val ^ 1)) {
        cout << -1 << '\n';
        exit(0);
      }
      b[i][j] = val;
    };
    vector<int> rows_all[2];
    vector<int> cols_all[2];
    vector<int> rows_some[2];
    vector<int> cols_some[2];
    for (int i = 0; i < n; i++) {
      if (s[i] == 0) {
        if (ub[i] == 0) rows_some[0].push_back(i);
        else rows_all[1].push_back(i);
      } else {
        if (ub[i] == 1) rows_some[1].push_back(i);
        else rows_all[0].push_back(i);
      }
      if (t[i] == 0) {
        if (vb[i] == 0) cols_some[0].push_back(i);
        else cols_all[1].push_back(i);
      } else {
        if (vb[i] == 1) cols_some[1].push_back(i);
        else cols_all[0].push_back(i);
      }
    }
    for (int z = 0; z < 2; z++) {
      for (int i : rows_all[z]) {
        for (int j = 0; j < n; j++) {
          Set(i, j, z);
        }
      }
      for (int j : cols_all[z]) {
        for (int i = 0; i < n; i++) {
          Set(i, j, z);
        }
      }
    }
    vector<int> row_done(n, 0);
    vector<int> col_done(n, 0);
    for (int z = 0; z < 2; z++) {
      for (int i : rows_some[z]) {
        for (int j = 0; j < n; j++) {
          row_done[i] |= (b[i][j] == z);
        }
      }
      for (int j : cols_some[z]) {
        for (int i = 0; i < n; i++) {
          col_done[j] |= (b[i][j] == z);
        }
      }
    }
    vector<int> row_req(n);
    vector<int> col_req(n);
    for (int i = 0; i < n; i++) {
      row_req[i] = 1 - row_done[i];
    }
    for (int i = 0; i < n; i++) {
      col_req[i] = 1 - col_done[i];
    }
    for (int z = 0; z < 2; z++) {
      for (int i : rows_some[z]) {
        if (!row_done[i]) {
          int mn = n + 1;
          int id = -1;
          for (int j = 0; j < n; j++) {
            if (b[i][j] == -1) {
              int val = col_req[j];
              if (!col_done[j] && t[j] == z && vb[j] == z) {
                val = -1;
              }
              if (val < mn) {
                mn = val;
                id = j;
              }
            }
          }
          if (id == -1) {
            cout << -1 << '\n';
            return 0;
          }
          col_req[id] += 1;
          b[i][id] = z;
          row_done[i] = true;
          if (mn == -1) {
            col_done[id] = true;
          }
        }
      }
      for (int j : cols_some[z]) {
        if (!col_done[j]) {
          int mn = n + 1;
          int id = -1;
          for (int i = 0; i < n; i++) {
            if (b[i][j] == -1) {
              int val = row_req[i];
              if (!row_done[j] && s[i] == z && ub[i] == z) {
                val = -1;
              }
              if (val < mn) {
                mn = val;
                id = i;
              }
            }
          }
          if (id == -1) {
            cout << -1 << '\n';
            return 0;
          }
          row_req[id] += 1;
          b[id][j] = z;
          col_done[j] = true;
          if (mn == -1) {
            row_done[id] = true;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (b[i][j] == 1) {
          a[i][j] |= ull(1) << bit;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) {
        cout << " ";
      }
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}
