#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;


int main() {
  int id, num;
  map<int,int> m;
  vector<int> v;
  while(1) {
    scanf("%d,%d", &id, &num);
    if(id|num) ; else break;
    m[id] = num;
    v.push_back(-num);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  while(scanf("%d", &id) != EOF) {
    cout << lower_bound(v.begin(), v.end(), -m[id]) - v.begin() + 1 << endl;
  }
  return 0;
}