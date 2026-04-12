#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
  int T, C;
  vector<pair<int, int> > v;
  while (scanf("%d,%d ", &T, &C) == 2) {
    if (T == 0 && C == 0) {break;}
    v.push_back(make_pair(C, T - 1));
  }
  sort(v.begin(), v.end(), greater<pair<int, int> >());
  map<int, int> lank;
  
  lank[v[0].second] = 1;
  int l = 1;
  for (int i = 1; i < v.size(); i++) {
    //printf("%d,%d\n", v[i].second, v[i].first);
    for (;v[i].first == v[i - 1].first && i < v.size() ;i++) {
      lank[v[i].second] = l;
    }
    if (i < v.size()) {
      lank[v[i].second] = ++l;
    }
  }

  int N;
  while (scanf("%d ", &N) == 1) {
    printf("%d\n", lank[N - 1]);
  }
  return 0;
}