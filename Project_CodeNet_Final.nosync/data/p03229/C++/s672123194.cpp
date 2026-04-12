#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  vector<long> vec;
  cin >> n;
  for (int i=0; i<n; i++) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  sort(vec.begin(), vec.end());
  long sum1=0, sum2=0;
  if (n%2==1) {
    for (int i=0; i<n/2-1; i++) {
      sum1 += 2*vec[n-i-1]-2*vec[i];
      sum2 += 2*vec[n-i-1]-2*vec[i];
    }
    sum1 += vec[n/2+1]+vec[n/2]-2*vec[n/2-1];
    sum2 += 2*vec[n/2+1]-vec[n/2]-vec[n/2-1];
  } else {
    for (int i=0; i<n/2-1; i++) {
      sum1 += 2*vec[n-i-1]-2*vec[i];
    }
    sum1 += vec[n/2] - vec[n/2-1];
  }
  if (sum1>sum2) cout << sum1 << endl;
  else cout << sum2 << endl;

  return 0;
}
