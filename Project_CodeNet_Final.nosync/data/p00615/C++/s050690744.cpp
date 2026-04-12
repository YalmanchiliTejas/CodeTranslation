#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  while(cin>>n>>m, n+m) {
    vector<int> a;
    a.push_back(0);
    for (int i=0; i<n; i++) {
      int tmp;
      cin >> tmp;
      a.push_back(tmp);
    }
    for (int i=0; i<m; i++) {
      int tmp;
      cin >> tmp;
      a.push_back(tmp);
    }
    int ans=0;
    sort(a.begin(), a.end());
    for(int i=1; i<a.size(); i++) {
      ans =max(ans, a[i]-a[i-1]);
    }
    cout << ans << endl;
  }
}