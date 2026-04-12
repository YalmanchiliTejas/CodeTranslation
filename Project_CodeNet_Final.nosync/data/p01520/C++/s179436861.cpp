#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int n, t, e;
  cin >> n >> t >> e;
  for (int i = 0; i < n; i++) {
    int x, sum;
    cin >> x;
    sum = x;
    while (true) {
      if (t-e <= sum && sum <= t+e) {
        cout << i+1 << endl;
        return 0;
      } else if (t+e < sum) {
        break;
      } else {
        sum += x;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}