#include <iostream>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[]) {
  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      break;

    int score[100];
    for (int i = 0; i < n; i++)
      cin >> score[i];

    sort(score + 0, score + n);
    int sum = accumulate(score + 1, score + n - 1, 0);

    cout << sum / (n - 2) << endl;
    memset(score, 0, n);
  }
  return 0;
}