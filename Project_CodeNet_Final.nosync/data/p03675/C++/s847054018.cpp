#include<iostream>
using namespace std;

int main() {
  int n, a[222222], b[222222], i;
  cin>>n;
  for(i=1; i <= n; ++i) cin >> a[i];
  int evens, odds;

  if(1&n) {
    evens = n/2+2;
    odds = n/2+1;
  }
  else {
    evens = n/2;
    odds = n/2+1;
  }

  for(i = 1; i <= n; ++i) {
    if(i&1) {
      b[odds] = a[i];
      if(1&n) odds--;
      else odds++;
    }
    else
    {
      b[evens] = a[i];
      if(1&n) evens++;
      else evens--;
    }
  }
  for(i = 1; i <= n; ++i) cout << b[i] << " ";
  return 0;
}
