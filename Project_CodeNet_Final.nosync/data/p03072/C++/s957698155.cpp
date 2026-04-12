#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int H[N];
  for(int i = 0; i < N; i++) cin >> H[i];
  int counter = 0;
  int maxH = H[0];
  for(int i = 1; i < N; i++) {
    if(maxH <= H[i]) {
      counter++;
      maxH = H[i];
    }
  }
  cout << counter + 1 << endl;
}
