#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[8][8];

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    d[a-1][b-1] = 1;
    d[b-1][a-1] = 1;
  }
  vector<int> v;
  for (int i = 1; i < n; i++) {
    v.push_back(i);
  }
  long long count = 0;
  do {
    if (d[0][v[0]] != 1) continue;
    for (int i = 1; i < n-1; i++) {
      if (d[v[i-1]][v[i]] != 1) break;
      if (i == n-2) count++;
    }
    if (n == 2) count++;
  } while( next_permutation(v.begin(), v.end()));
  cout << count << endl;
  return 0;
}
