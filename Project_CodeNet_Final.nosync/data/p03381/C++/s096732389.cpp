#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> x;
  vector<long long> y;
  for (int i = 0; i < n; i++) {
    long long k;
    scanf("%lld", &k);
    x.push_back(k);
    y.push_back(k);
  }
  sort(x.begin(), x.end());

  long long u = x[n/2 - 1] + x[n/2];
  for (int i = 0; i < n; i++){
    if (y[i] <= x[n/2 - 1]) {
      printf("%lld\n", x[n/2]);
    } else {
      printf("%lld\n", x[n/2-1]);
    }
  }
  return 0;
}