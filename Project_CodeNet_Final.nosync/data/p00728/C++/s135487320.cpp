#include <iostream>
#include <algorithm>
using namespace std;
int n;
int data[100];


int solve() {
  int avg;
  sort(data, data+n);
  avg = 0;
  for(int i = 1; i < n-1; ++i) {
    avg += data[i];
  }
  return avg / (n-2);
}

main() {
  while(( cin >> n ) && n) {
    for(int i = 0; i < n; ++i) {
      cin >> data[i];
    }
    cout << solve() << endl;
  }
}