#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;

  int H[101];
  for (int i = 0; i < N; i++)
    cin >> H[i];

  int C = 1;
  for (int i = 1; i < N; i++) {
    bool canView = true;
    for (int j = 0; j < i; j++) {
      if (H[j] > H[i]) {
        canView = false;
        break;
      }
    }
    if (canView)
      C++;
  }

  cout << C << endl;

  return 0;
}