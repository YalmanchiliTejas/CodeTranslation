#include<bits/stdc++.h>
using namespace std;

#define INFTY (1 << 30);
typedef long long ll;

int main(void) {
  int N;
  vector<int> H;
  cin >> N;
  int H_input;
  for (int i = 0; i < N; i++) {
    cin >> H_input;
    H.push_back(H_input);
  }
  int counter = 1;
  reverse(H.begin(), H.end());
  bool possible = true;
  for (int i = 0; i < N - 1; i++) {
    possible = true;
    for (int j = i+1; j < N; j++) {
      if (H[i] >= H[j]) {
      } else {
        possible = false;
        break;
      }
    }
    if (possible == true) {
      counter++;
    }
  }

  cout << counter << endl;

  
  return 0;
}
