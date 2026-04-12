#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,x=0,count=0; cin >> n;
  vector<int> h(n);
  for(int i=0;i<n;i++) {
    cin >> h[i];
    x=max(x,h[i]);
    if(x==h[i]) {
      count++;
    }
  }
  cout << count << endl;
}