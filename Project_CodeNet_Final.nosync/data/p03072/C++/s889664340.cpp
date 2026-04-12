#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int res=1;
  int N;
  cin >> N;
  vector<int> M(N);

  for (int i = 0; N > i; ++i) cin >> M[i];

  for (int c = 1;N>c; ++c) {
    int i = 0;
    while (c>i) {
      if (M[i] > M[c]) break;
      ++i;
    }
    if (i == c) ++res;
  }
  cout << res << endl;
  return 0;
}