#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N;
  cin >> N;

  int cnt = 0;
  int mx = 0;
  rep(i, N)
  {
    int h;
    cin >> h;
    if (mx <= h)
    {
      cnt++;
      mx = h;
    }
  }

  cout << cnt << endl;

  return 0;
}
