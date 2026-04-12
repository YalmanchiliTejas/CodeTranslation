#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> s(n);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    s.at(a - 1).insert(b - 1);
    s.at(b - 1).insert(a - 1);
  }
  vector<int> v;
  for(int i = 1; i < n; i++){
    v.push_back(i);
  }
  
  sort(v.begin(), v.end());
  int count = 0;
  do {
    if (!s.at(0).count(v.at(0))) continue;
    bool flag = true;
    for (int i = 0; i < n - 2; i++) {
      if(!s.at(v.at(i)).count(v.at(i + 1))) {
        flag = false;
        break;
      }
    }
    if(flag) {
/*      cout << "1 ";
      for (int x : v) {
        cout << x + 1 << " ";
      }
      cout << endl;*/
      count++;
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << count << endl;
}