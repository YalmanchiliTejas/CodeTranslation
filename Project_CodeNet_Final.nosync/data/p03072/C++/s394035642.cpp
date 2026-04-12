#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  
  int count = 1;
  int max_high = H[0];
  
  for (int i = 1; i < N; ++i) {
    if (H[i] >= max_high) {
      count++;
    }
    max_high = max(H[i], max_high);
  }
  
  cout << count << endl;
  
  return 0;
}