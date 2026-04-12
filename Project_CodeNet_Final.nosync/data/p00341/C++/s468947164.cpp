#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main() {
  vector<int> v(12);
  for(int i=0; i<12; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  set<int> S[3];
  for(int i=0; i<12; i++) {
    S[i/4].insert(v[i]);
  }

  bool ok = true;
  for(int i=0; i<3; i++) {
    ok &= (S[i].size() == 1);
  }
  if(ok) cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}

