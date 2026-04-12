#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
  int N;

  cin >> N;

  int H=0;
  int count = 0;
  
  for (int ii=0; ii<N; ++ii) {
    int h;
    cin >> h;
    if (h >= H) {
      H = h;
      ++count;
    }
  }
  
  cout << count << endl;

  return 0;
}