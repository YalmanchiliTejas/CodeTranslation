#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n; scanf("%d", &n);
  vector<int> a(n);
#ifdef DEBUG
  for(int i = 0; i < n; i++) {
    a.push_back(i+1);
    reverse(a.begin(), a.end());
  }
  for(int i = 0; i < n; i++) {
    if(i > 0) cout << " ";
    cout << a[i];
  }
#endif
  for(int i = 0; i < n; i++) cin>>a[i];
  for(int i = n-1; i >= 0; i-=2) {
    if(i != n-1) cout << " ";
    cout << a[i];
  }
  for(int i = n%2; i < n; i += 2) {
    cout << " " << a[i];
  }
  cout << endl;

  return 0;


}
