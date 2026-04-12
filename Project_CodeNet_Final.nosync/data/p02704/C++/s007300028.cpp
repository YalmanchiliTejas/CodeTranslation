#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull = unsigned long long;

ull ans[500][500];
int part[500][500];

void fail() {
  cout << -1 << endl;
  exit(0);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ull> rtype(n), ctype(n), rval(n), cval(n);
  for (ull&v : rtype) cin >> v;
  for (ull&v : ctype) cin >> v;
  for (ull&v : rval) cin >> v;
  for (ull&v : cval) cin >> v;
  for (int bit = 0; bit < 64; bit++) {
    vector<int> rv(n), cv(n);
    for (int i = 0; i < n; i++) {
      rv[i] = rval[i]>>bit&1;
      cv[i] = cval[i]>>bit&1;
    }

    vector<int> rows, cols;
    fill_n((int*)part, 500*500, -1);
    for (int i = 0; i < n; i++) {
      if (rtype[i] != rv[i])
	for (int j = 0; j < n; j++)
	  part[i][j] = rv[i];
      else rows.push_back(i);
    }
    for (int j = 0; j < n; j++) {
      if (ctype[j] != cv[j])
	for (int i = 0; i < n; i++)
	  part[i][j] = cv[j];
      else cols.push_back(j);
    }

    if (rows.size() >= 2 && cols.size() >= 2) {
      int flipi = 0;
      for (int i : rows) {
	int flipj = 0;
	for (int j : cols) {
	  part[i][j] = flipi^flipj;
	  flipj ^= 1;
	}
	flipi ^= 1;
      }
    } else if (rows.size() == 1 && cols.size()) {
      int r = rows[0];
      for (int j : cols) {
	int found = 0;
	for (int i = 0; i < n; i++)
	  if (part[i][j] == cv[j])
	    found = 1;
	part[r][j] = (found ? rv[r] : cv[j]);
      }
    } else if (cols.size() == 1 && rows.size()) {
      int c = cols[0];
      for (int i : rows) {
	int found = 0;
	for (int j = 0; j < n; j++)
	  if (part[i][j] == rv[i])
	    found = 1;
	part[i][c] = (found ? cv[c] : rv[i]);
      }
    } else assert(cols.empty() || rows.empty());

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	if (part[i][j] == -1) fail();
	ans[i][j] |= ull(part[i][j])<<bit;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    ull v = ans[i][0];
    for (int j = 0; j < n; j++) {
      if (rtype[i] == 0)
	v &= ans[i][j];
      else
	v |= ans[i][j];
    }
    if (v != rval[i]) fail();
  }
  for (int j = 0; j < n; j++) {
    ull v = ans[0][j];
    for (int i = 0; i < n; i++) {
      if (ctype[j] == 0)
	v &= ans[i][j];
      else
	v |= ans[i][j];
    }
    if (v != cval[j]) fail();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << ans[i][j] << ' ';
    cout << endl;
  }
}
