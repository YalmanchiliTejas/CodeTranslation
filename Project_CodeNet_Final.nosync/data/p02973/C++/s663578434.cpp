
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

int vs[100000+10];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &vs[i]);
  }
  multiset<int> ss;
  for(int i = n-1; i >= 0; --i) {
    auto it = ss.upper_bound(vs[i]);
    if(it == ss.end()) {
      ss.insert(vs[i]);
    } else {
      ss.erase(it);
      ss.insert(vs[i]);
    }
  }
  cout << ss.size() << endl;
  
  return 0;
}
