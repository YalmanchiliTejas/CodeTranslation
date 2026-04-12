#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

int main() {
  int N;
  while((cin >> N) && N) {
    vector< pair<int, pair<int, int> > > v;
    for(int i = 0; i < N; ++i) {
      int y, m, d;
      cin >> y >> m >> d;
      v.push_back(make_pair(y, make_pair(m, d)));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); ++i) {
      printf("%04d %02d %02d\n", v[i].first, v[i].second.first, v[i].second.second);    }
  }
  return 0;
}