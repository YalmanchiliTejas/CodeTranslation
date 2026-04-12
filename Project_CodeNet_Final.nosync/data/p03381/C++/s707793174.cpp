#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>

using namespace std;
const long long P = 1000000007;

int main() {
  long long n;
  cin >> n;
  vector<long long> x(n,0),a(n);
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }
  a = x;
  sort(a.begin(),a.end());
  int mid = n/2;
  for(int i = 0; i < n; i++) {
    if(x[i] <= a[mid-1]) {
      cout << a[mid] << endl;
    }else {
      cout << a[mid-1] << endl;
    }
  }
  return 0;
}