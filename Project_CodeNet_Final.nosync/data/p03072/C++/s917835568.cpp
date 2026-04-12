#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int res=1;
  int N;
  cin >> N;
  vector<int> mountain(N);

  for (int i = 0; N > i; ++i) cin >> mountain[i];

  for (int current_number = 1;N>current_number; ++current_number) {
    int i = 0;
    while (current_number>i) {
      if (mountain[i] > mountain[current_number]) break;
      ++i;
    }
    if (i == current_number) ++res;
  }
  cout << res << endl;
  return 0;
}