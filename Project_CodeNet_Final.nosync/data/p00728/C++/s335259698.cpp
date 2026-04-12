#include <iostream>

using namespace std;

int main()
{
  int n;
  int max, min, score;
  int s;
  
  while (1) {
    cin >> n;
    if (n == 0) break;

    max = 0;
    min = 1000;
    score = 0;
    for (int i = 0; i < n; i++) {
      cin >> s;
      score += s;
      if (s > max) max = s;
      if (s < min) min = s;
    }
    cout << (score - max - min) / (n - 2) << endl;
  }
}

