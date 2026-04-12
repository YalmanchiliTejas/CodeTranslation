#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint64_t N;
  cin >> N;

  cout << N * 800 - ((N / 15) * 200) << endl;

  return 0;
}
