#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  multimap<int, int> paths;
  while (m--) {
    int first, second; cin >> first >> second;
    paths.insert(make_pair(first, second));
    paths.insert(make_pair(second, first));
  }
  
  vector<int> apexes(n);
  for (int i = 0; i < n; i++) apexes.at(i) = i + 1;
  
  int answer = 0;
  do {
    if (apexes.at(0) != 1) break;
    
    for (int i = 0; i < n - 1; i++) {
      auto range = paths.equal_range(apexes.at(i));
      
      bool valid = false;
      while (range.first != range.second) {
        if (apexes.at(i + 1) == range.first -> second) {
          valid = true;
          break;
        }
        range.first++;
      }
      
      if (!valid) break;
      if (i == n - 2) answer++;
    }
  } while (next_permutation(apexes.begin(), apexes.end()));
  
  cout << answer << endl;
}