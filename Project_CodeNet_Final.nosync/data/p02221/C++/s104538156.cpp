#include <bits/stdc++.h>
using namespace std;

long long n;
string s;
vector<int> p, res;
vector<vector<int>> memo;

void prepair(int dep, int id, const vector<int> &v);
int calc(int x, int y);

int main() {
  cin >> n >> s;
  p.resize(1 << n);
  res.assign(1 << n, 0);
  memo.assign(n, vector<int>(2, -1));
  for(int i = 0; i < (1 << n); ++i) cin >> p[i];
  prepair(0, 0, p);
  for(int i = 0; i < (1 << n); ++i) cout << res[i] << endl;
  return 0;
}

void prepair(int dep, int id, const vector<int> &v) {
  if(dep == n) {
    assert(v.size() == 1);
    res[id] = v[0];
    return;
  }
  int vsize = v.size();
  vector<int> to;
  // pattern 0
  for(int i = 0; i < vsize; i += 2)
    to.push_back(calc(v[i], v[i + 1]));
  prepair(dep + 1, id, to);
  // pattern 1
  to.clear();
  for(int i = 0; i < vsize; i += 2)
    to.push_back(calc(v[i + 1], v[(i + 2) % vsize]));
  prepair(dep + 1, id + (1 << dep), to);
}

int calc(int x, int y) {
  if(x > y) swap(x, y);
  return (s[y - x - 1] == '1') ? y : x;
}
