#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int H = 0;
  int count = 0;
  for (int i=0; i<N;i++) {
    int height = 0;
    cin >> height;
    if (height >= H) {
      count++;
      H = height;
    }
  }
  cout << count << endl;
  return 0;
}
