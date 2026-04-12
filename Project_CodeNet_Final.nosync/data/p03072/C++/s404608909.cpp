#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> mountains(N);
  for (int i = 0; i < N; i++) {
    cin >> mountains[i];
  }
  int count = 1;
  for (int i = 1; i < N; i++) {
    int flag = 0;
    for (int j = 0; j < i; j++) {
      if (mountains[j] > mountains[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      count++;
    }
  }
  cout << count << endl;
  
  return 0;
}
