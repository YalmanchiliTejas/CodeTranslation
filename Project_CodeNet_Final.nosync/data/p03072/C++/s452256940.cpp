#include<iostream>

using namespace std;


int main(void) {
  int n;
  cin >> n;
  int h[n];
  int max = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    if (h[i] >= max) {
      max = h[i];
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}