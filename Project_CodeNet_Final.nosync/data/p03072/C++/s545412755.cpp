#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int height[N];
  for (int i=0; i<N; i++) {
    cin >> height[i];
  }
  int count = 1;
  bool flag = false;
  for (int j=1; j<N; j++) {
    for (int k=0; k<j; k++) {
      if (height[j] < height[k]) {
        flag = true;
        break;
      }
    }
    if (flag) {
      flag=false;
    } else {
      count += 1;
    }
  }
  cout << count << endl;
}