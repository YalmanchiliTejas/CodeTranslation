#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> h(n);
  int highest = 0;
  int count=0;
  for (size_t i = 0; i < n; i++) {
    cin>>h[i];
    if (h[i]>=highest) {
      highest=h[i];
      count++;
    }
  }
  cout<<count;
}