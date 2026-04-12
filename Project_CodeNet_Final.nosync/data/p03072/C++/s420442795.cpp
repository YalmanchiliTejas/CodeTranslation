#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, top;
  cin >> N >> top;
  
  int count = 1;
  for (int i = 1; i < N; ++i) {
    int H;
    cin >> H;
    if (top <= H) {
      count++;
      top = H;
    }
  }
  
  cout << count << endl;
}