#include<bits/stdc++.h>
#define int64 long long int
using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  
  vector<int> xx(x);
  sort(xx.begin(), xx.end());
  
  int m = xx[n/2];
  for (int i = 0; i < n; i++) {
    if(x[i]<m){
      cout << m << endl;
    } else {
      cout << xx[n/2-1] << endl;
    }
  }
    
  return 0;
}
