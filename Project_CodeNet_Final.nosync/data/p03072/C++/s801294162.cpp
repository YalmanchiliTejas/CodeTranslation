#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;

  int Mt_Max = 0;
  int count = 0;
  for (int i = 0; i < N; ++i)
  {
    int H;
    cin >> H;

    if (Mt_Max <= H)++count;
    if (Mt_Max < H) Mt_Max = H;
  }
  cout << count << endl;
}