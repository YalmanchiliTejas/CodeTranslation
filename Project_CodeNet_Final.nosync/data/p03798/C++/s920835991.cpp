#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int x[4] = {1, 1, -1, -1};
int y[4] = {1, -1, 1, -1};
string c = "W_S";

int main(){
  int n; cin >> n;
  string ss; cin >> ss;
  vector<int> s;
  for (int i = 0; i < n; i++) {
    int k;
    if (ss[i] == 'o') k = 1;
    else k = -1;
    s.push_back(k);
  }

  for (int p = 0; p < 4; p++) {
    vector<int> v(n+1, 0);
    v[0] = x[p]; v[1] = y[p];
    for (int i = 1; i < n; i++) {
      v[i+1] = v[i-1] * v[i] * s[i];
    }
    if (v[n] == v[0] && v[n-1] == v[1] * v[0] * s[0]) {
      for (int i = 0; i < n; i++) {
        printf("%c", c[v[i]+1]);
      }
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
