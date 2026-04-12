// http://koturn.hatenablog.com/entry/2016/02/04/050000#cpp
#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;
int main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N;
  cin >> N;

  int *H = nullptr;
  H = new int[N];
  for (int index = 0; index < N; index++)
  {
    cin >> H[index];
  }

  int count = 0;
  int highest = 0;
  for (int index = 0; index < N; index++)
  {
    if (H[index] < highest)
    {
      // pass
    }
    else
    {
      highest = H[index];
      count++;
    }
  }
  cout << count << endl;

  return EXIT_SUCCESS;
}
