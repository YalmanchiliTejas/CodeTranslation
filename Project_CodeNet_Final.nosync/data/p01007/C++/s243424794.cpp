#include <bits/stdc++.h>
using namespace std;

int n, m, o, r, c, sz, ang;
int mp[20][20] = {0}, tmp[400] = {0};

void rotate();
void reversal();
void lshift();
void rshift();
void island();

int main() {
  int i, j;
  cin >> n >> m;
  for(i = 1; i <= n; ++i)
    for(j = 1; j <= n; ++j) cin >> mp[i][j];
  for(i = 0; i < m; ++i) {
    cin >> o;
    if(o == 0) rotate();
    if(o == 1) reversal();
    if(o == 2) lshift();
    if(o == 3) rshift();
    if(o == 4) island();
  }
  for(i = 1; i <= n; ++i) {
    for(j = 1; j <= n; ++j) {
      cout << mp[i][j];
      if(j != n) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
void rotate() {
  int i, j, k, cnt;
  cin >> r >> c >> sz >> ang;
  if(ang == 0 || ang == 360 || sz == 1) return;
  for(k = 0; k < ang; k += 90) {
    cnt = 0;
    for(i = r; i < r + sz; ++i)
      for(j = c; j < c + sz; ++j) tmp[cnt++] = mp[i][j];
    cnt = 0;
    for(i = c + sz - 1; i >= c; --i)
      for(j = r; j < r + sz; ++j) mp[j][i] = tmp[cnt++];
  }
}
void reversal() {
  int i, j;
  cin >> r >> c >> sz;
  for(i = r; i < r + sz; ++i)
    for(j = c; j < c + sz; ++j) mp[i][j] = 1 - mp[i][j];
}
void lshift() {
  cin >> r;
  mp[r][n + 1] = mp[r][1];
  for(int i = 1; i <= n; ++i) mp[r][i] = mp[r][i + 1];
}
void rshift() {
  cin >> r;
  mp[r][0] = mp[r][n];
  for(int i = n; i > 0; --i) mp[r][i] = mp[r][i - 1];
}
void island() {
  int data;
  int d[4] = {1, 0, -1, 0};
  pair<int, int> now, nextn;
  stack<pair<int, int>> st;
  cin >> r >> c;
  data = mp[r][c];
  mp[r][c] = 1 - mp[r][c];
  st.push(make_pair(r, c));
  while(!st.empty()) {
    now = st.top();
    st.pop();
    for(int i = 0; i < 4; ++i) {
      nextn = now;
      nextn.first += d[i];
      nextn.second += d[1 ^ i];
      if(nextn.first > 0 && nextn.first <= n &&
         nextn.second > 0 && nextn.second <= n &&
         mp[nextn.first][nextn.second] == data) {
        st.push(nextn);
        mp[nextn.first][nextn.second] =
            1 - mp[nextn.first][nextn.second];
      }
    }
  }
}
