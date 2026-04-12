#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
    a[i]/=10;
  }
  for(int k=0; k<2; k++) {
    int x=0;
    for(int i=0; i<n; i++) {
      if(x<i) {
        cout << "no" << endl;
        return 0;
      }
      x=max(x,i+a[i]);
    }
    reverse(a,a+n);
  }
  cout << "yes" << endl;
  return 0;
}
