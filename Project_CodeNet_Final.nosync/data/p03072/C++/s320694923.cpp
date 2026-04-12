#include<iostream>
using namespace std;
int main () {
  int N;
  cin >> N;
  int h[100];
  for (int i = 0; i < N; i ++) cin >> h[i];
  int ma = h[0];
  int ans = 1;
  for (int i = 1; i < N; i ++) {
    if (h[i] >= ma) {
      ma = h[i];
      ans ++;
    }
  }
  cout << ans << endl;
}
