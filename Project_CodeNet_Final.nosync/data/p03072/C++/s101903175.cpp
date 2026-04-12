#include <iostream>
using namespace std;

int main()
{
  int N, a = 0, b = 1;
  cin >> N;
  int H[N];
  for (int i = 0; i < N; i++)
    cin >> H[i];
  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (H[i] - H[j] < 0)
        a++;
    }
    if (a == 0)
      b++;
    a = 0;
  }
  cout << b << endl;
}