#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  int N, K;
  char c;
  string S;

  cin >> N >> S >> K;

  c = S[K - 1];

  for (int i = 0; i < N; i++)
  {
    if (S[i] != c)
    {
      S[i] = '*';
    }
  }

  cout << S << endl;

  return 0;
}