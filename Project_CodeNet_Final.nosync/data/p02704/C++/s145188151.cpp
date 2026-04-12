#include <bits/stdc++.h>
using namespace std;

int n;
bool s[500];
bool t[500];
uint64_t u[500];
uint64_t v[500];
uint64_t ans[500][500];

vector<vector<bool>> sub(vector<bool> a, vector<bool> b) {
  vector<vector<bool>> ret(n, vector<bool>(n));
  vector<int> rows(n);
  vector<int> cols(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == a[i]) rows[i] = n - 1;
    if (s[i] != a[i]) rows[i] = 0;
  }
  for (int j = 0; j < n; ++j) {
    if (t[j] == b[j]) cols[j] = n - 1;
    if (t[j] != b[j]) cols[j] = 0;
  }
  //cerr << "p" << endl;
  //for (int i = 0; i < n; ++i) cerr << rows[i] << ' '; cerr << endl;
  //for (int i = 0; i < n; ++i) cerr << cols[i] << ' '; cerr << endl;
  
  using PP = pair<int, int>;
  queue<PP> que;
  for (int i = 0; i < n; ++i) if (rows[i] == 0) que.push(PP(0, i));
  for (int j = 0; j < n; ++j) if (cols[j] == 0) que.push(PP(1, j));
  
  vector<bool> rused(n);
  vector<bool> cused(n);
  while (!que.empty()) {
    PP p = que.front(); que.pop();
    int rc = p.first;
    if (rc == 0) {
      int i = p.second;
      if (rused[i]) continue;
      rused[i] = true;
      for (int j = 0; j < n; ++j) {
        if (cused[j]) continue;
        ret[i][j] = a[i];
        if (b[j] != a[i]) {
          --cols[j];
          if (cols[j] == 0) que.push(PP(1, j));
        }
      }
    } else {
      int j = p.second;
      if (cused[j]) continue;
      cused[j] = true;
      for (int i = 0; i < n; ++i) {
        if (rused[i]) continue;
        ret[i][j] = b[j];
        //cerr << "#" << j << ' ' <<b[j] << endl;
        if (a[i] != b[j]) {
          --rows[i];
          if (rows[i] == 0) que.push(PP(0, i));
        }
      }
    }
  }
  
  vector<int> x(n);
  vector<int> y(n);
  {
    int curr = 2;
    for (int i = 0; i < n; ++i) {
      if (!rused[i]) {
        x[i] = curr;
        curr = 1;
      }
    }
  }
  {
    int curr = 2;
    for (int j = 0; j < n; ++j) {
      if (!cused[j]) {
        y[j] = curr;
        curr = 1;
      }
    }
  }
  
  for (int i = 0; i < n; ++i) {
    if (x[i] == 0) continue;
    for (int j = 0; j < n; ++j) {
      if (y[j] == 0) continue;
      //cerr << i << ' ' << j << endl;
      ret[i][j] = x[i] == y[j];
    }
  }
  
  //cerr << "k = " << endl;
 
  return ret;
}

bool ok() {
  for (int i = 0; i < n; ++i) {
    if (!s[i]) {
      uint64_t q = -1;
      for (int j = 0; j < n; ++j) q &= ans[i][j];
      if (q != u[i]) return false;
    } else {
      uint64_t q = 0;
      for (int j = 0; j < n; ++j) q |= ans[i][j];
      if (q != u[i]) return false;
    }
  }
  for (int j = 0; j < n; ++j) {
    if (!t[j]) {
      uint64_t q = -1;
      for (int i = 0; i < n; ++i) q &= ans[i][j];
      if (q != v[j]) return false;
    } else {
      uint64_t q = 0;
      for (int i = 0; i < n; ++i) q |= ans[i][j];
      if (q != v[j]) return false;
    }
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) cin >> t[i];
  for (int i = 0; i < n; ++i) cin >> u[i];
  for (int i = 0; i < n; ++i) cin >> v[i];
  
  for (int k = 0; k < 64; ++k) {
    vector<bool> a(n);
    vector<bool> b(n);
    for (int i = 0; i < n; ++i) a[i] = (u[i] >> k) & 1;
    for (int j = 0; j < n; ++j) b[j] = (v[j] >> k) & 1;
    
    auto res = sub(a, b);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] |= uint64_t(res[i][j]) << k; 
      }
    }
  }
 
  if (ok()) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << ans[i][j] << ' ';
      }
      cout << endl;
    }
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cerr << ans[i][j] << ' ';
      }
      cerr << endl;
    }
    cout << -1 << endl;
  }
}