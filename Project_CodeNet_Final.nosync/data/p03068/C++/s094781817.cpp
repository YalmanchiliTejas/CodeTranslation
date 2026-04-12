#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

int main()
{
  int N, K;
  string S;
  cin >> N >> S >> K;
  char ch = S[K - 1];
  string T;
  for (int i = 0; i < N; ++i) {
    if (S[i] == ch) T += ch;
    else T += '*';
  }
  cout << T << endl;
  return 0;
}
