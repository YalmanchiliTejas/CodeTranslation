#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int i, n, sum, p[1001];
  while(1) {
    sum = 0;
    cin >> n;
    if(n==0) break;
    for(i=0; i<n; i++) {
      cin >> p[i];
      sum += p[i];
    }
    sort(p, p+n);
    sum -= p[0] + p[n-1];
    sum /= n-2;
    cout << sum << endl;
  }
  return 0;
}
