#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define ENDL "\n"

typedef long long int llint;

int main()
{
  int N;
  string S;
  int K;
  cin >> N >> S >> K;
  K--;
  for (int i = 0; i < N; i++)
  {
    if (S[i] == S[K])
    {
      cout << S[i];
    }
    else
    {
      cout << "*";
    }
  }
  cout << ENDL;
  return 0;
}
