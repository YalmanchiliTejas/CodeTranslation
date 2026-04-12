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
    // i番目の山が見れるのか．
    while (true) {
      if (i == current_number) {
        ++res;
        break;
      }
      if (mountain[i] > mountain[current_number]) break;
      ++i;
    }
  }

  cout << res << endl;
  return 0;
}