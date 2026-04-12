#include <iostream>
using namespace std;

int main() {
  int N, i, c = 0;
  cin >> N;
  int H[N];
  for (i = 0; i < N; i++)
    cin >> H[i];
  
  for (i = 1; i <= N; i++) {
    int max = 0;
    for (int j = 1; j <= i; j++) {
      if (max < H[j - 1])
        max = H[j - 1];
    }
    if (max == H[i - 1])
      c++;
  }
  cout << c;
  return 0;
}